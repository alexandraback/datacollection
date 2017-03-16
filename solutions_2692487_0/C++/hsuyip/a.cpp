#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<utility>
#define ll long long
using namespace std;
int a[1000010];
int main()
{
#ifdef TEST
freopen("in.txt","r",stdin);
freopen("outa.txt","w",stdout);
#endif
    int i,j,k,t,T,m,n,ans,temp,temp1;
    ll sum;
    scanf("%d",&T);
    t=1;
    while(t<=T)
    {
        scanf("%d %d",&m,&n);
        for(i=0;i<n;i++)
        scanf("%d",a+i);

        sort(a,a+n);
        sum=m;

        ans=n;
        temp=0;

        if(sum>1LL)
        for(i=0;i<n;i++)
        {
            while(sum<=a[i])
            {
                sum+=sum-1LL;
                temp++;
            }
            sum+=a[i];
            temp1=temp+n-i-1;
            ans=min(ans,temp1);
            //cout<<sum<<" ";
        }

        printf("Case #%d: %d\n",t++,ans);
    }

return 0;
}
