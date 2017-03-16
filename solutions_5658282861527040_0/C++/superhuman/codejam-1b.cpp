#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output-1.out","w",stdout);
    int t,c;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        int a,b,k,ans=0;
        scanf("%d%d%d",&a,&b,&k);
        ans=a*b;
        //cout<<"ans="<<ans<<endl;
        for(int i=k;i<=a-1;i++)
                for(int j=k;j<=b-1;j++)
                if((i&j)>=k)
                {
                //cout<<"i="<<i<<" j="<<j<<" i&j="<<(i&j)<<endl;
                ans--;
                }
        printf("Case #%d: %d\n",c,ans);
    }
    return 0;
}
