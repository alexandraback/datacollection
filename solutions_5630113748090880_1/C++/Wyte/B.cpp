//#define WYTE
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
    cin.tie(nullptr);
    int t,ii,n,i,j,x;
    cin>>t;
    for(ii=1;ii<=t;ii++)
    {
        int cnt[2501]={};
        cin>>n;
        for(i=0;i<2*n-1;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>x;
                cnt[x]++;
            }
        }
        vi ans;
        for(i=1;i<=2500;i++)
        {
            if(cnt[i]%2)ans.emplace_back(i);
        }
        sort(ALL(ans));
        cout<<"Case #"<<ii<<":";
        for(i=0;i<n;i++)
        {
            cout<<" "<<ans[i];
        }
        cout<<"\n";
    }
}
