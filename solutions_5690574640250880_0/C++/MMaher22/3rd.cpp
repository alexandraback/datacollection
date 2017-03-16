#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

int t, r, c, m;
int sol = 0;
int no = 0;
int index[100] = {0};
int vis[100] = {0};

typedef pair<int, int> P;
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void mido1(int x, int y)
{
    queue<P> que;

    que.push(P(x, y));
    vis[x*c+y] = 1;
    sol = 1;

    while(que.size())
    {
        P p = que.front();
        que.pop();

        int check = 1;
        for(int i = 0; i < 8; ++i)
        {
            int nx = p.first + dir[i][0], ny = p.second + dir[i][1];
            if(nx >= 0 && nx < r && ny >= 0 && ny < c)
            {
                if(index[nx*c+ny] == 1) check = 0;
            }
        }
        if(check)
        {
            for(int i = 0; i < 8; ++i)
            {
                int nx = p.first + dir[i][0], ny = p.second + dir[i][1];
                if(nx >= 0 && nx < r && ny >= 0 && ny < c && vis[nx*c+ny] == 0)
                {
                    vis[nx*c+ny] = 1;
                    sol++;
                    que.push(P(nx, ny));
                }
            }
        }
    }
}

int mido2()
{
    int comb = (1 << m) - 1;
    memset(index, 0, sizeof(index));
    int i = 1;
    int j = 0;
    while(true)
    {
        if(i & comb)
        {
            index[j] = 1;
        }
        ++j;
        i*=2;
        if(j >= r*c) break;
    }

    int res = r * c - m;

    for(int x = 0; x < r; ++x)
    {
        for(int y = 0; y < c; ++y)
        {
            if(index[x*c+y] == 0)
            {
                sol = 0;
                memset(vis, 0, sizeof(vis));
                mido1(x, y);
                if(sol == res)
                {
                    cout << "Case #" << no << ": " << endl;
                    for(int l = 0; l < r; ++l)
                    {
                        for(int g = 0; g < c; ++g)
                        {
                            if(l == x && g == y) cout << "c";
                            else if(index[l*c+g] == 1) cout << "*";
                            else cout << ".";
                        }
                        cout << endl;
                    }
                    return 1;
                }
            }
        }
    }

    while(comb < 1 << r*c)
    {
        int p1 = comb & -comb, p2 = comb + p1;
        comb = ((comb & ~p2) / p1 >> 1) | p2;

        memset(index, 0, sizeof(index));
        int i = 1;
        int j = 0;
        int sol1 = 0;
        while(true)
        {
            if(i & comb)
            {
                index[j] = 1;
                ++sol1;
            }
            ++j;
            i*=2;
            if(j >= r*c) break;
        }

        for(int x = 0; x < r; ++x)
        {
            for(int y = 0; y < c; ++y)
            {
                if(index[x*c+y] == 0)
                {
                    sol = 0;
                    memset(vis, 0, sizeof(vis));
                    mido1(x, y);
                    if(sol == res)
                    {
                        cout << "Case #" << no << ": " << endl;
                        for(int l = 0; l < r; ++l)
                        {
                            for(int g = 0; g < c; ++g)
                            {
                                if(l == x && g == y) cout << "c";
                                else if(index[l*c+g] == 1) cout << "*";
                                else cout << ".";
                            }
                            cout << endl;
                        }
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void Solve()
{
    memset(index, 0, sizeof(index));
    if(mido2() == 0)
    {
        cout << "Case #" << no << ": " << endl << "Impossible" << endl;
    }
}

int main()
{
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("clocks.out", "w", stdout);

    cin >> t;
    int tf = t;
    while(t--)
    {
        cin >> r >> c >> m;
        no = tf - t;
        Solve();
    }
    return 0;
}
