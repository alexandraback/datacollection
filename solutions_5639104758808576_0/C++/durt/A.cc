#include <iostream>
using namespace std;

int Smax;
int count[1001], psum[1001];

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		string s;
		cin >> Smax >> s;
		for (int i = 0; i <= Smax; i++)
			count[i] = s[i] - '0';
		psum[0] = 0;
		for (int i = 1; i <= Smax; i++)
			psum[i] = psum[i-1] + count[i-1];
		
		int res = 0;
		for (int i = 1; i <= Smax; i++) {
			if (count[i] != 0) {
				res = max(res, i - psum[i]);
			}
		}
		
		cout << "Case #" << icase << ": " << res << endl; 
	}
	return 0;
}
