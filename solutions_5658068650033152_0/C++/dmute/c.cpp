#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int maxn = 1005;
const int X[4]={0,0,1,-1},Y[4]={1,-1,0,0};
int n, m, k;
bool stone[maxn][maxn], vis[maxn][maxn];
void spread(int x, int y){
    vis[x][y] = true;
    for (int i = 0; i < 4; i ++){
        int nx = x + X[i], ny = y + Y[i];
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if (vis[nx][ny] || stone[nx][ny]) continue;
        spread(nx, ny);
    }
}
int solvesmall(){
     scanf("%d%d%d",&n,&m,&k);
     int tot = n * m;
     
     int ans = k;
     for (int st = 0; st < (1 << tot); st ++){
         int cnt = 0, tmp = 0;
      // if (st % 100000 == 0)  printf("st=%d 1<<tot=%d\n",st, 1 << tot);
         for (int i = 1; i <= n; i ++)
           for (int j = 1; j <= m; j ++){
              stone[i][j] = (st >> cnt) & 1;
              cnt ++;
              if (stone[i][j]) tmp ++;
              vis[i][j]=0;
           }
         for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
               if (i == 1 || j == 1 || i == n || j == m)
                  if (!vis[i][j] && !stone[i][j]) spread(i,j);
         int cant=0;
         for (int i = 1; i <= n; i ++)
           for (int j =1; j <= m; j ++)
             if (!vis[i][j])cant++;
         if (cant>=k)ans= min(ans, tmp);
              
     }
     return ans;
}
int main(){
    freopen("cc.in","r",stdin);
    freopen("c.out","w",stdout);
    int tst;
    scanf("%d",&tst);
    for (int t = 1; t <= tst; t ++)
       printf("Case #%d: %d\n",t, solvesmall());
    return 0;
}
