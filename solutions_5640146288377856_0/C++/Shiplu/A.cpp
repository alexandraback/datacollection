#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<numeric>
#include<fstream>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps (1e-9)
#define inf (1<<29)
#define i64 long long
#define u64 unsigned i64

int r,c,w, dp[12][1<<11][1<<11];
int solve(int ship, int mask1, int mask2){
    if(ship == w) return 0;
    int &ret = dp[ship][mask1][mask2];
    if(ret!=-1) return ret;
    ret = inf;
    int i, nmx,nxx, r1, j;
        for(i = 0;i<c;i++){
            if( ( mask2 & (1<<i) ) ||  (mask1 & (1<<i))) continue;
            r1 = 0;
            int k;
            for(j = 0;j<c-w+1;j++){
                for(k = j;k<=j+w-1;k++){
                    if(mask2 & (1<<k)) break;
                }
                if(k<=j+w-1) continue;
               // if(nmx>=j && nxx<=j+w-1){
                    if(i<j || i>j+w-1)
                        r1 = max(r1,solve(ship,mask1,mask2 | (1<<i))+1);
                    else
                        r1 = max(r1, solve(ship+1,mask1 | (1<<i),mask2)+1);
                //}
            }
            ret = min(ret,r1);
        }
    return ret;
}
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.ans","w",stdout);
    int t,cs = 1;
    cin>>t;
    while(t--){
        cin>>r>>c>>w;
        SET(dp);
        printf("Case #%d: %d\n",cs++,solve(0,0,0));
    }
	return 0;
}
