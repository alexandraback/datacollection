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
typedef unsigned long long ULL;

ULL r, t;

ULL solve()
{
	ULL st = 0, ed = 1LL << 30;
	while (st <= ed)
	{
		ULL md = (st + ed) >> 1;
		ULL area = (2 * r + 2 * md + 1) * (md + 1);
		if (area > t) ed = md - 1;
		else st = md + 1;
	}
	return st;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; ++cs)
	{
		scanf("%I64u%I64u", &r, &t);
		printf("Case #%d: %I64u\n", cs, solve());
	}
	return 0;
}
