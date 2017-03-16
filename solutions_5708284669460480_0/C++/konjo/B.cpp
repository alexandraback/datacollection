#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++) {
		double prob[120] = {0};
		int nex[120][30] = {0};
		double expect = 0;
		double letters[30] = {0};
		int K, L, S;
		string keyboard, target;
		cin >> K >> L >> S;
		cin >> keyboard >> target;

		for(int i = 0; i < keyboard.size(); i++)
			letters[keyboard[i] - 'A'] += 1;
		for(int i = 0; i < 30; i++)
			letters[i] /= (double)(keyboard.size());

		for(int i = 0; i < target.size()+1; i++) {
			string str(target.begin(), target.begin() + i);
			for(int j = 0; j < 26; j++) {
				string added;
				added = str + (char)('A'+ j);

				nex[i][j] = 0;
				for(int k = 0; k < added.size()+1; k++) {
					if(target.find(string(added.begin()+k, added.end())) == 0) {
						nex[i][j] = added.size() - k;
						break;
					}
				}
			}
		}

		/*
		for(int i = 0; i < 10; i++)  {
			for(int j = 0; j < 30; j++) {
				cout << nex[i][j] << " ";
			}
			cout << endl;
		}
		// */

		prob[0] = 1.0;
		for(int i = 0; i < S; i++) {
			/*
			for(int i = 0; i < target.size() + 2; i++)
				cout << prob[i] << " ";
			cout << endl;
			// */
			double nex_prob[120] = {0};
			for(int j = 0; j < target.size()+1; j++) {
				for(int k = 0; k < 26; k++) {
					nex_prob[nex[j][k]] += prob[j] * letters[k];
				}
			}
			for(int j = 0; j < target.size()+1; j++) {
				prob[j] = nex_prob[j];
			}
//			cout << nex_prob[target.size()] << endl;
			expect += nex_prob[target.size()];
		}

		//cout << "Case #" << t + 1 << ": " << expect << endl;
		
		bool flgs[30] = {0};
		bool canmk = false;
		int bring = 0;
		for(int i = 0; i < target.size(); i++) {
			flgs[target[i] - 'A'] = true;
		}
		for(int i = 0; i < keyboard.size(); i++) {
			flgs[keyboard[i] - 'A'] = false;
		}
		for(int i = 0; i < 30; i++) {
			canmk |= flgs[i];
		}
		if(canmk || target.size() > S) {
			bring = 0;
		}
		else {
			int a, b;
			a = b = target.size();
			for(int i = 1; i < target.size(); i++) {
				if(target.find(string(target.begin() + i, target.end())) == 0) {
					b = i;
					break;
				}
			}
//			cout << a << " " << b << endl;
			bring = (S-a) / b + 1;
		}
		
//		cout << bring << " " << expect << endl;
		printf("Case #%d: %.10f\n", t+1, bring - expect);
	}
}
