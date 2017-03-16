#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream inputFile("B-small-attempt0.in");
    ofstream outputFile("googleCodeJamOUTPUT.txt");
    int numExamples;
    inputFile >> numExamples;
    for(int i = 0; i < numExamples; i++){
        int x,y;
        inputFile >> x;
        inputFile >> y;
        string output = "";
        if(x > 0){
            for(int j = 0; j < x; j++) output += "WE";
        } else{
            for(int j = 0; j < -x; j++) output += "EW";
        }
        
        if(y > 0){
            for(int j = 0; j < y; j++) output += "SN";
        } else{
            for(int j = 0; j < -y; j++) output += "NS";
        }
        outputFile << "Case #" << (i+1) << ": " << output << endl;
    }
}

