#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <complex>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mp make_pair
using namespace std;

int solve(){
    int a,mo[111],n;
    scanf("%d%d",&a,&n);
    rep(i,n) scanf("%d",mo+i);
    if(a==1) return n;
    sort(mo,mo+n);

    int ans = 999;
    for(int i = 0; i <= n; i++){
        int temp = n-i; //remove
        int sz = a;
        for(int j = 0; j < i; j++){
            //absorb
            while(mo[j]>=sz){
                sz += sz-1;
                temp++;
            }
            sz += mo[j];
        }
        ans = min(ans,temp);
    }
    return ans;
}


int main(){
    int t;
    scanf("%d",&t);
    rep(tc,t){
        printf("Case #%d: %d\n",tc+1,solve());
    }
    return 0;
}


