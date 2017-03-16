#include <vector>
#include <numeric>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <limits>
#include <iomanip>

using namespace std;

#define FOR(i,a,b)		for(int i=(a),_b=(b);i<(_b);++i)
#define FORD(i,a,b)		for(int i=(a),_b=(b);i>(_b);--i)
#define pb			push_back
#define mp			make_pair
#define	all(c)			(c).begin(),(c).end()
#define	tr(c,i)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define	present(c,x)		((c).find(x) != (c).end())
#define	cpresent(c,x)		(find(all(c),x) != (c).end())

typedef long long			ll;
typedef unsigned long long	ull;
typedef unsigned char	 	byte;
typedef vector<int>			vi;
typedef pair<int, int>		pii;
typedef pair<ll, ll>		pll;
typedef vector<pii>			vpii;

const int N = 15;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen(argv[1],"r",stdin);
#endif
#ifndef ONLINE_JUDGE
	ifstream cin(argv[1]);
#endif
#if 1
	ofstream cout(argv[2]);
	freopen(argv[2],"w",stdout);
#endif
	int T,n,s,p;
	scanf("%d",&T);
    FOR(t,1,T+1) {
	    scanf("%d%d%d",&n,&s,&p);
        int a[n];
        FOR(i,0,n) scanf("%d",a+i);
        pii ans[n];
        FOR(i,0,n) ans[i].first = ans[i].second = 0;
        FOR(i,0,n) {
            FORD(z,min(10,a[i]),p-1) {
                FORD(y,z,-1) {
                    int x = a[i]-z-y;
                    if (x >= 0 && x <= y) {
                        if (z-x == 2)
                            ans[i].second++;
                        else if (z-x < 2)
                            ans[i].first++;
                    }
                }
            }
        }
        sort(ans,ans+n);
        int cnt = 0;
        FOR(i,0,n) {
            if (s) {
                if (ans[i].first) ++cnt;
                else if (ans[i].second) {
                    ++cnt;
                    --s;
                }
            } else {
                if (ans[i].first) ++cnt;
            }
        }
        printf("Case #%d: %d\n",t,cnt);
    }

	return 0;
}
