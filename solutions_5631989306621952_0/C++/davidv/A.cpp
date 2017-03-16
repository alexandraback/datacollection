#include <bits/stdc++.h>

using namespace std;

void doCase(int t) {
	string S;
	cin >> S;
	
	string res = "";
	
	for (int i=0; i<S.size(); i++) {
		if (S[i]+res > res+S[i]) res = S[i]+res;
		else res = res+S[i];
	}
	
	cout << "Case #" << t << ": " << res << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i=0; i<t; i++) doCase(i+1);
	return 0;
}
