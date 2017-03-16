
/* Author: Mahesh */

#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string.h>
#include <memory.h>
#include <cassert>
#include <climits>
#include <cfloat>
#include <sstream>

using namespace std;

#define ford(i, a, b, c)        for(int i=(a); i<(b); i+=(c))
#define fori(i, a, b)           ford(i,a,b,1)
#define rep(i, n)               fori(i,0,n)
#define ifor(i, a, b)           for(int i=(a); i>=(b); i--)
#define iter(i, a)              for(typeof((a).begin()) i=(a).begin(); i!=(a).end(); i++)
#define si(x)                   ((int)x.size())
#define SS                      ({int x;scanf("%d",&x);x;})
#define pb                      push_back
#define mp                      make_pair
#define all(a)                  a.begin(),a.end()
#define SORT(v)                 sort(all(v))
#define fill(a, v)              memset(a, v, sizeof(a))
#define inf                     (int)1e9
#define linf                    (long long)1e18
#define V                       vector
#define S                       string
#define XX                      first
#define YY                      second
#define P(v)                    rep(i, si(v)) cout<<v[i]<<" "; puts("")

typedef V<int> vi;
typedef V<S> vs;
typedef long long ll;
typedef pair<int,int> pii;

/* Program Body starts here */

double p[1000000], pre[1000000];

int main()
{
    freopen("in.in", "r", stdin);
    freopen("o.txt", "w", stdout);
    int T=SS;
    rep(t, T){
        int A = SS, B = SS;
        rep(i, A){
            scanf("%lf", &p[i]);
        }
        pre[0] = 1;
        fori(i, 1, A+1){
            pre[i] = pre[i-1]*p[i-1];
        }
        double ans = B+2;
        rep(i, A+1){
            ans = min(ans, pre[A-i]*(i+(B-A+i+1)) + (1-pre[A-i])*(i+B-A+i+1+B+1));
        }
        printf("Case #%d: %.9lf\n", t+1, ans);
    }
    return 0;
}











