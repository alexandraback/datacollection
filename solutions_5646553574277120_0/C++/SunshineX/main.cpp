
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#define lson l,mid,u << 1
#define rson mid + 1,r,u << 1 | 1
#define ls u << 1
#define rs u << 1 | 1
#define mid ((l + r) >> 1)

using namespace std;

typedef long long ll;
int c,d,v;
int cnt[50],dp[50];
vector<int> b;
bool jd(vector<int> a)
{
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0; i<a.size(); i++)
    {
        int x=a[i];
        if(i && a[i]==a[i-1]) continue;
        memset(cnt,0,sizeof(cnt));
        for(int j=x; j<=v; j++)
        {
            if(dp[j]==0 && cnt[j-x]<c && dp[j-x]==1)
            {
                dp[j]=1;
                cnt[j]=cnt[j-x]+1;
            }
        }
    }
    for(int i=1; i<=v; i++) if(dp[i]==0) return false;
    return true;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out","w",stdout);
    int ct = 0,T;
    cin>>T;
    while(T--)
    {
        b.clear();
        cin>>c>>d>>v;
        for(int i=0; i<d; i++)
        {
            int x;
            cin>>x;
            b.push_back(x);
        }
        int ans=-1;
        if(jd(b)) ans=0;
        if(ans==-1)
            for(int p=1; p<=v; p++)
            {
                int comb=(1<<p)-1;
                while(comb<1<<v)
                {
                    vector<int> a;
                    for(int i=0; i<v; i++)
                        if(comb&(1<<i)) a.push_back(i+1);
                    for(int i=0; i<b.size(); i++)
                        a.push_back(b[i]);
                    sort(a.begin(),a.end());
//                    for(auto x:a)
//                    {
//                        cout<<' '<<x;
//                    }
//                    cout<<endl;
                    if(jd(a))
                    {
                        ans=p;
                        goto S;
                    }
                    int x=comb&-comb,y=comb+x;
                    comb=((comb & ~y)/x>>1)|y;
                }
            }
        S:printf("Case #%d: ",++ct);
        printf("%d\n",ans);
    }
    return 0;
}

