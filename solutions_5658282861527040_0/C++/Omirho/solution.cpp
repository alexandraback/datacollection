#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,n,0)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a,b) for(int i=a;i>=0;i--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf mod

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("a.in","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    int t,a,b,k;
    cin>>t;
    REP(i,t)
    {
        cout<<"Case #"<<i+1<<": ";
        int ans=0;
        cin>>a>>b>>k;
        REP(j,a)
        {
            REP(c,b)
            {
                int temp = c&j;
                if(temp < k)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
