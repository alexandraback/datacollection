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

int divs[] = {3,2,5,2,7,2,3,2,11};
int dp[35][60000];

int p6[15];
int mod[11][40];
int M = 501;

int convert(int mask, int pos) {
	int res = 0;
	int tot = 1;
	FOR(i,2,11) {
		int c = (mask%divs[i - 2]);
		int p = 1;
		FOR(j,0,pos - 1)
			p = (p*i)%divs[i - 2];
		c += p;
		c%=divs[i - 2];
		res += c*tot;
		tot*=divs[i - 2];
		mask/=divs[i - 2];
	}
	return res;
}

int good(int mask) {
	FOR(i,2,11) {
		int c = (mask%6);
		if (((c == 1) || (c == 5)) && (i!=6))
			return 0;
		mask/=3;
	}
	return 1;
}

int n,j;

int r(int pos, int mask) {
	if (pos == 0) {
		return (mask == 0);
	}
	if (dp[pos][mask] != -1) {
		return dp[pos][mask];
	}
	int res = 0;
	FOR(dig,0,2) {
		if (dig == 0) {
			if ((pos == n) || (pos == 1))
				continue;
			res += r(pos - 1, mask);
		}
		int nmask = convert(mask,pos);
		res += r(pos - 1, nmask);
	}
	return dp[pos][mask] = MIN(res,M);
}

vector<pair<string, int > > ans;

void restoreAns(string s, int pos, int mask) {
	if (pos == 0) {
		if (ans.size() >= j)
			return;
		ans.push_back(mp(s,mask));
		return;
	}
	if (ans.size() >= j)
		return;
	if ((pos != n) && (pos != 1)) {
		if (r(pos - 1, mask) > 0) {
			restoreAns(s+'0',pos - 1,mask);
		}
	}
	if (ans.size() >= j)
		return;
	int nmask = convert(mask,pos);
	if (r(pos - 1, nmask) > 0) {
		restoreAns(s+'1',pos - 1,nmask);
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

	p6[0] = 1;
	FOR(i,1,15)
		p6[i] = p6[i - 1]*6;
	FOR(p,2,11) {
		mod[p][0] = 1;
		FOR(i,1,40) {
			mod[p][i] = (mod[p][i - 1] * p)%6;
		}
	}
	int tests;
	scanf("%d",&tests);
	FOR(testNumber,1,tests+1) {
		printf("Case #1:\n");
		cin>>n>>j;
		MEMS(dp,-1);
		r(n,0);
		restoreAns("",n,0);
		FOR(i,0,j) {
			cout<<ans[i].first;
			FOR(k,0,9)
				cout<<" "<<divs[k];
			cout<<endl;
		}
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}
