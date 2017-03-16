#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

set<string> S;

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int r, c, t;
string cad;

char M[5][5];

void hacermatriz()
{
    int pos = 0;
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            M[i][j] = cad[pos];
            pos++;
        }
    }
}

bool desborda(int x, int y)
{
    if (x < 0 || y < 0 || x >= r || y >= c)
        return true;
    return false;
}

int espacios(int x, int y)
{
    bool V[5][5];
    memset(V, false, sizeof(V));
    V[x][y] = true;
    queue<int> X;
    queue<int> Y;
    X.push(x);
    Y.push(y);
    int ret = 0;
    while (!X.empty())
    {
        ret++;
        x = X.front();
        y = Y.front();
        X.pop();
        Y.pop();
        bool valelapena = true;
        for (int i=0; i<8; i++)
        {
            if (!desborda(x+dx[i], y+dy[i]) && M[x+dx[i]][y+dy[i]] == '*')
            {
                valelapena = false;
                break;
            }
        }
        if (valelapena)
        {
            for (int i=0; i<8; i++)
            {
                if (!desborda(x+dx[i], y+dy[i]) && M[x+dx[i]][y+dy[i]] == '.' && !V[x+dx[i]][y+dy[i]])
                {
                    X.push(x+dx[i]);
                    Y.push(y+dy[i]);
                    V[x+dx[i]][y+dy[i]] = true;
                }
            }
        }

    }
    return ret;
}

bool posible()
{
    do
    {
        int T = S.size();
        S.insert(cad);
        if (T != S.size())
        {
            hacermatriz();
            for (int i=0; i<r; i++)
            {
                bool saldeaqui = false;
                for (int j=0; j<c; j++)
                {
                    if (M[i][j] == '*')
                        continue;
                    for (int k=0; k<8; k++)
                    {
                        if (M[i+dx[k]][j+dy[k]] == '*' && !desborda(i+dx[k], j+dy[k]))
                        {
                            saldeaqui = true;
                            break;
                        }
                    }
                    if (saldeaqui) continue;
                    if (espacios(i, j) == (r*c)-t)
                    {
                        M[i][j] = 'c';
                        return true;
                    }
                }
            }
        }
    }while (next_permutation(cad.begin(), cad.end()));
    return  false;
}

int main()
{
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int nc;
    cin >> nc;
    for (int tc=1; tc<=nc; tc++)
    {
        cad = "";
        S.clear();
        memset(M, '.', sizeof(M));
        cin >> r >> c >> t;
        for (int i=1; i<=r*c; i++)
        {
            if (i <= t)
                cad += "*";
            else
                cad += ".";
        }
        cout << "Case #" << tc << ":" << endl;
        if ((r*c)-t == 1)
        {
            int pos = 0;
            for (int i=0; i<r; i++)
            {
                for (int j=0; j<c; j++)
                {
                    if (cad[pos] == '.')
                        cout << "c";
                    else
                        cout << cad[pos];
                    pos++;
                }
                cout << endl;
            }
        }
        else if (posible())
        {
            for (int i=0; i<r; i++)
            {
                for (int j=0; j<c; j++)
                {
                    cout << M[i][j];
                }
                cout << endl;
            }
        }
        else
        {
            cout << "Impossible" << endl;
        }
    }
    fclose (stdout);
    return 0;
}

