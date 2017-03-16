#include <iostream>
#include <string>
using namespace std;

int main(){
	int t;
	cin >> t;

	//for each case
	for (int i = 1; i <= t; ++i){
		cout << "Case #" << i << ": ";
		string pancakes;
		cin >> pancakes;

		int currentPancake = 0;
		char currentSide = pancakes[currentPancake];
		++currentPancake;		//next pancake
		int sz = pancakes.length();
		unsigned long long numFlips = 0;

		//while haven't made entire stack uniform
		while (currentPancake < sz){

			//see if next pancake is the same
			if (pancakes[currentPancake] != currentSide){
				
				//flip if not
				numFlips++;
				string copy = pancakes;
				for (int i = 0; i < currentPancake; ++i){
					pancakes[i] = (copy[currentPancake - 1 - i] == '+' ? '-' : '+');
				}
				currentSide = (currentSide == '+' ? '-' : '+');
			}
			++currentPancake;
		}

		//our stack may be wrong side up
		if (currentSide == '-'){
			++numFlips;
		}

		cout << numFlips << endl;
	}//end testcases

	return 0;
}
