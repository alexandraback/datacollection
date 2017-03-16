#include <iostream>
#include <cstdio>
using namespace std;
const int mm=111;
int t,cs=0,flag;
long long i,a,b,tmp,num,rev,ans;
long long work(long long a)
{
    long long ret=0;
    while(a)
    {
        ret=ret*10+a%10;
        a/=10;
    }
    return ret;
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        cin>>a>>b;
        tmp=1;
        ans=0;
        flag=1;
        while(flag)
        {
            for(i=tmp;i<tmp*10;++i)
            {
                rev=work(i);
                num=i*tmp*10+rev;
                num=num*num;
                if(num==work(num)&&num>=a&&num<=b)++ans;
                num=i*tmp+rev%tmp;
                num=num*num;
                if(num==work(num)&&num>=a&&num<=b)++ans;
                if(num>b)
                {
                    flag=0;
                    break;
                }
            }
            tmp*=10;
        }
        printf("Case #%d: %lld\n",++cs,ans);
    }
    return 0;
}
