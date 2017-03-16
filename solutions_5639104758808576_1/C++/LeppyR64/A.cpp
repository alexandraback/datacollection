#include <iostream>
#include <algorithm>
using namespace std;

int Smax;
string S;
	
int main() {
	int T; 
	cin >> T;
	for(int Z = 1; Z <= T; Z++) {
		
		cin >> Smax >> S;
		int invited = 0, standing = S[0] - '0';
		for(int i = 1; i <= Smax; i++) {
			if(standing < i) {
				invited += i - standing;
				standing = i;
			}
			standing += S[i] - '0';
		}
		cout << "Case #" << Z << ": " << invited << endl;
	}
}