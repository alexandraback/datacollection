#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <memory.h>
#include <ctype.h>
  
#include <iostream>
  
#include <string>
#include <complex>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <sstream>
  
using namespace std;
  
template<typename TYPE> inline TYPE sqr(const TYPE& a) { return (a) * (a); }
  
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
  
typedef long long li;
typedef double ld;
typedef pair<int, int> pt;
  
const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 1010;

ld nao[N];
ld ken[N];

int cheat(int n) {
	int nlf = 0, nrg = n - 1;
	int klf = 0, krg = n - 1;
	int res = 0;
	while (nlf <= nrg) {
		/* invest in loss */
		while (nlf <= nrg && nao[nlf] < ken[klf]) {
			++nlf;
			--krg;
		}
		while (nlf <= nrg && nao[nlf] > ken[klf]) {
			++nlf;
			++klf;
			++res;
		}
	}
	return res;
}

bool kused[N];
set<pair<ld, int> > kavail;
int find_greater(int fm, int to, ld val) {
	auto a = kavail.upper_bound(mp(val, -1));
	if (a != kavail.end())
		return (*a).second;
	throw 1;
	while (fm + 1 < to) {
		int mid = (fm + to) / 2;
		if (ken[mid] < val)
			fm = mid;
		else
			to = mid;
	}
	for (; fm <= to; ++fm) {
		if (ken[fm] > val)
			break;
	}
	while (kused[fm])
		++fm;
	return fm;
}

void kuse(int id) {
	kused[id] = true;
	kavail.erase(kavail.lower_bound(mp(ken[id], id)));
}

int fair(int n) {
	int nlf = 0, nrg = n - 1;
	int klf = 0, krg = n - 1;
	int res = 0;
	memset(kused, 0, sizeof kused);
	kavail.clear();
	forn (i, n)
		kavail.insert(mp(ken[i], i));
	while (nlf <= nrg) {
		while (klf <= krg && kused[krg])
			--krg;
		assert(klf <= krg);
		if (nao[nrg] > ken[krg]) {
			--nrg;
			++klf;
			++res;
		} else {
			--nrg;
			int id = find_greater(klf, krg, nao[nrg]);
			kuse(id);
			//kused[id] = true;
		}
	}
	return res;
}

bool nused[N];

int ken_turn(int n, ld nao_turn) {
	int def = -1;
	forn (i, n)
		if (!kused[i]) {
			if (ken[i] > nao_turn)
				return i;
			if (def == -1)
				def = i;
		}
	return def;
}

void indent(int s) {
	forn(i, s)
		printf(" ");
}

int rec(int n) {
	int res = 0;
	forn (i, n)
		if (!nused[i]) {
			nused[i] = true;
			int k = ken_turn(n, nao[i]);
			kused[k] = true;
			int cur = 0;
			if (ken[k] < nao[i])
				++cur;
			cur += rec(n);
			res = max(res, cur);
			kused[k] = false;
			nused[i] = false;
		}
	return res;
}

int fair_brute(int n) {
	memset(nused, 0, sizeof nused);
	memset(kused, 0, sizeof kused);
	return rec(n);
}

int main() {
	int tests;
	scanf("%d", &tests);
	for1(it, tests) {
		int n;
		scanf("%d", &n);
		forn(i, n)
			scanf("%lf", &nao[i]);
		forn(i, n)
			scanf("%lf", &ken[i]);
		sort(nao, nao + n);
		sort(ken, ken + n);
		/*
		forn (i, n)
			printf("%lf ", nao[i]);
		puts("");
		forn (i, n)
			printf("%lf ", ken[i]);
		puts("");
		*/
		int cheat_score = cheat(n);
		int fair_score = fair(n);
		/*
		int fair_brute_score = fair_brute(n);
		if (fair_score != fair_brute_score)
			printf("ERROR! brute %d != %d\n", fair_brute_score, fair_score);
		*/
		printf("Case #%d: %d %d\n", it,
			cheat_score, fair_score);
		continue;
	}  
    return 0;
}
