#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
	int T, smax, sum, casenum, friends;
	string input;

	cin >> T;
	for (int i = 0; i < T ; i++){

		cin >> smax;
		cin >> input;
		sum = 0; 
		friends = 0;
		for (int j = 0; j <= smax; j++){
			if (sum < j){
				friends++;
				sum++;
				if (sum >= j){
					sum+= input[j]-'0';
				}
			} else {
				sum+= input[j]-'0';
			}
		}
		cout << "Case #" << i + 1 << ": " << friends << endl;
		//cout << smax << " " << input << endl;
		
	}

	return 0;
}

