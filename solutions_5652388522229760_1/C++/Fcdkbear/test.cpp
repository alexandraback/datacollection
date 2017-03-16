#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define MEMS(a,b) memset((a),(b),sizeof(a))
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define LL long long
#define U unsigned

LL solve(int n) {
	int i = 1;
	vector<int> was;
	was.resize(10,0);
	int cnt = 0;
	while (1) {
		LL v = n*1ll*i;
		while (v)
		{
			int d = v%10;
			v/=10;
			cnt += (was[d] == 0);
			was[d] = 1;
		}
		if (cnt == 10)
			return n*1ll*i;
		i++;
	}
	return -1;
}

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	double beg = clock();
#else
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int tests;
	scanf("%d",&tests);
	FOR(testNumber,1,tests+1) {
		int v;
		scanf("%d",&v);
		printf("Case #%d: ",testNumber);
		if (v == 0)
			printf("INSOMNIA\n");
		else
		{
			LL res = solve(v);
			cout<<res<<endl;
		}
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}
