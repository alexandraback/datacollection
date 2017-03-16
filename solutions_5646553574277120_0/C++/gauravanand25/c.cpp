#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX

int dp[31];
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;  cin>>t;
    for( int tt=1; tt<=t; ++tt ) {
        int c,d,v,ans=0,x;  cin>>c>>d>>v;
        vector<int> a; a.resize(d);   for( int i=0; i<d; ++i ) cin>>a[i];
        bool flag=false;
        do {
            memset(dp,0,sizeof(dp));        dp[0]=1;
            for( int i=0; i<a.size(); ++i ) {
                for( int k=v; k>=a[i]; --k ) {
                    dp[k]|=dp[k-a[i]];
                }
            }
            flag=false;
            for( int i=1; i<=v; ++i )
                if( dp[i]==0 ) {
                    ans++;
                    x=i;
                    flag=true;
                    break;
                }
            //cout<<"add "<<x<<endl;
            a.push_back(x); sort(a.begin(),a.end());
            //for( int i=1; i<=v; ++i ) if( dp[i]==0 ) cout<<i<<' ';  cout<<endl;
        } while(flag);
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
