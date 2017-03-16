#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <stack>

using namespace std;

string s;
int a[50];
int b[50];
void parse() {
	cin >> s;
}

void solve() {
	memset(a, 0 , sizeof(a));
	memset(b, 0 , sizeof(b));
	int len = s.length();
	for (int i =0; i < len; i++){
		a[s[i]-'A'] ++;
	}


	b[0] = a['Z'-'A'];
	b[6] = a['X'-'A'];
	b[7] = a['S'-'A']-b[6];
	b[5] = a['V'-'A']-b[7];
	
	b[2] = a['W'-'A'];
	b[4] = a['F'-'A']- b[5];
	b[1] = a['O'-'A']-b[2]-b[4]-b[0];
	b[3] = a['R'-'A']-b[0]-b[4];

	b[9] = (a['N'-'A']-b[1]-b[7])/2;
	b[8] = a['T'-'A']-b[2]-b[3];

	for (int i = 0; i <= 9; i++)
		for (int j = 0; j < b[i]; j++)
			cout << i;
	cout << endl;


}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++){
		//cout << "OK " << endl;
		parse();

		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}



