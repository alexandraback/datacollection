#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case #%d: ", cas++);
#define EPS 1e-9
#define MAX 100010
#define ll long long
#define INF (1<<30)
#define pii pair<int, int>
#define MP make_pair
int xx[] = {1,1,0,-1,-1,-1,0,1}, yy[] = {0,1,1,1,0,-1,-1,-1}; //eight direction

int udx[] = {-1, 1}, udy[] = {0, 0};
int lrx[] = {0, 0}, lry[] = {-1, 1};

using namespace std;

int grid[105][105];
bool col[105][105];
int n, m;

bool bfs(int x, int y, int val)
{
    memset(col, false, sizeof col);
    int i, j, nx, ny, sx, sy;
    queue<int>Q;
    Q.push(x); Q.push(y);
    col[x][y]=true;
    int cnt=0;
    while(!Q.empty())
    {
        sx = Q.front(); Q.pop();
        sy = Q.front(); Q.pop();
        cnt++;
        for(i=0;i<2;i++)
        {
            nx = sx+udx[i], ny = sy+udy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(grid[nx][ny]>val) continue;
            if(col[nx][ny]) continue;
            col[nx][ny] = true;
            Q.push(nx), Q.push(ny);
        }
    }
    if(cnt==n) return true;
    cnt=0;
    while(!Q.empty()) Q.pop();
    Q.push(x), Q.push(y);
    memset(col, false, sizeof col);
    col[x][y]=true;
    while(!Q.empty())
    {
        sx = Q.front(); Q.pop();
        sy = Q.front(); Q.pop();
//        cout<<"niche "<<sx<<" "<<sy<<" "<<val<<endl;
        cnt++;
        for(i=0;i<2;i++)
        {
            nx = sx+lrx[i], ny = sy+lry[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(grid[nx][ny]>val) continue;
            if(col[nx][ny]) continue;
            col[nx][ny] = true;
            Q.push(nx), Q.push(ny);
        }
    }
    if(cnt==m) return true;
    return false;
}

int main()
{
    freopen("small.in", "r", stdin);
    freopen("small.out", "w", stdout);
    int t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
        int i, j, k, now, val;
        scanf("%d%d", &n, &m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d", &grid[i][j]);

        int ok=1;
        for(val=1;val<=100;val++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    if(grid[i][j]==val)
                    {
                        now = bfs(i, j, val);
//                        cout<<"val "<<val<<" "<<i<<" "<<j<<" "<<now<<endl;
                        if(now==false)
                            ok=0;

                    }
                }
            }
        }
        csprnt;
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

