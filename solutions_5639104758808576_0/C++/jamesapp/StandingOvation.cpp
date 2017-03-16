#include <iostream>
#include <string>
using namespace std;

int main(){
	cin.sync_with_stdio(false);
	
	int Tests;
	cin >> Tests;

	int smax;
	string digits;

	for (int t = 1; t <= Tests; t++){
		cin >> smax >> digits;
		int invites = 0;
		int standing = 0;
		for (int i = 0; i <= smax; i++){
			int digit = digits.at(i) - '0';
			if (standing < i){
				invites += (i - standing);
				standing = i;
			}
			standing += digit;
		}
		cout << "Case #" << t << ": " << invites << endl;
	}
	
	return 0;
}
