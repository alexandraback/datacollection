#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#else
#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#endif
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <string>
#include <iostream>
#define FOR(x,y,z) for (int x=(y); x<=(z); ++x)
#define FORD(x,y,z) for(int x=(y); x>=(z); --x)
#define REP(x,y) for (int x=0; x<(y); ++x)
#if defined(__GNUC__) && __cplusplus < 201103L
#define FOREACH(y,x) for (typeof((x).begin()) y = (x).begin(); y != (x).end(); ++y)
#else
#define FOREACH(y,x) for (auto y = (x).begin(); y != (x).end(); ++y)
#endif
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x).size())
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
const int INF = 1000000001;
const int P = 1000000007;

int Fct(int n)
{
	int r = 1;
	FOR(i,2,n) r = ((LL)r * i) % P;
	return r;
}

struct Problem {
	int n;
	vector<string> s;
	VI bgn,end,all;
	Problem(const vector<string>& sarg) : n(SIZE(sarg)), s(sarg), bgn(26,-1), end(26,-1), all(26)
	{
		FOREACH(it1,s) {
			FOREACH(it2,*it1) *it2 -= 'a';
		}
	}
	int Go();
	int ClcSq(int x);
};

int Problem::Go()
{
	REP(i,n) {
		char c1 = s[i][0], c2 = s[i].back();
		if (c1 == c2) {
			FOREACH(it,s[i]) {
				if (*it != c1) return 0;
			}
			all[c1]++;
		}
		else {
			if (bgn[c1] != -1 || end[c2] != -1) return 0;
			bgn[c1] = i;
			end[c2] = i;
		}
	}
	vector<bool> occ(26);
	REP(i,n) {
		char c1 = s[i][0], c2 = s[i].back();
		if (c1 == c2) continue;
		int ix = 1;
		while (s[i][ix] == s[i][ix-1]) ++ix;
		while (1) {
			while (ix+1 < SIZE(s[i]) && s[i][ix] == s[i][ix+1]) ++ix;
			if (ix == SIZE(s[i])-1) break;
			int x = s[i][ix];
			if (occ[x] || bgn[x] != -1 || end[x] != -1 || all[x] > 0) {
				return 0;
			}
			occ[x] = true;
			++ix;
		}
	}
	VI v0;
	REP(i,26) {
		if (end[i] == -1 && (bgn[i] != -1 || all[i] > 0)) v0.push_back(i);
	}
	if (v0.empty()) return 0;
	int res = Fct(SIZE(v0));
	FOREACH(it,v0) {
		int x = ClcSq(*it);
		res = ((LL)res * x) % P;
	}
	return res;
}

int Problem::ClcSq(int x)
{
	int r = Fct(all[x]);
	while (bgn[x] != -1) {
		x = s[bgn[x]].back();
		r = ((LL)r * Fct(all[x])) % P;
	}
	return r;
}

char tmp[102];

int main(int argc, char** argv)
{
	int tc;
	scanf("%d", &tc);
	FOR(tccc,1,tc) {
		int n;
		scanf("%d", &n);
		vector<string> s(n);
		REP(i,n) {
			scanf("%s", tmp);
			s[i] = tmp;
		}
		Problem p(s);
		printf("Case #%d: %d\n", tccc, p.Go());
	}

#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}
