#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
long long Gcd(long long x, long long y)
{
    if(y==0) return x;
    return  Gcd(y, x%y);
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int caseno=1; caseno<=t; caseno++)
    {
        long long int p,q;
        scanf("%lld/%lld",&p,&q);

        long long gcd = Gcd(p,q);
        p/=gcd, q/=gcd;
        //printf("%lld/%lld\n",p,q);

        bool flag = true;
        long long tmp = q;
        while(tmp)
        {
            if(tmp!=1 && tmp%2==1){
                flag = false;
                break;
            }
            else tmp/=2;
        }
        if(!flag){
            printf("Case #%d: impossible\n",caseno);
        }
        else{
            double num = (double)p/(double)q;
            int cnt=0;
            while(num < 1)
            {
                num *=2;
                cnt++;
            }
            printf("Case #%d: %d\n",caseno, cnt);
        }
    }

    return 0;
}
