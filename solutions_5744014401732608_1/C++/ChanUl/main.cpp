#include <stdio.h>
#include <algorithm>
using namespace std;
int b;
long long m;
void solve (void)
{
    long long i,j;
    long long x=1,y;
    for(i=1;i<b-1;i++,x*=2);

    if(x<m){
        puts("IMPOSSIBLE");
        return ;
    }
    puts("POSSIBLE");

    for(i=0;i<b-1;i++){
        for(j=0;j<=i;j++) printf("0");
        for(j=i+1;j<b-1;j++) printf("1");
        if(i==1) y=1;
        if(i==0 && x==m) printf("1");
        else printf("%d",((y&m) || x==m)?1:0);
        printf("\n");
        y*=2;
    }
    for(i=0;i<b;i++) printf("0");
    printf("\n");

    return ;
}
int main (void)
{
    int i,t;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%lld",&t);
    for(i=0;i<t;i++){
        scanf("%lld %lld",&b,&m);
        printf("Case #%d: ",i+1);
        solve();
    }

    return 0;
}
