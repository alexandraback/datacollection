#include<bits/stdc++.h>
#define X first
#define Y second
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define ALL(x) (x).begin(),(x).end()
#define INIT(x,y) memset((x),(y),sizeof(x))
#define PQ priority_queue
#define IT iterator
#define INF 1e9
#define EPS 1e-9
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,ii,r,c,w,ans;
    cin>>t;
    for(ii=1;ii<=t;ii++)
    {
        cin>>r>>c>>w;
        ans=c/w+(w-1);
        if(c%w)
        {
            ans++;
        }
        if(r!=1)
        {
            ans+=(r-1)*(c/w);
        }
        cout<<"Case #"<<ii<<": "<<ans<<"\n";
    }
}
