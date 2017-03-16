#include <iostream>
#include<fstream>
#include <string>
using namespace std;



int main() 
{
	ifstream cin;
	cin.open("A-small-attempt0.in");

	ofstream cout;
	cout.open("standing_ovation_sevag.out");


	int Smax;
	int nbStanding;
	int nbAdded;
	int T;
	string audience;

	cin>>T; 

	for (int t=1; t<=T; t++) 
	{
		nbStanding = 0;
		nbAdded = 0;

		cin>>Smax;
		cin>>audience;
		
		for (int level=0; level<=Smax; level++) {
			int nbInLevel = audience[level] - '0';
			if (nbStanding < level) {
				int nbToAdd = level - nbStanding;
				nbStanding += nbToAdd;
				nbAdded += nbToAdd;
			}
			nbStanding += nbInLevel;
		}

		cout << "Case #" << t <<": "<<nbAdded<<endl;
	}

	return 0;
}