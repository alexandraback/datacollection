#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>

std::string ReadString;
std::ofstream OutputFile;
std::ifstream InputFile;
std::stringstream StringStream;

int main() {
	//Opens the file and creates an input file
	OutputFile = std::ofstream( "smallOutput.out" );
	InputFile = std::ifstream( "B-small-attempt1.in" );

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
		int maxEnergy, currentEnergy, energyRegain, numOfActivities;
		long long unsigned int maxValue;
		StringStream >> maxEnergy;
		currentEnergy = maxEnergy;
		StringStream >> energyRegain;
		StringStream >> numOfActivities;
		maxValue = 0;

		std::vector<int> multipliers;
		getline( InputFile, ReadString );
		StringStream.clear();
		StringStream.str( ReadString );
		for( int j = 0; j < numOfActivities; j++ ) {
			int temp;
			StringStream >> temp;
			multipliers.push_back(temp);
		}

		int regainEnergy;
		int nextID;
		int energyToSpend;
		bool searching;
		for( int j = 0;  j < numOfActivities; j++ ) {
			regainEnergy = energyRegain;
			nextID = j+1;
			energyToSpend = 0;
			searching = true;
			while( nextID != numOfActivities && regainEnergy < maxEnergy && searching ) {
				if( multipliers[nextID] < multipliers[j] ) {
					regainEnergy += energyRegain;
					nextID++;
				} else {
					searching = false;
				}
			}

			if( nextID == numOfActivities || regainEnergy >= maxEnergy ) {
				energyToSpend = currentEnergy;
			} else {
				energyToSpend = ( regainEnergy + currentEnergy ) - maxEnergy;
				if( energyToSpend < 0 ) { energyToSpend = 0; }
			}

			maxValue += energyToSpend * multipliers[j];
			currentEnergy -= energyToSpend;
			currentEnergy += energyRegain;
		}

		std::cout << (i+1) << std::endl;
		OutputFile << "Case #" << (i+1) << ": " << maxValue << std::endl;
	}

	OutputFile.close();
	InputFile.close();

	//while( true ) {}
	return 0;
}