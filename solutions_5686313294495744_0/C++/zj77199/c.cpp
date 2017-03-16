#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
using namespace std;
int T,t,n,cnt,ans;
string tmp;
map<string,int>mp;
int a[20],b[20];
void _solve(int mask)
{
    int t=mask,c=0;
    while(t)
    {
        c+=t&1;
        t>>=1;
    }
    if(c<=ans)return;
    int i,j;
    for(i=0;i<n;++i)
        if((1<<i)&mask)
        {
            bool f1=0,f2=0;
            for(j=0;j<n;++j)
            {
                if((1<<j)&mask)
                    continue;
                if(a[j]==a[i]&&b[j]==b[i])
                    return;
                if(a[j]==a[i])
                    f1=1;
                if(b[j]==b[i])
                    f2=1;
            }
            if(!f1||!f2)
                return;
        }
    ans=c;
}
void solve()
{
    int mask;
    for(mask=1;mask<(1<<n);++mask)
        _solve(mask);
}
int main()
{
    cin>>T;
    for(t=1;t<=T;++t)
    {
        mp.clear();
        cnt=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            cin>>tmp;
            if(mp.find(tmp)!=mp.end())
                a[i]=mp[tmp];
            else
            {
                mp[tmp]=++cnt;
                a[i]=cnt;
            }
            cin>>tmp;
            if(mp.find(tmp)!=mp.end())
                b[i]=mp[tmp];
            else
            {
                mp[tmp]=++cnt;
                b[i]=cnt;
            }
        }
        ans=0;
        solve();
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
