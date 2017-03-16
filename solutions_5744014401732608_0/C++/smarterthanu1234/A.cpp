#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<climits>
#include<vector>
#include<stack>
#include<set>
#include<math.h>
using namespace std;
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define sint(i) scanf("%d",&i)
#define ss(s) scanf("%s",s)
#define pii pair<int,int>
#define mp(i,j) make_pair(i,j)
#define ll long long
#define MAX 1000000000
#define MOD 1000000007
#define vi vector<int>
#define vvi vector < vi >
#define pb(i) push_back(i);
#define tr(v,it) for(it=v.begin();it!=v.end();it++)
int main()
{
    freopen("test.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int i;
    int t;
    cin>>t;
    int test;
    long long l[55];
    l[1]=1;
    l[2]=1;
    FOR(i,3,50)
    l[i]=(1ll<<(i-2));
    FOR(test,1,t)
    {
        ll n,m,i,j;
        cin>>n>>m;
        if(m>l[n])
        cout<<"Case #"<<test<<": IMPOSSIBLE\n";
        else
        {
            int last;
            FOR(i,0,50)
            {
                if(m&(1ll<<i))
                {
                    last=i;
                }
            }
            int ans[n][n];
            FOR(i,0,n-1)
            {
                FOR(j,0,n-1)
                ans[i][j]=0;
            }
            FOR(i,0,last+1)
            {
                FOR(j,i+1,last+1)
                {
                    ans[i][j]=1;
                }
            }
            FOR(i,0,last)
            {
                if(m&(1ll<<i) && (i!=(n-2)))
                {
                    ans[i+1][n-1]=1;
                }
            }
            cout<<"Case #"<<test<<": POSSIBLE\n";
            FOR(i,0,n-1)
            {
                FOR(j,0,n-1)
                cout<<ans[i][j];
                cout<<"\n";
            }
        }
    }
    return 0;
}
