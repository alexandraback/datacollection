#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, m;
	cin >> t;
	for (m = 0; m < t ; m++){
		char s[1001];
		cin >> s;
		string sout;
		sout += s[0];
		int i;
		for (i = 1; i < strlen(s); i++){
			if (sout[0] <= s[i])
				sout.insert(0,1,s[i]);
			else
				sout += s[i];
		}
		cout << "Case #" << m+1 << ": ";
		cout << sout << endl;
	}
	return 0;
}