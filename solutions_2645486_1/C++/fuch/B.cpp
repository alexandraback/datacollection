#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <functional>

#define rep(i,n) for(int i=0;i<(n);++i)
#define foreach(i,v) for(__typeof(v.begin()) i=v.begin();i!=v.end();++i)
#define ass(v) (v)||++*(int*)0;

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<double> VD;
typedef long long LL;

int E, N, R;
VI next;
VI val;

LL solve()
{
	next.resize(N);
	VI seq;
	int gap = E / R;
	for (int i = N - 1; i >= 0; --i)
	{
		while (!seq.empty() && val[seq.back()] <= val[i]) seq.pop_back();
		next[i] = (seq.empty() || seq.back() - i > gap) ? -1 : seq.back();
		seq.push_back(i);
	}

	LL ans = 0;
	int en = E;
	for (int i = 0; i < N; ++i)
	{
		int cost = (next[i] == -1) ? en : (next[i] - i) * R + en - E;
		if (cost < 0) cost = 0;
		en -= cost;
		en += R;
		ans += (LL)cost * val[i];

	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; ++cs)
	{
		scanf("%d%d%d", &E, &R, &N);
		val.resize(N);
		for (int i = 0; i < N; ++i) scanf("%d", &val[i]);
		printf("Case #%d: %I64d\n", cs, solve());
	}
	return 0;
}
