#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long long b,t,m,ans[55][55],dp[55];

void display() {
    cout<<"POSSIBLE"<<endl;
    For(i,0,b) {
        For(j,0,b) cout<<ans[i][j];
        cout<<endl;
    }
}

int main( ){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    For(cas,1,1+t) {
        cout<<"Case #"<<cas<<": ";
        cin>>b>>m;
        if((1ll<<(b-2))<m) {
            cout<<"IMPOSSIBLE"<<endl;continue;
        }
        reset(ans,0);
        reset(dp,0);
        m--;
        For(i,0,b-1) ans[i][b-1]=1;
        dp[0]=1;
        For(i,1,b-1) {
            for(int j=i-1;j>=0;j--) if(m>=dp[j]) {
                m-=dp[j];
                dp[i]+=dp[j];
                ans[j][i]=1;
            }
        }
        display();
    }
}
