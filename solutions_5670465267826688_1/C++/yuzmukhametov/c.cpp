// -Wl,--stack,9001 
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)((x).size()))
#define rep(i, N) for (int i = 0; i < N; ++i)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
typedef long long lint;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define ONE 1
#define II 2
#define JJ 3
#define KK 4

int convert(char ch) {
	if (ch == '1') return ONE;
	if (ch == 'i') return II;
	if (ch == 'j') return JJ;
	if (ch == 'k') return KK;	
	puts("invalid_convert");
	return 0;
}


// int MUL[4][4] = {
// 	{ONE, II, JJ, KK},
// 	{II, -ONE, KK, -JJ},
// 	{JJ, -KK, -ONE, II},
// 	{KK, JJ, -II, -ONE},

// };

inline int my_mul(int x, int y) {
	int sgn = 1;
	if (x < 0) {sgn = -sgn; x = -x; }
	if (y < 0) {sgn = -sgn; y = -y; }
	if (x == 1) return y * sgn;
	if (y == 1) return x * sgn;
	if (x == y) return -1 * sgn;
	if (x == II && y == JJ) return +KK * sgn;
	if (x == JJ && y == II) return -KK * sgn;		
	if (x == II && y == KK) return -JJ * sgn;
	if (x == KK && y == II) return +JJ * sgn;		
	if (x == JJ && y == KK) return +II * sgn;
	if (x == KK && y == JJ) return -II * sgn;		
	puts("invalid args");
	return 0;
}

int DIV[100][100];

inline int my_div(int d, int x1) {
	if (DIV[d + 4][x1 + 4]) return DIV[d + 4][x1 + 4];
	vi res;
	for (int x2 = -4; x2 <= 4; ++x2) {
		if (x2==0) continue;
		int t = my_mul(x1, x2);
		if (t == d) res.pb(x2);
	}
	if (sz(res) != 1) {
		puts("hmmm");	
		char tt;
		cin >> tt;
		return 3;
	} 
	return DIV[d + 4][x1 + 4] = res[0];
}

inline bool check(int x1, int x2, int x3) {
	return x1 == II && x2 == JJ && x3 == KK;
}
int A[(1 << 20)  + 1] ;
lint H = 4;
char S[(1 << 20) + 1];

void solve(int num) {
	int L;
	lint X;
	string s;
	//L = 1; X = 10000;
	//s = "i";
	cin >> L >> X >> s;
	if (X > H) {
		X = H + X % 4;
	}
	// while (X + 4 > H) {
	// 	X -= 4;
	// }
	// if (X > H) {
	// 	if (X & 1) {
	// 		X = H + 1;
	// 	} else {
	// 		X = H;
	// 	}
	// }
	//string S = "";
	int pos = 0;
	for (int i = 0; i < X; ++i) {
		for (int j = 0; j < L; ++j) {
			S[pos++] = s[j];
		}
		//S += s;
	}
	S[pos] = 0;
	if (pos != L * X) {
		puts("sdfsd");
	}
	int n = L * X;
	int x1 = 1;
	bool ok = false;

	int x = 1;
	for (int i = 0; i < n; ++i) {
		A[i] = convert(S[i]);
		x = my_mul(x, A[i]);
	}

	for (int i = 0; !ok && i < n; ++i) {
		x1 = my_mul(x1, A[i]);
		if (x1 != II) continue;
		int x2 = 1;
		for (int j = i + 1; !ok && j < n; ++j) {
			x2 = my_mul(x2, A[j]);
			if (x2 != JJ) continue;
			// j + 1..n-1
			int len1 = i + 1; // 0..i
			int len2 = j - i; // i+1..j
			int len3 = n - len1 - len2;
			if (len3 > 0) {
				int x12 = my_mul(x1, x2);
				int x3 = my_div(x, x12);
				if (x3 == KK) {
				//if (check(x1, x2, x3)) {
					ok = true;
					break;
				}
			}
		}
		
	}

	string ans = ok ? "YES" : "NO"; 

	printf("Case #%d: %s\n", num, ans.c_str());
}

int main() {
	// for (int d = -4; d <= 4; ++d) {
	// 	for (int x1 = -4; x1 <= 4; ++x1) {
	// 		if (d == 0 || x1 == 0) continue;
	// 		//printf("chck %d  %d\n", x1, d);
	// 		int x2 = my_div(d, x1);
	// 		printf("%d * %d = %d\n", x1, x2, d);
			
	// 	}
	// }
	// return 0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tst;
	cin >> tst;
	for (int i = 1; i <= tst; ++i) {
		solve(i);
	}
    return 0;
}
