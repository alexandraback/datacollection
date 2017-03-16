#include<cstdio>
using namespace std;
int main(){
    int a,b,c,k,t,ans,i,j;
    scanf("%d",&t);
    for(c=1;c<=t;c++){
        scanf("%d%d%d",&a,&b,&k);
        ans=0;
        for(i=0;i<a;i++){
            for(j=0;j<b;j++){
                if((i&j)<k) ans++;
            }
        }
        printf("Case #%d: %d\n",c,ans);
    }
    return 0;
}
