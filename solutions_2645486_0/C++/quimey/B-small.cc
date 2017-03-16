#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)
#define all(v) v.begin(),v.end()

typedef long long int tint;

int dp[100][100];

int calc(int e,int n,vector<int> &v,int E,int R)
{
    if(n+1==v.size())return e*v[n];
    if(dp[e][n]==-1)
    {
        dp[e][n]=0;
        forn(i,e+1)
        {
            dp[e][n]=max(dp[e][n],i*v[n]+calc(min(e-i+R,E),n+1,v,E,R));
        }
    }
    return dp[e][n];
}

int main()
{
    int T;
    cin>>T;
    forn(t,T)
    {
        int E,R,N;
        cin>>E>>R>>N;
        vector<int>v(N);
        forn(i,100)forn(j,100)dp[i][j]=-1;
        forn(i,N)cin>>v[i];
        int res=calc(E,0,v,E,R);
        cout<<"Case #"<<t+1<<": "<<res<<endl;
    }
}
