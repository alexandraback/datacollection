#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#define pb push_back
using namespace std;
typedef long long ll;
const double eps = 1e-6;
struct Node{
    double D,M;
    bool operator < (const Node &o) const
    {
        if(M == o.M) return D<o.D;
        return M<o.M;
    }
}nodes[20];
int np;
int main()
{
    freopen("C-small-1-attempt5.in","r",stdin);
    freopen("C-small-1-attempt5.out","w",stdout);
    int T,cas,n,H;
    double D,M;
    scanf("%d",&T);
    for(cas=1; cas<=T; cas++)
    {
        scanf("%d",&n);
        np = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%lf%d%lf",&D,&H,&M);
            for(int j=0; j<H; j++)
            {
                nodes[np].D = D;
                nodes[np++].M = M+j;
            }
        }
        printf("Case #%d: ",cas);
        if(np >= 3) continue;
        sort(nodes,nodes+np);

        if(np == 1 || np==2 && nodes[0].M == nodes[1].M) puts("0");
        else
        {
            if(1.0*nodes[1].D+360.0/nodes[1].M*nodes[0].M >= 360.0 - eps) puts("0");
            else
            {
                if(1.0*nodes[0].D + 360.0/nodes[0].M*nodes[1].M < 720.0-eps) puts("0");
                else if(1.0*nodes[1].D/(360.0/nodes[0].M-360.0/nodes[1].M)*360.0/nodes[0].M < 360.0-eps && ((1.0*nodes[1].D/(360.0/nodes[0].M-360.0/nodes[1].M)+(360.0-nodes[1].D)/(360.0/nodes[1].M))*360.0/nodes[0].M+nodes[0].D)<720.0-eps)
                {
                    puts("0");
                }
                else
                {
                    double t1 = (360.0-nodes[0].D)/(360.0/nodes[0].M);
                    double t2 = (360.0-nodes[1].D)/(360.0/nodes[1].M);
                    if(t1 < nodes[0].M && t2 < nodes[1].M) puts("0");
                    else puts("1");
                }
            }
        }
    }
    return 0;
}
