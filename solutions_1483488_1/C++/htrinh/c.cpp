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

const int N = 2000005;

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
	int T,a,b;
	scanf("%d",&T);
    FOR(t,1,T+1) {
	    scanf("%d%d",&a,&b);
        int cnt = 0;
        set<pii> S;
        FOR(n,a,b) {
            int x = n;
            int len = log10(x)+1;
            int d[len];
            int k = len-1;
            int v[len];
            int p = 0;
            while (x) {
                d[k] = x%10;
                x /= 10;
                v[k] = d[k]*pow(10,len-1-k)+p;
                p = v[k];
                --k;
            }
            int vv[len];
            p = 0;
            FOR(i,0,len) {
                p *= 10;
                p += d[i];
                vv[i] = p;
            }
            FOR(i,1,len) {
                if (d[i] < d[0]) continue;
                int m = v[i]*pow(10,i)+vv[i-1];
                if (m > n && m <= b && !present(S,pii(n,m))) {
                    ++cnt;
                    S.insert(pii(n,m));
                }
            }
        }
        printf("Case #%d: %d\n",t,cnt);
    }

	return 0;
}
