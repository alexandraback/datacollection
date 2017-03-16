#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <cstdio>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <cassert>
#include <sstream>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef stringstream SS;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ABS(a) MAX(a,-(a))

#define SS(a) scanf("%d",&a)
#define SZ(a) ((int)a.size())
#define PB(a) push_back(a)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,(int)(n-1))
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define printv(v) REP(i,SZ(v))printf("%d ",v[i]);
#define mp(a,b) make_pair(a,b)
#define MOD 1000000007
#define INF 2147483647

int b[444];

int main() {
    freopen("dab.in","r",stdin);
    freopen("a.out","w",stdout);
    int t;
    cin>>t;
    FOR(tt,1,t) {
        int a,n;
        cin>>a>>n;
        REP(i,n) cin>>b[i];
        sort(b,b+n);
        int ans = MOD;
        FOR(i,0,n) {
            int last = n-1-i;
            int res = i;
            int cap = a;
            FOR(j,0,last) {
                if (cap > b[j]) {
                    cap += b[j];
                } else {
                    if (cap == 1) {
                        res = INF;
                        break;
                    }
                    while(cap <= b[j]) {
                        cap += cap-1;
                        res++;
                    }
                    cap += b[j];
                }
            }
            ans = MIN(res, ans);
        }

        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
