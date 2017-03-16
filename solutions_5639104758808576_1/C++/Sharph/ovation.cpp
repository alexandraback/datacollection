#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	
	int T;
	cin >> T;
	
	for(int t = 0; t < T; ++t) {
		int Smax;
		cin >> Smax;
		string x;
		cin >> x;
		vector<int> y(Smax + 1);
		for(int i = 0; i <= Smax; ++i) {
			y[i] = x[i] - '0';
		}
		
		int s = 0;
		int clap = 0;
		for(int i = 0; i <= Smax; ++i) {
			if(i == clap + 1) {
				++s;
				++clap;
			}
			clap += y[i];
		}
		
		cout << "Case #" << t + 1 << ": " << s << "\n";
	}
	
	return 0;
}
