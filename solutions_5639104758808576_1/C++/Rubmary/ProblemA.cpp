#include <iostream>
using namespace std;


int main () {
	int T;
	int Smax;
	string shyness;
	cin >> T;
	int peopleStanding;
	int friends;
	
	for (int k=1; k<=T; k++) {
		cin >> Smax;
		cin.get();
		getline(cin, shyness);
		
		peopleStanding = shyness[0]-48; 
		friends=0;
		for (int i=1; i<=Smax; i++) {
			if (peopleStanding<i) {
				friends+=i-peopleStanding;
				peopleStanding=i;
			}
			
			peopleStanding+=shyness[i]-48;
		}
		
		cout << "Case #" << k << ": " << friends << endl;
	}
	
	return 0;
}
