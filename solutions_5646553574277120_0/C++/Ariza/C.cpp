#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define EPS (1e-10)
#define lef(x) (x<<1)
#define rig(x) (x<<1)+1
#define PI (2*acos(0.0))

void solve(){
     printf(" ");
     int c,d,v;
     int memo[35],coin[5];
     memset(memo,0,sizeof(memo));
     scanf("%d %d %d",&c,&d,&v);
     for (int i=0;i<d;++i){
         scanf("%d",&coin[i]);
     }
     memo[0]=1;
     vector<int> ans;
     for (int i=0;i<d;++i) ans.pb(coin[i]);
     for (;;){
         memset(memo,0,sizeof(memo));
         memo[0]=1;
         for (int i=0;i<ans.size();++i){
             for (int j=v;j>0;--j){
                 if (j-ans[i]>=0)
                    if (memo[j-ans[i]]==1)
                       memo[j] = 1;
             }
         }
         bool chk=0;
         for (int i=1;i<=v;++i){
             if (memo[i]==0){
                ans.pb(i);
                chk=1;
                break;
             }
         }
         if (chk==0) break;
     }
     printf("%d\n",(int)ans.size()-d);
}

int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d:",test);
        solve();
    }
    return 0;
}
