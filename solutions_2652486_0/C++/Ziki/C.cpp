/*==================================================*\
 |Author: ziki
 |Created Time: 2013/4/27 10:52:03
 |File Name: C.cpp
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

map<vector<int> , int > mp;
int tmp[10];
int R,n,m,K;
void dfs(int d) {
    if(d == n) {
        vector<int> v(tmp,tmp+n);
        sort(v.begin(),v.end());
        mp[v]++;
        return ;
    }
    for(tmp[d] = 2; tmp[d]<=m; tmp[d]++) dfs(d+1);
}

int main() {
    int T; cin>>T;
    rep(cas,T) {
        cin>>R>>n>>m>>K;
        printf("Case #1:\n");
        mp.clear();
        dfs(0);
        int X = 0;
        //out(mp.size());
        rep(t,R) {
            vector<int> ans, v;
            int q = 0;
            int s[20];
            rep(i,K) cin>>s[i];
            int thas = 0;
            //show(s,K);
            repit(it,mp) {
                //if(it->second<q) continue;
                v=it->ff;
                //show(v,v.size());
                map<int,int> has;
                rep(msk,1<<v.size()) {
                    int sum = 1;
                    rep(i,v.size()) if((1<<i)&msk) sum *= v[i];
                    has[sum]++;
                    //out(sum);
                }
                int tcnt = 0, yes = true;
                rep(i,K) {
                    //out(s[i]); out(yes);
                    if(!has.count(s[i])) {
                        yes = false; break;
                    }
                    else {
                        tcnt += has[s[i]];
                    }
                }
                if(!yes) continue;
                thas++;
                //puts("not");
                int qua = it->second*tcnt;
                if(qua>q) {
                    ans = v;
                    q = qua;
                }
                else if(qua == q) {
                    if(rand()%2) ans = v;
                }
            }
            //out(thas);
            if(thas == 1) X++;
            rep(i,ans.size()) printf("%d",ans[i]);
            puts("");
        }
        //out(X);

    }
    return 0;
}

