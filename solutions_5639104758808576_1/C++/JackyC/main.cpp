#include <iostream>

using namespace std;

void solve(int nCase) {
	int max;
	string str; 

	cin >> max >> str;
	
	int ans = 0, up = 0; 
	for (int i=0; i<max+1; i++) {
		if (str[i]-'0' == 0) continue;
		if (up<i) {
			ans += i-up;
			up = i+str[i]-'0';
		} else {
			up += str[i]-'0';
		}
	}

	cout << "Case #" << nCase+1 << ": " << ans << endl;
}

int main() {
	int nCase = 0;
	cin >> nCase;

	for (int i=0; i<nCase; i++) {
		solve(i);
	}
}
