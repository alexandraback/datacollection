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

int dp[(1<<16)+5];
int n;
string s1[20];
string s2[20];

int r(int mask) {
	if ((1<<n)==(mask+1))
		return 0;
	if (dp[mask]!=-1)
		return dp[mask];
	int res = 0;
	FOR(i,0,n) {
		if (((mask>>i)&1) == 0) {
			bool f1 = false;
			bool f2 = false;
			FOR(j,0,n) {
				if ((mask>>j)&1) {
					if (s1[i] == s1[j])
						f1 = true;
					if (s2[i] == s2[j])
						f2 = true;
				}
			}
			if ((f1) && (f2)) {
				res = max(res,1+r(mask|(1<<i)));
			} else {
				res = max(res,r(mask|(1<<i)));
			}
		}
	}
	return dp[mask] = res;
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
        FOR(testNumber, 1, tests+1) {
        	cout<<"Case #"<<testNumber<<": ";
        	cin>>n;
        	FOR(i,0,n)
        		cin>>s1[i]>>s2[i];
        	MEMS(dp,-1);
        	cout<<r(0)<<endl;
        }

#ifdef Fcdkbear
        double end = clock();
        fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
        return 0;
}
