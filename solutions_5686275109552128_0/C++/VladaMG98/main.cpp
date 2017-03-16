#include <bits/stdc++.h>
#define mid (lo+hi)/2
using namespace std;
const bool SUBMIT=true;
const int MAXN=1010;
int arr[MAXN];
int main()
{
    if(SUBMIT)
    {
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    }
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {scanf("%d",&arr[i]);}
        int ans=2000000010;
        for(int x=1;x<=1000;x++)
        {
            int tmp=0;
            for(int i=1;i<=n;i++)
            {
                tmp+=max(0,(arr[i]-1)/x);
            }
            ans=min(ans,tmp+x);
        }
        printf("Case #%d: %d\n",test,ans);
    }
    return 0;
}
