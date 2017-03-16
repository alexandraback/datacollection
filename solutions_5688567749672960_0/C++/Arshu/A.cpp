#include<bits/stdc++.h>
using namespace std;

int X=0,t,ans[1000005];

int rev(int x)
{
    int temp=0;
    while(x>0)
    {
        temp=temp*10 + x%10;
        x=x/10;
    }
    return temp;
}

void solve()
{
    int i;
    for(i=0;i<=20;i++)
        ans[i]=i;

    for(i=21;i<=1000002;i++)
    {
        if(i%10==0)
        {
            ans[i]=ans[i-1]+1;
        }
        else if(rev(i)<i)
        {
            ans[i]=min(ans[i-1],ans[rev(i)])+1;
        }
        else
            ans[i]=ans[i-1]+1;
    }
}
int n;
int main()
{
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    solve();
    scanf("%d",&t);
    while(t--)
    {X++;
        scanf("%d",&n);
        printf("Case #%d: %d\n",X,ans[n]);
    }
}
