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

LL gcd(LL a, LL b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    LL a,b,g;
    int t,tt;
    char c;
    cin>>t;
    string s;
    FOR(tt,1,t+1)
    {
        cout<<"Case #"<<tt<<": ";
        getline(cin,s,'/');
        cin>>b;
        stringstream(s)>>a;
        //cin>>a>>b;
        //cout<<a<<' '<<b<<endl;
        g=gcd(a,b);
        a/=g;b/=g;
        if(a>b) cout<<"impossible\n";
        else
        {
            bool f=0;
            LL ii;
            for(ii=1;ii<b;ii<<=1);
            if(ii!=b) {cout<<"impossible\n";continue;}
            REP(i,40)
            {
                if(b==1) {cout<<i<<endl;f=1;break;}
                a<<=1;
                if(a>=b) {cout<<i+1<<endl;f=1;break;a-=b;}

                g=gcd(a,b);
                a/=g;b/=g;
            }
            if(!f) cout<<"impossible\n";
        }

    }
    return 0;
}
