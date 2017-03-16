#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const string res[4] = {"Draw", "O won", "X won", "Game has not completed"};

int n;
int m;
string s[4];

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

		for (int i = 0; i < 4; i++) cin >> s[i];
		int ok = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (s[i][j] == '.')
					ok = 3;
		for (int i = 0; i < 4; i++) {
			int ok1 = 1, ok2 = 1;
			for (int j = 0; j < 4; j++) {
				if (s[i][j] != 'O' && s[i][j] != 'T') ok1 = 0;
				if (s[i][j] != 'X' && s[i][j] != 'T') ok2 = 0;
			}
			if (ok1) ok = 1;
			if (ok2) ok = 2;
		}
		for (int i = 0; i < 4; i++) {
			int ok1 = 1, ok2 = 1;
			for (int j = 0; j < 4; j++) {
				if (s[j][i] != 'O' && s[j][i] != 'T') ok1 = 0;
				if (s[j][i] != 'X' && s[j][i] != 'T') ok2 = 0;
			}
			if (ok1) ok = 1;
			if (ok2) ok = 2;
		}
		{
			int ok1 = 1, ok2 = 1;
			for (int j = 0; j < 4; j++) {
				if (s[j][j] != 'O' && s[j][j] != 'T') ok1 = 0;
				if (s[j][j] != 'X' && s[j][j] != 'T') ok2 = 0;
			}
			if (ok1) ok = 1;
			if (ok2) ok = 2;
		}
		{
			int ok1 = 1, ok2 = 1;
			for (int j = 0; j < 4; j++) {
				if (s[j][3 - j] != 'O' && s[j][3 - j] != 'T') ok1 = 0;
				if (s[j][3 - j] != 'X' && s[j][3 - j] != 'T') ok2 = 0;
			}
			if (ok1) ok = 1;
			if (ok2) ok = 2;
		}
				
		cout << "Case #" << it << ": " << res[ok];

		cout << endl;

		cerr << it << " / " << tt << endl;
	}
	return 0;
}