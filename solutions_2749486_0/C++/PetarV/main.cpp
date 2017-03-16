/*
 Petar 'PetarV' Velickovic
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <time.h>
#define LIMIT 1000000
using namespace std;
typedef long long lld;
char buffer[LIMIT], * pos = buffer + LIMIT;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int mark[205][205][505];
int parent[205][205][505];
int t, x, y;
int dd = 100;

inline int BFS(int id)
{
    queue<int> bfs_qX;
    queue<int> bfs_qY;
    queue<int> movz;
    bfs_qX.push(dd);
    bfs_qY.push(dd);
    movz.push(0);
    while (!bfs_qX.empty())
    {
        int xt = bfs_qX.front();
        int yt = bfs_qY.front();
        int mt = movz.front();
        //printf("Exploring point: (%d, %d) after %d moves.\n",xt, yt, mt);
        bfs_qX.pop();
        bfs_qY.pop();
        movz.pop();
        mark[xt][yt][mt] = id;
        if (xt == x && yt == y) return mt;
        for (int i=0;i<4;i++)
        {
            int xt1 = xt + dx[i]*(mt+1);
            int yt1 = yt + dy[i]*(mt+1);
            if (xt1 < 0 || xt1 > 200 || yt1 < 0 || yt1 > 200 || mt > 500) continue;
            if (mark[xt1][yt1][mt+1] != id)
            {
                bfs_qX.push(xt1);
                bfs_qY.push(yt1);
                movz.push(mt+1);
                mark[xt1][yt1][mt+1] = id;
                parent[xt1][yt1][mt+1] = i;
            }
        }
    }
    return -1;
}

char convert(int xx)
{
    if (xx == 0) return 'E';
    if (xx == 1) return 'N';
    if (xx == 2) return 'W';
    if (xx == 3) return 'S';
    return 'X';
}

struct Treble
{
    int a, b, c;
    Treble() {}
    Treble(int a, int b, int c)
    {
        this -> a = a;
        this -> b = b;
        this -> c = c;
    }
    bool operator <(const Treble &t) const
    {
        if (a != t.a) return (a<t.a);
        if (b != t.b) return (b<t.b);
        return (c<t.c);
    }
};

int main()
{
    freopen("/Users/PetarV/CodeJam/B-small-attempt1.in.txt","r",stdin);
    freopen("/Users/PetarV/CodeJam/B-outttt.txt","w",stdout);
    scanf("%d",&t);
    for (int f=1;f<=t;f++)
    {
        
        scanf("%d%d",&x,&y);
        x += dd;
        y += dd;
        int movez = BFS(f);
        stack<char> S;
        int xcurr = x, ycurr = y;
        while (movez > 0)
        {
            S.push(convert(parent[x][y][movez]));
            int leftmov = movez*dx[parent[x][y][movez]];
            int rightmov = movez*dy[parent[x][y][movez]];
            movez--;
            x -= leftmov;
            y -= rightmov;
        }
        printf("Case #%d: ",f);
        while (!S.empty()) { printf("%c",S.top()); S.pop(); }
        printf("\n");
    }
    return 0;
}