#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int num[105];
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t,Case=0;
    scanf("%d",&t);
    while(t--)
    {
        int a,n;
        scanf("%d%d",&a,&n);
        for(int i=0;i<n;++i)
            scanf("%d",&num[i]);
        sort(num,num+n);
        int ans=n,ind=0;
        if(a!=1)
        {
            for(int i=0;i<n;++i)
            {
                if(a>num[i])a+=num[i];
                else
                {
                    ans=min(ans,n-i+ind);
                    while(a<=num[i])a+=a-1,++ind;
                    a+=num[i];
                }
            }
            ans=min(ans,ind);
        }
        printf("Case #%d: %d\n",++Case,ans);
    }
    return 0;
}
