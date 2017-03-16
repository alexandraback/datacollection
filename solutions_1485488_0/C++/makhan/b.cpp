#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int ceil[101][101];
int floor[101][101];
bool reach[101][101];
unsigned long long int reached[101][101];
int h,n,m;
bool check(int x, int y, int nx, int ny)
{
    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        return 0;
    int maxv = max(max(floor[x][y], h), floor[nx][ny]);
    if (ceil[nx][ny]-maxv < 50)
        return 0;
    if (ceil[x][y]-floor[nx][ny] < 50)
        return 0;
    if (reach[nx][ny])
        return 0;
    return 1;
}
bool dfs(int x, int y)
{
    reach[x][y] = true;
    if (check(x,y,x+1,y))
        dfs(x+1, y);
    if (check(x,y,x-1,y))
        dfs(x-1, y);
    if (check(x,y,x,y+1))
        dfs(x, y+1);
    if (check(x,y,x,y-1))
        dfs(x, y-1);
}
class node
{
    public:
        int x, y;
        unsigned long long int time;
        node(int a, int b, int c) : x(a), y(b), time(c) {};
        bool operator<(const node &b) const {
            return time > b.time;
        }

};
priority_queue< node > Q;

void swim(int x, int y, int nx, int ny, int t)
{

    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        return;
    int maxv = max(floor[x][y], floor[nx][ny]);
    if (ceil[nx][ny]-maxv < 50)
        return;
    if (ceil[x][y]-floor[nx][ny] < 50)
        return;

    int level = h - t;
    if (ceil[nx][ny]-level < 50)
    {
        t += 50-(ceil[nx][ny]-level);
        level = h - t;
    }

    if (level-floor[x][y] >= 20)
        Q.push(node(nx, ny, t+10));
    else
        Q.push(node(nx, ny, t+100));
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ti=1; ti<=t; ti++)
    {
        scanf("%d %d %d",&h, &n, &m);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                scanf("%d",&ceil[i][j]);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                scanf("%d",&floor[i][j]);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
            {
                reach[i][j] = false;
                reached[i][j] = 1000000000000L;
            }
        dfs(0,0);
        printf("Case #%d: ",ti);
        if (reach[n-1][m-1])
            printf("0.0\n");
        else
        {
            for (int i=0; i<n; i++)
                for (int j=0; j<m; j++)
                    if (reach[i][j])
                    {
                        Q.push(node(i,j,0));
                    }
            while (!Q.empty())
            {
                node tmp = Q.top();
                Q.pop();
                if (tmp.x == n-1 && tmp.y == m-1)
                {
                    printf("%.1lf\n",double(tmp.time)/10.0);
                    break;
                }
                if (tmp.time < reached[tmp.x][tmp.y])
                {
                    reached[tmp.x][tmp.y] = tmp.time;
                    swim(tmp.x, tmp.y, tmp.x+1, tmp.y, tmp.time);
                    swim(tmp.x, tmp.y, tmp.x-1, tmp.y, tmp.time);
                    swim(tmp.x, tmp.y, tmp.x, tmp.y+1, tmp.time);
                    swim(tmp.x, tmp.y, tmp.x, tmp.y-1, tmp.time);
                }
            }
        }
        while (!Q.empty())
            Q.pop();
    }
}
