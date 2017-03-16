#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<map>
#include<utility>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;
#define MAXSIZE 200
int dist[MAXSIZE+6][MAXSIZE+6][MAXSIZE+6];
int xdir[] = {0,-1,0,1};
int ydir[] = {-1,0,1,0};
struct node
{
    int x,y,d;
    node() {}
    node(int xx, int yy, int dd) {x=xx, y=yy, d=dd;}
};
queue < node > Q;
int bfs(int X, int Y)
{
    while(!Q.empty()) Q.pop();
    Q.push(node(100,100,0));
    memset(dist, -1, sizeof(dist));
    dist[100][100][0] = -1;
    node now;
    int p,x,y,d;
    while(!Q.empty())
    {
        now = Q.front();
        Q.pop();
        //printf("%d %d %d : %d\n", now.x,now.y,now.d,dist[now.x][now.y][now.d]);
        if (now.x==X && now.y==Y) return now.d;
        d = now.d + 1;
        for (p=0; p<4; ++p)
        {
            x = now.x + d*xdir[p];
            y = now.y + d*ydir[p];
            if (x<0 || y<0 || x>MAXSIZE || y>MAXSIZE) continue;
            if (dist[x][y][d] == -1)
            {
                dist[x][y][d] = p;
                Q.push(node(x,y,d));
            }
        }
    }
}
char rmap[] = {'W','S','E','N'};
void print_path(int x, int y, int d)
{
    if (d==0) return;
    int p = dist[x][y][d];
    print_path(x-d*xdir[p], y-d*ydir[p], d-1);
    putchar(rmap[p]);
}
int main()
{
    //freopen("data.txt", "r", stdin);
    freopen("inputB.txt", "r", stdin);
    freopen("outputB.txt", "w", stdout);
    int t,T;
    int X,Y;
    scanf("%d", &T);
    for (t=1; t<=T; ++t)
    {
        scanf("%d %d", &Y, &X);
        X += 100, Y += 100;
        printf("Case #%d: ", t);
        print_path(X,Y,bfs(X,Y));
        puts("");
    }
    return 0;
}
