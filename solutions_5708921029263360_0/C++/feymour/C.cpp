#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0;t<T;++t) {
		int J,P,S,K;
		cin >> J >> P >> S >> K;
		int jp[10][10];
		int js[10][10];
		int ps[10][10];
		for (int i=0;i<10;++i) {
			for (int j=0;j<10;++j) {
				jp[i][j] = 0;
				js[i][j] = 0;
				ps[i][j] = 0;
			}
		}
		vector<string> results;
		for (int j=0;j<J;++j) {
			for (int p=0;p<P;++p) {
				for (int s=0;s<S;++s) {
					if (jp[j][p]<K && js[j][s]<K && ps[p][s]<K) {
						jp[j][p]++;
						js[j][s]++; 
						ps[p][s]++;
						string tmp;
						tmp += (char)('0'+j+1);
						tmp += " ";
						tmp += (char)('0'+p+1);
						tmp += " ";
						tmp += (char)('0'+s+1);
						results.push_back(tmp);
					}
				}
			}
		}

		cout << "Case #" << t+1 << ": " << results.size() << endl;
		for (int i=0;i<results.size();++i) {
			cout << results[i] << endl;
		}
	}
	return 0;
}
