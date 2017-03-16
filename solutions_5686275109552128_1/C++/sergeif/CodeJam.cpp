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
bool candoneInt(const int* p, int t, int spl) {
	int acc = 0;
	for (int i = N - 1; i > 0; i--) {
		if (p[i] > 0) {
			if (i <= t) continue;
			int rspl = i / t + (int)(i % t != 0);
			acc += (rspl-1) * p[i];
		}
	}
	return acc <= spl;
}
bool candoneInt(const int* p, int t) {
	bool bCanDone = false;
	for (int spl = 0; spl < t && ! bCanDone; spl++) {
		bCanDone = candoneInt(p, t - spl, spl);
	}
	return bCanDone;
}
void problemb(int t) {

	int D;
	int PP[1001];
	cout << "Case #" << (t + 1) << ": ";
	cin >> D;
	int curmax = 0;
	memset(PP, 0, sizeof(int) * N);
	for (auto i = 0; i < D; ++i) {
		int val;
		cin >> val;
		PP[val]++;
		if (val > curmax) curmax = val;
	}
	int l = 1;
	int r = curmax;
	while (r - l > 1) {
		int mid = (r + l) / 2;
		if (candoneInt(PP, mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	int res = r;
	if (candoneInt(PP, l)) res = l;
	cout << res << endl;
}


int main()
{
	int T;
	cin >> T;
	for (auto t = 0; t < T; ++t)
	{
		problemb(t);
	}
	
	return 0;
}

