// Contestant: Veselin 'anrieff' Georgiev
// Round: Google Code Jam Qualification 2016
// Task C: Some greedy. Find all independent solutions of the form 
// A->B->C->...->F<->G<-H<-I 
// L->M->N->..->O<->Q<-R<-S ...
// ...
// concatenate all such disjoint solutions - this is a possible solution to the task. Note this does not use
// the fact, that the kids are ordered in a circle, thus subsolutions are clearly independent and can be put in any order.
// The only other option is to have a really big circle of friends, in which case you have to use the
// circular property.

#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

const int MAXN = 1005;

int n;
int bff[MAXN];
int seen[MAXN];

struct TwoCycle {
	pair<int, int> key;
	int maxLen1, maxLen2;
	TwoCycle(const vector<int>& path)
	{
		int l = path.size();
		key.first = min(path[l - 2], path[l - 1]);
		key.second= max(path[l - 2], path[l - 1]);
		maxLen1 = maxLen2 = 0;
		if (path[l - 2] == key.first)
			maxLen1 = l;
		else
			maxLen2 = l;
	}
	inline bool operator < (const TwoCycle& rhs) const
	{
		return key < rhs.key;
	}
	void augment(const TwoCycle& other)
	{
		maxLen1 = max(maxLen1, other.maxLen1);
		maxLen2 = max(maxLen2, other.maxLen2);
	}
	int groupSize() const
	{
		if (maxLen1 > 0 && maxLen2 > 0) return maxLen1 + maxLen2 - 2;
		return maxLen1 + maxLen2;
	}
};

#define clear(arr) memset(arr, 0, sizeof(arr))

int solve(void)
{
	scanf("%d", &n);
	FOR(x, n) {
		int y;
		scanf("%d", &y);
		y--;
		// arrow x->y
		bff[x] = y;
	}
	int answer = 0;
	vector<vector<int> > paths;
	set<TwoCycle> twoCycles;
	
	FOR(i, n) {
		vector<int> path;
		clear(seen);
		int x = i;
		while (!seen[x]) {
			path.push_back(x);
			seen[x] = path.size();
			x = bff[x];
		}
		int pos = path.size();
		int prevPos = seen[x];
		int cycleSize = pos - prevPos + 1;
		if (cycleSize == 2) {
			TwoCycle cc(path);
			auto it = twoCycles.find(cc);
			if (it == twoCycles.end())
				twoCycles.insert(cc);
			else
				const_cast<TwoCycle&>(*it).augment(cc);
		} else {
			answer = max(answer, cycleSize);
		}
	}
	int alternativeAnswer = 0;
	for (auto& cc: twoCycles)
		alternativeAnswer += cc.groupSize();
	return max(answer, alternativeAnswer);
}


int main(void)
{
//	freopen("/home/vesko/gcj/c.in", "rt", stdin);
	
	int nCases;
	scanf("%d", &nCases);
	for (int tc = 1; tc <= nCases; tc++) {
		printf("Case #%d: %d\n", tc, solve());
	}
	return 0;
}
