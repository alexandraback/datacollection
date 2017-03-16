#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long

char a[1010];
int cnt[1010];

int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        int smax;
        scanf("%d",&smax);

        scanf("%s",a);

        for(int i=0;i<=smax;i++)
            cnt[i]=a[i]-'0';

        int ans=-1;
        int lo=0,hi=smax;

        for(int i=lo;i<=hi;i++)
        {
            cnt[0]+=i;

            int sum=cnt[0];
            bool flag=0;
            for(int j=1;j<=smax;j++)
            {
                if(sum>=j)
                    sum+=cnt[j];
                else
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                ans=i;
                break;
            }
            cnt[0]-=i;
        }
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
