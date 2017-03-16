#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

#define FOR(i,v)    for (__typeof(v.begin()) i = v.begin(); i != v.end(); i++)

using namespace std;

vector <int> fa[1010];
int nxt[1010];
map <int,bool> M;
vector <int> biP;

int dfs(int x, int ban)
{
    if (M[x]) return 0;
    M[x] = true;
    int ans = 0;
    FOR(t, fa[x])
    {
        if (M[*t]==false && (*t != ban))
            ans = max(ans, dfs(*t, ban));
    }
    return ans + 1;
}

int main()
{
    freopen("example.in","r",stdin);
    freopen("ans.out","w",stdout);
    int T, n;
    scanf("%d",&T);
    for (int _ = 1; _ <= T; _++)
    {
        biP.clear();
        for (int i=1;i<=1000;i++)
            fa[i].clear();
        memset(nxt,0,sizeof nxt);

        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&nxt[i]);
            fa[nxt[i]].push_back(i);
        }
        for (int i=1;i<=n;i++)
            if (nxt[nxt[i]] == i)
                biP.push_back(i);

        int ansP1 = 0;
        for (int i=1;i<=n;i++)
        {
            //printf("%d: ",i);
            M.clear();
            int temp=i;
            int step=1;
            M[temp] = true;
            while (!M[nxt[temp]])
            {
              //  printf("%d,",nxt[temp]);
                step++;
                temp = nxt[temp];
                M[temp] = true;
            }
            if (nxt[temp] == i)
                if (step > ansP1)
                {
                    ansP1 = step;
                    //printf(" %d",nxt[temp]);
                }
            //printf("\n");
        }
      //  printf("ansP1: %d\n",ansP1);

        M.clear();
        int ansP2 = 0;
        int anstemp;
        int xx,yy;
        FOR (t,biP)
        {
            int x = *t;
            int y = nxt[*t];
            xx = dfs(x, y);
            yy = dfs(y, x);
            //printf("%d: %d; %d: %d\n",x,xx,y,yy);
            ansP2 += xx + yy;
        }

        printf("Case #%d: %d\n", _, max(ansP1,ansP2));
    }
}
