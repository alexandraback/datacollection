#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
#define N 111111
#define M 222222
#define md 1000000007
#define ll long long

int main(){
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        int k, c, s;
        scanf("%d%d%d",&k,&c,&s);
        if(s >= k/c){
            printf("Case #%d:", tt);
            for(int i=0;i<s;){
                ll u = 0;
                for(int j=0;j<c;j++,i++){
                    u *= k;
                    if(i < s) u += i;
                }
                printf(" %lld",u+1);
            }
            printf("\n");
        } else
            printf("Case #%d: IMPOSSIBLE\n",tt);
    }
}