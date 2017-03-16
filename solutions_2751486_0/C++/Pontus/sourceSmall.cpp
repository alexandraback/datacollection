#include <iostream>
#include <fstream>
using namespace std;

long nValue(string name, int n){
    int* nameInt = new int[name.length()];
    for(int i = 0; i < name.length(); i++){
        if(name[i] == 'a' || name[i] == 'o' || name[i] == 'u' || name[i] == 'e' || name[i] == 'i'){
            nameInt[i] = 0;
        } else{
            nameInt[i] = 1;
        }
    }
    long count = 0;
    int startIndex = 0;
    for(int i = 0; i < name.length(); i++){
        if(nameInt[i] == 1){
            //check if there are n in a row
            int checkSum = 0;
            for(int j = 0; j < n; j++) checkSum += nameInt[i+j];
            if(checkSum == n){
                count += (i-startIndex+1)*(name.length() - i - n + 1);
                startIndex = i + 1;
            }
        }
    }
    return count;
}

int main(){
    ifstream inputFile("A-small-attempt1.in");
    ofstream outputFile("googleCodeJamOUTPUT.txt");
    
    int numExamples;
    inputFile >> numExamples;
    for(int i = 0; i < numExamples; i++){
        string name;
        int n;
        inputFile >> name;
        inputFile >> n;
        outputFile << "Case #" << (i+1) << ": " << nValue(name,n) << endl;
    }
}

