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

int transfer(int mask, int n, int p) {
	int res = mask;
	FOR(i,0,p) {
		if ((mask>>(p - i - 1))&1)
		{
			if ((res>>i)&1)
				res ^= (1<<i);
		}
		else
			res |= (1<<i);
	}
	return res;
}

const int N = 20;

int d[(1<<N)+20];
int p[(1<<N)+20];

int solveSlow(string s) {
	int mask = 0;
	FOR(i,0,s.size())
		if (s[i] == '-')
			mask |= (1<<i);
	int n = s.size();
	FOR(i,0,(1<<n))
		d[i] = 1000000000;
	d[mask] = 0;
	p[0] = mask;
	int l = 0, r = 0;
	while (l<=r)
	{
		int now = p[l++];
		FOR(i,1,n+1) {
			int to = transfer(now,n,i);
			if (d[to]>d[now]+1) {
				r++;
				d[to] = d[now]+1;
				p[r]=to;
			}
		}
	}
	return d[0];
}

string s;

void gen() {
	FOR(it,0,100) {
		int len = rand()%6;
		len += 15;
		string s;
		FOR(i,0,len) {
			if (rand()&1) {
				s += '-';
			} else {
				s += '+';
			}
		}
		int res1 = solveFast(s);
		int res2 = solveSlow(s);
		if (res1 == res2)
			printf("ok");
		else
		{
			printf("FAIL!\n%s",s.c_str());
			return;
		}
	}
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
		cin>>s;
		printf("Case #%d: %d\n",testNumber,solveFast(s));
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}
