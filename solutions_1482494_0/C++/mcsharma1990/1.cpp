
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

int a[1000], b[1000], v[1000];

int main()
{
    freopen("in.in", "r", stdin);
    freopen("o.txt", "w", stdout);
    int T=SS;
    rep(t, T){
        int N = SS;
        int ans = 0, s = 0;
        rep(i, N){
            a[i] = SS;
            b[i] = SS;
            v[i] = 0;
        }
        while (1){
            int flag = 0;
            rep(i, N){
                if (v[i]<2 && s>=b[i]){
                    s += 2-v[i];
                    v[i] = 2;
                    flag = 1;
                    ans++;
                }
            }
            if (flag)
             continue;
            else{
                int ind = -1;
                rep(i, N){
                    if (v[i]==0 && s>=a[i] && (ind==-1 || b[i]>b[ind])){
                        ind = i;
                    }
                }
                if (ind==-1){
                    break;
                }
                else{
                    ans++;
                    s++;
                    v[ind] = 1;
                }
            }
        }
        if(count(v, v+N, 2)<N)
            printf("Case #%d: Too Bad\n", t+1);
        else
            printf("Case #%d: %d\n", t+1, ans);
    }
    return 0;
}
























