#include <stdio.h>
int mark[2000006],True;
int ten[]={1,10,100,1000,10000,100000,1000000,10000000};
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int t,a,b,n,m,i,len,res;
    scanf("%d",&t);
    for(int cc=1;cc<=t;++cc){
        scanf("%d%d",&a,&b);
        for(len=0;;++len) if(a/ten[len]==0) break;
        res=0;
        for(n=a;n<b;++n){
            ++True;
            for(i=1;i<len;++i){
                m=(n%ten[i])*ten[len-i]+(n/ten[i]);
                if(n<m&&m<=b&&mark[m]!=True){
                    mark[m]=True;
                    ++res;
                }
            }
        }
        printf("Case #%d: %d\n",cc,res);
    }
    return 0;
}
