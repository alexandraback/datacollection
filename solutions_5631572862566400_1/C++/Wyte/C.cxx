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

int chk[1005];
vi v[1005];
int dfs(int node,int lv)
{
    if(chk[node])return 0;
    chk[node]=1;
    int i,ans=lv;
    for(i=0;i<v[node].size();i++)
    {
        ans=max(ans,dfs(v[node][i],lv+1));
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,ii,n,i,bff[1005],line,circle,left,right,node,cnt,iter[1005];
    cin>>t;
    for(ii=1;ii<=t;ii++)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            v[i].clear();
            chk[i]=0;
            iter[i]=0;
        }
        line=circle=0;
        for(i=1;i<=n;i++)
        {
            cin>>bff[i];
            v[bff[i]].emplace_back(i);
        }
        for(i=1;i<=n;i++)
        {
            if(!chk[i]&&i==bff[bff[i]])
            {
                /* type=>line
                 *
                 *  \            /
                 *   \          /
                 *    \        /
                 *  --- O -- O ---
                 *    /        \
                 *   /          \
                 *  /            \
                 *
                 * line += max(left) + max(right)
                */
                chk[bff[i]]=1;
                left=dfs(i,1);
                chk[bff[i]]=0;
                right=dfs(bff[i],1);
                line+=left+right;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(chk[i])continue;
            node=i;
            cnt=1;
            while(!chk[node])
            {
                chk[node]=cnt;
                iter[node]=i;
                node=bff[node];
                cnt++;
            }
            if(iter[node]==i)
            {
                circle=max(circle,cnt-chk[node]);
            }
        }
        cout<<"Case #"<<ii<<": "<<max(line,circle)<<"\n";
    }
}
