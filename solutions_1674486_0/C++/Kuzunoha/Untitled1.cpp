#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> v[1005];

vector<int> topo;
bool topoChecked[1005];
void topoSort(int u)
{
    int n=v[u].size(), c;
    for(c=0;c<n;c++) if(!topoChecked[v[u][c]]) topoSort(v[u][c]);
    topo.push_back(u);
}

int path[1005];
bool checked[1005];

queue<int> q;

int main()
{
    int T,n,m,a,b,c,d,u;
    bool isDiamond, diamondFound;
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++)
    {
        scanf("%d",&n);
        for(c=1;c<=n;c++) v[c].clear();
        for(c=1;c<=n;c++)
        {
            scanf("%d",&a);
            while(a--)
            {
                scanf("%d",&b);
                v[b].push_back(c);
            }
        }
        //toposort
        topo.clear();
        for(c=1;c<=n;c++) topoChecked[c] = false;
        for(c=1;c<=n;c++) if(!topoChecked[c]) topoSort(c);
        reverse(topo.begin(),topo.end());
        //for every node in topo, cek if having diamond
        diamondFound = false;
        for(d=0;d<topo.size();d++)
        {
            for(c=1;c<=n;c++)
            {
                path[c] = 0;
                checked[c] = false;
            }
            path[topo[d]] = 1;
            q.push(topo[d]);
            while(!q.empty())
            {
                u = q.front();
                q.pop();
                if(checked[u]) continue;
                checked[u] = true;
                m = v[u].size();
                for(c=0;c<m;c++)
                {
                    path[v[u][c]] += path[u];
                    q.push(v[u][c]);
                }
            }
            isDiamond = false;
            for(c=1;c<=n;c++) if(path[c]>=2)
            {
                isDiamond = true;
                break;
            }
            if(isDiamond)
            {
                diamondFound = true;
                break;
            }
        }
        if(diamondFound) printf("Case #%d: Yes\n",tc);
        else printf("Case #%d: No\n",tc);
    }
    return 0;
}
