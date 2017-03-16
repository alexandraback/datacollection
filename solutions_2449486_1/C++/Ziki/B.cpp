/*==================================================*\
 |Author: ziki
 |Created Time: 2013/4/13 10:02:49
 |File Name: B.cpp
 |Description: 
\*==================================================*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;
using namespace rel_ops;

typedef long long int64;
typedef unsigned long long uint64;
const double pi=acos(-1.0);
const double eps=1e-11;
const int inf=0x7FFFFFFF;
template<class T> inline bool checkmin(T &a,T b){return b<a?a=b,1:0;}
template<class T> inline bool checkmax(T &a,T b){return b>a?a=b,1:0;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define mem(a,b) memset(a, b, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define rep(i,n) for(int i=0; i<n; i++)
#define repit(i,v) for(typeof(v.begin()) i=v.begin(); i!=v.end(); i++)
#define iter(v) typeof(v.begin())
#define ff first
#define ss second
#define out(x) (cout<<#x<<": "<<x<<endl)
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}

const int N = 105;
bool ans[N][N];
int  chk[N][N], a[N][N];
int n,m;
int tans;
int clk;
bool valid(int i,int j) {
    return i>=0 && i<=n+1 && j>=0 && j<=m+1;
}

int main() {
    int T;
    cin>>T;
    rep(cas,T) {
        scanf("%d%d",&n,&m);
        clr(ans); clr(chk); clr(a);
        rep(i,n) rep(j,m) cin>>a[i][j];
        tans = 0;
        for(int h = 100; h>0; h--) {
            int t;
            rep(i,n) {
                for(t=0; t<m; t++) if(a[i][t]>h) break;
                if(t==m) 
                    for(t=0; t<m; t++) if(a[i][t] == h && !ans[i][t]) {
                        tans += 1;
                        ans[i][t] = 1;
                    }
            }
            rep(i,m) {
                for(t=0; t<n; t++) if(a[t][i]>h) break;
                if(t==n) 
                    for(t=0; t<n; t++) if(a[t][i] == h && !ans[t][i]) {
                        tans += 1;
                        ans[t][i] = 1;
                    }
            }
        }
        printf("Case #%d: %s\n", cas+1, tans == n*m?"YES":"NO");
    }
    return 0;
}

