#include <iostream>
#include <fstream>
using namespace std;


int main() {
	ofstream myfile("C-small-attempt4.txt");
	ifstream target("C-small-attempt4.in");
	int T;
	target >> T;
	string numToChar[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
	for (int i = 1; i <= T; i++) {
		int J, P, S, K;
		target >> J >> P >> S >> K;
		int total = J * P * S;
		int setA = J * P;
		string combinations[total];
		int k = 0;
		int j = 0, p = 0, s = 0;
		int targetFind = K;
		while (k < total) {
			combinations[k] = numToChar[j] + ' ' + numToChar[p] + ' ' + numToChar[s];
			s += 1;
			if (s == S) {
				s = 0;
				p += 1;
				if (p == P) {
					p = 0;
					j += 1;
				}
			}
			k += 1;
		}
		if (K >= S) {
			myfile << "Case #" << i << ": " << total << endl;
			for (k = 0; k < total; k++) {
				myfile << combinations[k] << endl;
			}
		} else if (K < S) {
			int output = setA * K;
			myfile << "Case #" << i << ": " << output << endl;
			int called = 0;
			int offset = 0;
			int sets = 1;
			int prevOffset = 0;
			while (called < output) {
				int index = (sets - 1) * S + offset;
			//	cout << index << endl << total << endl;
				myfile << combinations[index] << endl;

				targetFind = targetFind - 1;
				offset += 1;
				offset = offset % S;
				if (targetFind == 0) {
					sets += 1;
					if ((sets - 1) % P == 0) {
						offset = prevOffset + 1;
						offset = offset % S;
						prevOffset = offset;
					}
					targetFind = K;
				}
				called += 1;
			}
		}
//		myfile << "Case #" << i << ": " << << endl;
		
	}
	return 0;
}
