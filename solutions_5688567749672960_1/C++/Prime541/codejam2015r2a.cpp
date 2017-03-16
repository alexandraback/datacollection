#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
	int kT = 0;
	cin >> kT;
	cerr << "Nb of tests: " << kT << endl;
	for (int t = 0 ; t < kT ; ++t) {
		string kN;
		cin >> kN;
		
		string n; n.reserve(15); n = "1";
		
		int count = 1;
				
		while (n != kN) {
			//cerr << "kN: " << kN << endl;
			int s = kN.size();
			bool aIsReversable = true;
			bool aDoReverse = false;
			if (kN[s - 1] == '0') {
				//cerr << "Path 1" << endl;
				// do not reverse
				aIsReversable = false;
			} else /*if (kN[s - 1] == '1' && kN[0] != '1')*/ {
				bool aIsSym = true;
				for (int i = 0 ; i < s / 2 ; ++i) {
					if (kN[i] != kN[s - 1 - i]) {
						aIsSym = false;
						break;
					}
				}
				aIsReversable = !aIsSym;
				
				aDoReverse = (kN[s - 1] == '1');
				for (int i = s / 2 ; i < s - 1 ; ++i) {
					if (kN[i] != '0') {
						aDoReverse = false;
						break;
					}
				}
			}
			
			if (aIsReversable && aDoReverse) {
			    //cerr << "Path 2a" << endl;
				kN.assign(kN.rbegin(), kN.rend());
				//cerr << " -> " << kN << endl;
				++count;
			} else {
			    //cerr << "Path 2b" << endl;
				// do not reverse
				if (kN[s - 1] != '0') {
					kN[s - 1] -= 1;
				} else {
					int i = s;
					while (i > 0 && kN[i - 1] == '0') {
						kN[i - 1] = '9';
						--i;
					}
					kN[i - 1] -= 1;
		    	}
				for (int i = 0 ; i < s && kN[0] == '0' ; ++i) {
					kN = kN.c_str() + 1;
				}
				++count;
			}
			
		}
		cout << "Case #" << (t + 1) << ": " << count << endl;
		cerr << "Case #" << (t + 1) << ": " << count << endl;
	}
}
