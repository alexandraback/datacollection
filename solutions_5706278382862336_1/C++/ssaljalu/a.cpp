#include<stdio.h>

int t;
long long p,q,ans;
long long pow[41];

int main() {
    long long a,b,r;
    int i;
    pow[0]=1;
    for(i=1;i<=40;i++)
        pow[i]=pow[i-1]<<1;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        scanf("%I64d/%I64d",&p,&q);
        a=q;b=p;
        while(b){
            r=a%b;
            a=b;
            b=r;
        }
        p/=a;q/=a;
        a=q;
        while(!(a&1)) a>>=1;
        if (a!=1){
            printf("Case #%d: impossible\n",tc);
            continue;
        }
        for(i=40;i>=0;i--)
            if(p&pow[i])break;
        r=q/pow[i];
        for(i=40;i>=0;i--)if(r==pow[i])break;
        ans=i;
        printf("Case #%d: %I64d\n",tc,ans);
    }
}
