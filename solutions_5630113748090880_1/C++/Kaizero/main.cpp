#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n, H[2510];
int main(){
    int TT, TC, i, j, a;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&TC);
    for(TT=1;TT<=TC;TT++){
        scanf("%d",&n);
        for(i=1;i<=2500;i++)H[i]=0;
        for(i=1;i<=2*n-1;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&a);
                H[a]++;
            }
        }
        printf("Case #%d: ",TT);
        for(i=1;i<=2500;i++)if(H[i]%2==1)printf("%d ",i);
        printf("\n");
    }
}
