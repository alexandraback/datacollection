#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream myfile("A-small-attempt0.txt");
	ifstream target("A-small-attempt0.in");
	int T;
	target >> T;
	string S;
	for (int i = 0; i < T; i++) {
		target >> S;
		string result;
		int len = S.length();
		int prev = int(S[0]);
		if (len == 1){
			myfile << "Case #" << i + 1 << ": " << S << endl;
			continue;
		}
		for (int j = 0; j < len; j++) {
			int temp = int(S[j]);
			if (temp < prev)
				result = result + S[j];
			else {
				result = S[j] + result;
				prev = temp;
			}
		}
		myfile << "Case #" << i + 1 << ": " << result << endl;
	}
	return 0;
}
