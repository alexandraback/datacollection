#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long LL;

#define FOR(i,a,b) for(register int i=a;i<b;i++)
#define FORE(i,a,b) FOR(i,a,b+1)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define mod 1000000007
#define MP make_pair
#define INF mod

int main()
{
#ifndef ONLINE_JUDGE
    freopen("B-small-attempt1.in","r",stdin);
    freopen("a.out","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    int t,tt,n;
    cin>>t;
    FOR(tt,1,t+1)
    {
        cout<<"Case #"<<tt<<": ";
        cin>>n;
        string s[n];
        REP(i,n) cin>>s[i];
        int a[n];
        REP(i,n) a[i]=i;
        LL ans=0;
        do
        {
            bool f=1;
            int x[27];
            fill(x,x+27,-1);
            char l=-1;
            REP(i,n) REP(j,s[a[i]].length())
            {
                if(l!=s[a[i]][j] and x[s[a[i]][j]-'a']!=-1) {f=0;break;}
                l=s[a[i]][j];
                x[s[a[i]][j]-'a']=i;
            }
            if(f) ans++;
            //REP(i,n) cout<<s[i]<<' ';cout<<f<<endl;
        }
        while(next_permutation(a,a+n));
        cout<<ans%mod<<endl;
    }
    return 0;
}
