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
    FOR(test,1,t)
    {
        int j,p,s,k,l,limit;
        cin>>j>>p>>s>>limit;
        int v[1001];
        FOR(i,0,1000)
        v[i]=0;


        j--;
        p--;
        s--;
int num;
vector< pair< pair<int,int> ,int> > ans;
        FOR(i,0,j)
        {
            FOR(k,0,p)
            {
                FOR(l,0,s)
                {
                    num=(1<<i)+(1<<(k+3))+(1<<(l+6));
                    if(v[num])
                    continue;
                    else if(v[num^(1<<i)]>=limit)
                    continue;
                    else if(v[num^(1<<(k+3))]>=limit)
                    continue;
                    else if(v[num^(1<<(l+6))]>=limit)
                    continue;
                    else
                    {
                        ans.pb(mp(mp(i+1,k+1),l+1));
                        v[num]=1;
                        v[num^(1<<i)]++;
                        v[num^(1<<(k+3))]++;
                        v[num^(1<<(l+6))]++;
                    }
                }
            }
        }
        cout << "Case #" << (test) << ": " << ans.size() << endl;
        FOR(i,0,ans.size()-1)
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<"\n";
    }
    return 0;
}
