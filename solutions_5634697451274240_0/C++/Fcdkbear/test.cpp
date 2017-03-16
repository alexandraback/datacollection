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

int solveFast(string s) {
	int res = 0;
	vector<int> now;
	int cnt = 1;
	FOR(i,1,s.size()) {
		if (s[i] != s[i - 1]) {
			now.push_back((s[i - 1] == '-'));
		}
	}
	now.push_back((s[s.size() - 1] == '-'));
	FOR(i,0,now.size()) {
		if (now[i])
		{
			if (i)
				res += 2;
			else
				res++;
		}
	}
	return res;
}

string s;

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
		cin>>s;
		printf("Case #%d: %d\n",testNumber,solveFast(s));
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}
