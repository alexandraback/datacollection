//============================================================================
// Name        : SpeakingInTongues.cpp
// Author      : Patrick Lewis
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

char translategeGoogleSpeakChar(char input);

int translateKey[] = {24,6,2,15,10,-3,15,16,-5,11,-2,-5,-1,-12,-4,2,9,2,-5,3,-11,-6,-17,-11,-24,-9};

int main() {

	ofstream outputFile;
	ifstream inputFile;
	outputFile.open("output.txt");
	inputFile.open("input.txt");

	char* inputBuff = new char[1024];
	char* outputBuff = new char[1024];

	//check input file
	if(inputFile.is_open() == false) {
		cout << "Unable to open input.txt";
		return -1;
	}

	inputFile.getline(inputBuff,1023);

	int numCases = atoi(inputBuff);

	for( int i = 1; i <= numCases; i++) {
		inputFile.getline(inputBuff,1023);

		int index = 0;
		while(inputBuff[index] != NULL && index < 1023){
			outputBuff[index] = translategeGoogleSpeakChar(inputBuff[index]);
			index++;
		}
		outputBuff[index] = NULL;

		outputFile << "Case #" << i << ": " << outputBuff << endl;
	}

	inputFile.close();
	outputFile.flush();
	outputFile.close();

	return 0;
}


char translategeGoogleSpeakChar(char input){

	return input + translateKey[input-'a'];
}
