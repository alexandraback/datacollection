#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

std::string ReadString;
std::ofstream OutputFile;
std::ifstream InputFile;
std::stringstream StringStream;

int main() {
	//Opens the file and creates an input file
	OutputFile = std::ofstream( "smallOutput.out" );
	InputFile = std::ifstream( "A-small-attempt0.in" );

	getline( InputFile, ReadString );
	StringStream.clear();
	StringStream.str( ReadString );
	int numOfCases;
	StringStream >> numOfCases;
	std::cout << numOfCases << "\n";

	for( int i = 0; i < numOfCases; i++ ) {
		getline( InputFile, ReadString );
		StringStream.clear();
		StringStream.str( ReadString );
		long long int radius, amountOfPaint;
		StringStream >> radius;
		StringStream >> amountOfPaint;

		long long int numOfCircles = 0;
		long long int lastCircleRadius;
		do {
			lastCircleRadius = radius * radius;
			radius++;
			amountOfPaint -= radius * radius;
			amountOfPaint += lastCircleRadius;
			numOfCircles++;
			radius++;
		} while( amountOfPaint >= 0 );
		numOfCircles--;
		OutputFile << "Case #" << (i+1) << ": " << numOfCircles << std::endl;
	}

	OutputFile.close();
	InputFile.close();

	//while( true ) {}
	return 0;
}