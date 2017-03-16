#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int,int> PII;
#define For(i,n) for(int i=0;i<n;i++)
#define sz(i) int(i.size())
#define mst(i,n) memset(i,n,sizeof(i))
#define eps 1e-11
#define MOD 1000000007
#define LL long long
#define pi acos(-1)
#define ALL(n) n.begin(),n.end()
#define pb push_back
#define mp make_pair
#define iFor(i,n) for(typeof(n.begin()) i=n.begin();i!=n.end();i++)

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int ca = 0;
    scanf("%d",&ca);
    For(c, ca){
        int n,m;
        int h[105][105];
        scanf("%d %d",&n,&m);
        int g[105][105];
        For(i,n)
            For(j,m){
                scanf("%d",h[i]+j);
                g[i][j] = 1;
            }
        For(i,100){
            int t = i+1;
            For(j,n){
                bool p = true;
                For(k,m) if(g[j][k]){
                    if(h[j][k] != t) p =false;
                }
                if(p) For(k,m) g[j][k] = 0;
            }
            For(k,m){
                bool p = true;
                For(j,n) if(g[j][k]){
                    if(h[j][k]!=t) p =false;
                }
                if(p) For(j,n) g[j][k] = 0;
            }
        }
        bool res = true;
        For(i,n)For(j,m) if(g[i][j]) res = false;
        printf("Case #%d: %s\n",c+1,res?"YES":"NO");
    }
}
