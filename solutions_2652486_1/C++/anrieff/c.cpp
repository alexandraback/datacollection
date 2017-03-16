#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

int r, n, m, k;

ll prods[20];

vector<vector<int> > C;
vector<map<ll, int> > P;
int logg[32];

void bt(int level, int last)
{
	if (level == n) {
		vector<int> c;
		FOR(i, n) c.push_back(logg[i]);
		C.push_back(c);
		return;
	}
	for (int i = last; i <= m; i++) {
		logg[level] = i;
		bt(level + 1, i);
	}
}

void bt2(const vector<int>& numbers, map<ll, int>& mp, ll curProd, int pos)
{
	if (pos == (int) numbers.size()) {
		mp[curProd]++;
		return;
	}
	bt2(numbers, mp, curProd, pos + 1);
	bt2(numbers, mp, curProd * (ll) numbers[pos], pos + 1);
}

void genCombos(void)
{
	bt(0, 2);
	P.resize(C.size());
	REP(i, C) {
		bt2(C[i], P[i], 1, 0);
	}
}

double test(const vector<int>& nums, const map<ll, int>& mp)
{
	double prob = 1;
	FOR(i, k) {
		map<ll, int>::const_iterator it = mp.find(prods[i]);
		if (it == mp.end()) return 0;
		prob *= it->second;
	}
	return prob;
}

void solve(void)
{
	double maxScore = -1;
	vector<int> best;
	REP(i, C) {
		double score = test(C[i], P[i]);
		if (score > maxScore) {
			maxScore = score;
			best = C[i];
		}
	}
	REP(i, best) printf("%d", best[i]);
	printf("\n");
}

int main(void)
{
	int TC;
	scanf("%d", &TC);
	scanf("%d%d%d%d", &r, &n, &m, &k);
	genCombos();
	printf("Case #1:\n");
	FOR(i, r) {
		FOR(j, k) scanf("%lld", &prods[j]);
		solve();
	}
	return 0;
}
