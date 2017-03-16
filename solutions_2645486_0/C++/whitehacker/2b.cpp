#include<fstream>
#include<algorithm>
#include<iostream>
using namespace std;

int e,r,n,ans;
int v[100];
int dp[11][11];
void solve(int pos,int E,int gain)
{
    if(pos==n)
    {
        //cout<<E<<"\n";
        ans=max(ans,gain);
        return ;
    }
    for(int i=0;i<=E;i++)
    {
        if((E-i+r)<=e)
        solve(pos+1,(E-i)+r,gain+v[pos]*i);
        else
        solve(pos+1,e,gain+v[pos]*i);
    }
return ;
}
int main()
{
freopen("B-small-attempt0.in","r",stdin);
freopen("output.txt","w",stdout);
int test;
cin>>test;
for(int j=1;j<=test;j++)
{

    cin>>e>>r>>n;
    for(int i=0;i<n;i++)
    cin>>v[i];
    ans=0;
    solve(0,e,0);
    cout<<"Case #"<<j<<": "<<ans<<endl;

}

return 0;
}
