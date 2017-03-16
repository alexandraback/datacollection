#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stdint.h>
using namespace std;

int pos[2500];
char grid[51][51];
pair<int,int> ab[51][51];
int dep[51][51];
bool noproc[51][51];
bool visited[51][51];
int r,c,m,n,t;

int flood()
{
    deque<pair<int,int> > q;
    q.push_back(make_pair(0,0));
    int a = 0;
    memset(visited, 0, sizeof(visited));
    visited[0][0]= true;
    while (!q.empty()) {
        a++;
        int y = q.front().first, x = q.front().second;
        q.pop_front();
        bool potest = true;
        for (int i=max(0,y-1);i<min(y+2,r)&&potest;i++) {
            for (int j=max(0,x-1);j<min(x+2,c)&&potest;j++) {
                if ((i!=y || j!=x) && grid[i][j]=='*') potest = false;
            }
        }
        if (!potest) continue;
        for (int i=max(0,y-1);i<min(y+2,r);i++) {
            for (int j=max(0,x-1);j<min(x+2,c);j++) {
                if ((i!=y || j!=x) && grid[i][j]=='.' && !visited[i][j]) {
                    q.push_back(make_pair(i,j));
                    visited[i][j] = true;
                }
            }
        }
    }
    //cout << a << endl;
    return a;
}

bool bfs()
{
    list<pair<int,int> > q;
    q.push_back(make_pair(0,0));
    t = 1;
    memset(noproc, 0, sizeof(noproc));
    while (!q.empty() && t<(n-m)) {
        list<pair<int,int> >::iterator optimus=q.begin();
        int optimusv = 8;
        for (list<pair<int,int> >::iterator it=q.begin();it!=q.end();++it) {
            int y = it->first, x = it->second, cv = 0;
            for (int i=max(0,y-1);i<min(y+2,r);i++) {
                for (int j=max(0,x-1);j<min(x+2,c);j++) {
                    if ((i!=y || j!=x) && grid[i][j]=='*') {
                        cv++;
                    }
                }
            }
            if (cv<optimusv) {
                optimusv = cv;
                optimus = it;
            }
        }
        int y = optimus->first, x = optimus->second;
        q.erase(optimus);
        noproc[y][x] = false;
        dep[y][x] = optimusv;
        for (int i=max(0,y-1);i<min(y+2,r);i++) {
            for (int j=max(0,x-1);j<min(x+2,c);j++) {
                if ((i!=y || j!=x) && grid[i][j]=='*') {
                    grid[i][j] = '.';
                    noproc[i][j] = true;
                    ab[i][j] = make_pair(y,x);
                    q.push_back(make_pair(i,j));
                    t++;
                }
            }
        }
        //for (int i=0;i<r;i++) cout << grid[i] << endl;
    }
    while (t>n-m) {
        bool potest = false;
        for (int i=0;i<r&&!potest;i++)
            for (int j=0;j<c&&!potest;j++)
                if (grid[i][j] == '.') {
                    grid[i][j] = '*';
                    if (flood() == t-1) {
                        t--;
                        potest = true;
                        break;
                    }
                    grid[i][j] = '.';
                }
        if (!potest) break;
    }
    return t==n-m;
}


__attribute__((optimize("-O3")))
int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);

    int tcas;
    cin >> tcas;
    for (int cas=1;cas<=tcas;cas++) {
        cin >> r >> c >> m;
        n = r*c;
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++)
                grid[i][j] = '*';
            grid[i][c] = 0;
        }
        grid[0][0] = 'c';
        cout << "Case #" << cas << ':' << endl;
        if (!bfs()) cout << "Impossible" << endl;
        else {
            for (int i=0;i<r;i++) cout << grid[i] << endl;
        }
    }
    
    return 0;
}
