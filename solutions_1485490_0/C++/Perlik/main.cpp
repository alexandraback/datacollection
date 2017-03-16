#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair <ll,ll> pll;
int n,m;
pll a[3],rb[110],b[110];
int get[3],cnt[3];
ll ans=0;
void gen(int pos)
{
    if (pos==n)
    {
        ll cur=0;
        int p=0;
        for(int i=0;i<m;i++)
            b[i]=rb[i];
        for(int i=0;i<n;i++)
        {
            int add=0;
            ll left=a[i].first;
            while (add<get[i] && p<m)
            {
                if (b[p].second==a[i].second)
                {
                    if (b[p].first)
                        add++;
                    ll cost=min(b[p].first,left);
                    cur+=cost;
                    left-=cost;
                    b[p].first-=cost;
                    if (!left)
                        break;
                }
                p++;
            }
            if (add<get[i])
            {
                cur=0;
                break;
            }
        }
        ans=max(ans,cur);
    } else
        for(int i=0;i<=cnt[pos];i++)
        {
            get[pos]=i;
            gen(pos+1);
            get[pos]=0;
        }
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("answer.txt","w",stdout);
    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].first>>a[i].second;
            cnt[i]=0;
        }
        for(int i=0;i<m;i++)
            cin>>rb[i].first>>rb[i].second;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if (a[i].second==rb[j].second)
                    cnt[i]++;
        ans=0;
        gen(0);
        cout<<"Case #"<<q<<": "<<ans<<endl;
    }
    return 0;
}
