#include <iostream>

using namespace std;

int t, m;
string s;

int main() {
	cin >> t;
	for (int i=1;i<=t;i++) {
		cin >> m >> s;
		int a = 0;
		int k = 0;
		for (int j=0;j<=m;j++) {
			if (k+a < j) a++;
			k+=s[j]-'0';
		}
		cout << "Case #" << i << ": " << a << "\n";
	}
}
