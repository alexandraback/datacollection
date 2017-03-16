#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define REPD(k,a) for(int k=(a)-1; k >= 0; --k)
#define PB push_back 
#define MP make_pair

void splitPP(int* PP, int& curmax) {
	int val = curmax;
	int r1 = val / 2;
	int r2 = val / 2 + val % 2;
	PP[curmax]--;
	PP[r1]++;
	PP[r2]++;
	while (PP[curmax] == 0 && curmax > 0) curmax--;
}
int N = 1001;
int recursion(int bsol, int depth, const int* p) {
	if (depth >= bsol) return bsol;
	int* pp = new int[N];
	memcpy(pp, p, N * sizeof(int));
	int bbsol = bsol;
	int i = N - 1;
	for (i = N - 1; i > 0; i--) {
		if (pp[i] > 0) break;
	}
	if (i + depth < bsol)
		bbsol = i + depth;
	int j = i / 2;
	//for (int j = i / 2 - (i % 2 != 0); j < i / 2 && j < i; j++) {
		//if (j < 1) continue;
		pp[i]--;
		pp[i - j]++;
		pp[j]++;
		int v = recursion(bbsol, depth + 1, pp);
		if (v < bbsol) bbsol = v;
		memcpy(pp, p, N * sizeof(int));
	//}
	delete [] pp;
	return bbsol;
}
void problemb(int t) {

	int tt[10] = { 0, 1, 2, 3, 3, 4, 4, 5, 5, 5 };
	int ts[10] = { 0, 0, 1, 1, 1, 1, 1, 1, 3, 6 };
	int D;
	int PP[1001];
	cout << "Case #" << (t + 1) << ": ";
	cin >> D;
	int curmax = 0;
	memset(PP, 0, sizeof(int) * 1001);
	for (auto i = 0; i < D; ++i) {
		int val;
		cin >> val;
		PP[val]++;
		if (val > curmax) curmax = val;
	}
	int res = recursion(curmax, 0, PP);
	cout << res << endl;
}
void problemd(int t) {

	int X, R, C;
	cout << "Case #" << (t + 1) << ": ";
	cin >> X >> R >> C;
	if ((R * C) % X != 0) {
		cout << "RICHARD" << endl;
		return;
	}
	if (C == 1 || R == 1) {
		if (X > 2) {
			cout << "RICHARD" << endl;
			return;
		}
	}
	if (X > R * C) {
		cout << "RICHARD" << endl;
		return;
	}
	if (X > R && X > C) {
		cout << "RICHARD" << endl;
		return;
	}
	if (X == 4 && (R == 2 || C == 2)) {
		cout << "RICHARD" << endl;
		return;
	}
	cout << "GABRIEL" << endl;
}


int main()
{
	int T;
	cin >> T;
	for (auto t = 0; t < T; ++t)
	{
		problemd(t);
	}
	
	return 0;
}

