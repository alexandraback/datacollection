#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 200+5, MAXM = (1<<20)+5;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
int T, N;
//int main()
//{
//    freopen("input.txt", "r", stdin);
////    freopen("output.txt", "w", stdout);
//    scanf("%d", &T);
//    for (int cas = 1; cas <= T; cas++)
//    {
//        printf("Case #%d:\n", cas);
//        printf("\n");
//    }
//    return 0;
//}

int g[1010][1010];
int n,m,x = 2;
int v[1010];
int dist[1010][20];
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &n);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                g[i][j]=INF;
        for (int u = 1; u <= n; u++)
        {
            int c, v;
            scanf("%d", &c);
            for (int j = 1; j <= c; j++)
            {
                scanf("%d", &v);
                g[u][v] = 1;
            }
        }
        bool flag = 0;
        for (int s = 1; s <= n && !flag; s++)
        {
            for (int i=1;i<=n;i++){
                v[i]=0;
                for (int j=0;j<=x;j++)
                    dist[i][j]=INF;
            }
            dist[s][0]=0;
            dist[0][0]=INF;
            while (1){
                int k=0;
                for (int i=1;i<=n;i++)
                    if (v[i]<x && dist[i][v[i]]<dist[k][0])
                        k=i;
                if (k==0) break;
                if (k==n && v[n]==x-1) break;
                for (int i=1;i<=n;i++){
                    if (v[i]<x && dist[k][v[k]]+g[k][i]<dist[i][x]){
                        dist[i][x]=dist[k][v[k]]+g[k][i];
                        for (int j=x;j>0;j--)
                            if (dist[i][j]<dist[i][j-1])
                                swap(dist[i][j],dist[i][j-1]);
                    }
                }
                v[k]++;
            }
            for (int v = 1; v <= n; v++)
            {
//                printf("%d-%d:%d\n", s, v, dist[v][x-1]);
                if (dist[v][x-1] < INF)
                {
                    flag = 1;
//                    break;
                }
            }
        }
        printf("Case #%d: ", cas);
        printf("%s", flag ? "Yes" : "No");
        printf("\n");
    }
    return 0;
}
