#include <cstdio>
#include <vector>
#include <utility>
#include <cassert>

using namespace std;

int n, m, g;

int tab[55][55];
char nak[55][55];

const int xx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int yy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

bool wew(int x, int y) { return (x >= 1 && y >= 1 && x <= n && y <= m); }
bool rog(int x, int y) { return (x == 1 || x == n) && (y == 1 || y == m); }
bool kraw(int x, int y) { return (x == 1 || x == n || y == 1 || y == m) && !rog(x, y); }

void ustaw(int x, int y)
{
    if(nak[x][y] == '.')
        return;
    g--;
    nak[x][y] = '.';
    for(int i = 0; i < 8; i++)
    {
        int xxx = x + xx[i], yyy = y + yy[i];
        if(!wew(xxx, yyy)) continue;
        tab[xxx][yyy]--;
    }
}

void zabierz(int x, int y)
{
    if(nak[x][y] == '*')
        return;
    g++;
    nak[x][y] = '*';
    for(int i = 0; i < 8; i++)
    {
        int xxx = x + xx[i], yyy = y + yy[i];
        if(!wew(xxx, yyy)) continue;
        tab[xxx][yyy]++;
    }
}

bool upychaj(int x, int y)
{
    /*
    printf("upychaj(%d, %d)\n", x, y);
    for(int i = 1; i <= n; i++)
    {
        printf("    ");
        for(int j = 1; j <= m; j++)
            printf("%c", nak[i][j]);
        printf("    ");
        for(int j = 1; j <= m; j++)
            printf("%2d ", tab[i][j]);
        printf("\n");
    }
    */
    vector<pair<int, int> > v;
    for(int i = 0; i < 8; i++)
    {
        int xxx = x + xx[i], yyy = y + yy[i];
        if(!wew(xxx, yyy)) continue;
        if(nak[xxx][yyy] == '*')
        {
            v.push_back(make_pair(xxx, yyy));
            ustaw(xxx, yyy);
        }
    }
    if(g == 0) return true;
    if(g > 0)
    {
        for(int xxx = 1; xxx <= n; xxx++)
        {
            for(int yyy = 1; yyy <= m; yyy++)
            {
                if(tab[xxx][yyy] == 0 || nak[xxx][yyy] == '*') continue;
                bool ok = false;
                for(int i = 0; i < 8 && !ok; i++)
                {
                    int xxxx = xxx + xx[i], yyyy = yyy + yy[i];
                    if(wew(xxxx, yyyy) && tab[xxxx][yyyy] == 0)
                        ok = true;
                }
                if(ok)
                {
                    if(upychaj(xxx, yyy))
                        return true;
                }
            }
        }
    }
    for(int i = 0; i < v.size(); i++)
        zabierz(v[i].first, v[i].second);
    return false;
}

void przyp()
{
    scanf("%d%d%d", &n, &m, &g);
    g = n * m - g;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(n == 1 || m == 1)
            {
                if(rog(i, j)) tab[i][j] = 1;
                else tab[i][j] = 2;
            }
            else
            {
                if(rog(i, j)) tab[i][j] = 3;
                else if(kraw(i, j)) tab[i][j] = 5;
                else tab[i][j] = 8;
            }
            nak[i][j] = '*';
        }
    }
    bool ok = false;
    if(g == 1)
    {
        nak[1][1] = 'c';
        ok = true;
    }
    else if((n == 2 || m == 2) && (g % 2 == 1))
    {
        assert(g != 1);
        ok = false;
    }
    else
    {
        for(int i = 1; i <= n && !ok; i++)
            for(int j = 1; j <= m && !ok; j++)
            {
                ustaw(i, j);
                if(upychaj(i, j))
                {
                    nak[i][j] = 'c';
                    ok = true;
                }
                else zabierz(i, j);
            }
    }
    if(!ok)
    {
        printf("Impossible\n");
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            printf("%c", nak[i][j]);
        printf("\n");
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        printf("Case #%d:\n", i);
        przyp();
    }
    return 0;
}
