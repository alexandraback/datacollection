#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<set>
#include<string>
#include<queue>
using namespace std;
typedef long long LL;
const int maxn = 100005;

int n;
LL m,B[55];
int main(){
    freopen("1.in","r",stdin);
    freopen("out.txt","w",stdout);
    B[0]=1;
    for(int i=1;i<=50;i++){
        B[i]=B[i-1]<<1;
    }
    int t,a,ca=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%lld",&n,&m);
        printf("Case #%d: ",++ca);
        if(m>B[n-2]){
            printf("IMPOSSIBLE\n");
        }
        else if(m==B[n-2]){
            printf("POSSIBLE\n");
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(j>i) printf("1");
                    else printf("0");
                }
                printf("\n");
            }
        }
        else{
            printf("POSSIBLE\n");
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(j>i&&(j!=n||(m&B[i-2]))) printf("1");
                    else printf("0");
                }
                printf("\n");
            }
        }
    }
    return 0;
}
