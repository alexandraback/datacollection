#include <fstream>
#include <map>
#include <string>
#include <iostream>
using namespace std;


int main(){
	ifstream inf("B-small-attempt0.in");
	ofstream outf("B-small-attempt0.out");
	int T, K, L, S;
	inf >> T;
	for (int i = 1; i <= T; i++){
		inf >> K >> L >> S;
		string key, targ;
		inf >> key >> targ;
		map<char, int> keyboard;
		for (int j = 0; j < key.length(); j++){
			if (keyboard.find(key[j]) != keyboard.end()){
				keyboard[key[j]]++;
			}
			else
				keyboard[key[j]] = 1;
		}
		double expect = 1;
		for (int j = 0; j < targ.length(); j++){
			if (keyboard.find(targ[j]) != keyboard.end()){
				expect *= keyboard[targ[j]];
				expect /= K;
			}
			else{
				expect = 0;
				break;
			}
		}
		if (L > S)
			expect = 0;
		else
			expect = expect * (S - L + 1);

		int start = 1;
		for (start = 1; start <L; start++){
			if (targ.substr(start) == targ.substr(0, L - start)){
				break;
			}
		}
		double max = 0;
		if (expect == 0)
			max = 0;
		else{
			max = 1 + (S - L) / start;
		}
		outf.precision(10);
		outf << "Case #" << i << ": " << max - expect << endl;
		cout << i;
	}


	return 0;
}