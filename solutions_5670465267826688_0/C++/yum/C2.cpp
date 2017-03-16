#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<int(b); i++)
typedef long long LL;

int data[8][8], neg[8]={4,5,6,7,0,1,2,3}, tf[4]; // total product

int main() {
	data[0][0] = 0;
	data[0][1] = 1;
	data[0][2] = 2;
	data[0][3] = 3;
	data[1][0] = 0;
	data[1][1] = 4;
	data[1][2] = 3;
	data[1][3] = 6;
	data[2][0] = 2;
	data[2][1] = 7;
	data[2][2] = 4;
	data[2][3] = 1;
	data[3][0] = 3;
	data[3][1] = 2;
	data[3][2] = 5;
	data[3][3] = 4;
	FOR(i,0,4) FOR(j,4,8) data[i][j] = neg[data[i][neg[j]]];
	FOR(i,4,8) FOR(j,0,4) data[i][j] = neg[data[neg[i]][j]];
	FOR(i,4,8) FOR(j,4,8) data[i][j] = data[neg[i]][neg[j]];
	int TC, L;
	LL X;
	string s;
	cin >> TC;
	FOR(tc,1,TC+1) {
		cin >> L >> X >> s;
		string sx;
		FOR(x,0,X) sx += s;
		int cum = 0, st = 1;
		for (char c : sx) {
			cum = data[cum][c-'i'+1];
			if (st <= 2 && cum == st) {
				st++;
				cum = 0;
			}
		}
		string ans = (st == 3 && cum == st) ? "YES" : "NO";
		cout << "Case #" << tc << ": " << ans << endl;
	}
}
