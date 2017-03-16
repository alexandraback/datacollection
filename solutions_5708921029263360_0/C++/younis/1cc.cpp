#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    freopen("C-small-attempt1.bin","r",stdin);
    freopen("output.txt","w",stdout);
    int t;scanf("%d",&t);
    int j,p,s,k;
    int a,b,c;
    for(int cas=1;cas<=t;cas++){
        scanf("%d%d%d%d",&j,&p,&s,&k);
        if(s>k)s=k;
        if(p>k)p=k;
        if(j>k)j=k;
        int mx=j*p*s;
        printf("Case #%d: %d\n",cas,mx);
        for(a=1;a<=j;a++)for(b=1;b<=p;b++)for(c=1;c<=s;c++)
            printf("%d %d %d\n",a,b,c);
    }
    return 0;
}
