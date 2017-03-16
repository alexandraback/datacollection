#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;

string s[100];
string s2[1000000];

int v[10][10];
int a[10];
int sta[10];

void solve(int tc) {
	int m, n;
	string out="ZZZZ";
	memset(v,0,sizeof(v));
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> s[i];
	for (int i=1; i<=m; i++) {
		int x, y;
		cin >> x >> y;
		v[x][y] = v[y][x] = 1;
	}
	
	for (int i=0; i<n; i++) a[i] = i+1;
	
	do {
		int p=0;
		sta[p++] = a[0];
		bool b = true;
		for (int i=1; i<n; i++) {
			while (v[sta[p-1]][a[i]] == 0) {
				p--;
				if (p == 0) {
					b = false;
					break;
				}
			}
			if (b == false) break;
			sta[p++] = a[i];
		}
		if (b) {
			string ss = "";
			for (int i=0; i<n; i++) ss = ss + s[a[i]];
			if (ss < out) out = ss;
		}
			
	} while  (next_permutation(a,a+n));

	cout << "Case #" << tc << ": ";
	cout << out << endl;
}

int main() {
	int T;
	cin >> T;
	for (int tc=1; tc<=T; tc++) solve(tc);
	return 0;
}
