#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_INPUTED_STRING 1000000
#define SIZE_OF_ALPHABET 25

void findPositionOfLetters(int* counterTemporary, int* countOfLetters, int size, int* indexArray);
void getLetterCounter(char* inputedArray, int size, int* counterTemporary, int* countOfLetters);
void displayResult(int* countOfLetters, int* indexArray, int size);
void sortingCounterOfLetters(int* countOfLetters, int size);
char* getString();

int main() {
    
    int counterTemporary[26] = {0};
    int countOfLetters[26] = {0};
    int indexArray[26] = {0};
    int strLen;
    
    char* inputedString = getString();
    strLen = strlen(inputedString);
    
    getLetterCounter(inputedString, strLen, countOfLetters, counterTemporary);
    sortingCounterOfLetters(countOfLetters, SIZE_OF_ALPHABET);
    findPositionOfLetters(counterTemporary, countOfLetters, SIZE_OF_ALPHABET, indexArray);
    displayResult(countOfLetters, indexArray, SIZE_OF_ALPHABET);
    free(inputedString);
    return 0;
}

char* getString(){
    char* enteredStr;
    enteredStr = (char*) malloc(SIZE_OF_INPUTED_STRING * sizeof(char));
    
    printf("Pls enter a string. We will calculate an amount of each letter:\n");
    gets(enteredStr);
    fpurge(stdin);
    
    //handle case whan user do not type anything
    if (enteredStr[0] == 0){
        printf("Error! Empty string\n");
    }
    return enteredStr;
}

void getLetterCounter(char* inputedArray, int size, int* counterTemporary, int* countOfLetters){
    
    for (int i = 0; i < size; i++){
        //Considering characters from 'A' to 'Z' only and ignoring others
        if (inputedArray[i] >= 'A' && inputedArray[i] <='Z') {
            countOfLetters[inputedArray[i]-'A']++;
            counterTemporary[inputedArray[i]-'A']++;
        }
        //Considering characters from 'a' to 'z' only and ignoring others
        if  (inputedArray[i] >= 'a' && inputedArray[i] <= 'z'){
            countOfLetters[inputedArray[i]-'a']++;
            counterTemporary[inputedArray[i]-'a']++;
        }
    }
}

void sortingCounterOfLetters (int* countOfLetters, int size){
    
    for(int i=0; i < size; i++){
        for(int j=i+1; j < size; j++){
            if(countOfLetters[i] < countOfLetters[j]){
                int temp = countOfLetters[i];
                countOfLetters[i] = countOfLetters[j];
                countOfLetters[j] = temp;
            }
        }
    }
}


void findPositionOfLetters(int* counterTemporary, int* countOfLetters, int size, int* indexArray){
    int position = 0;
    for (int c = 0; c < size; c++){
        if (countOfLetters[c] != 0) {
            for (int i = 0; i < size; i++) {
                if (counterTemporary[i] == countOfLetters[c]) {
                    indexArray[position] = i;
                    counterTemporary[i] = 0;
                    position++;
                }
            }
        }
    }
}


void displayResult(int* countOfLetters, int* indexArray, int size){
    int j = 0;
    for (int i = 0; i < SIZE_OF_ALPHABET; i++){
        if (countOfLetters[i] != 0) {
            printf("%c occurs %d times in the entered string.\n", indexArray[j]+'A',countOfLetters[i]);
            j++;
        }
    }
}

