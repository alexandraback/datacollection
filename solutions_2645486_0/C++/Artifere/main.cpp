#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


int best[11][6];
int regain;
int val[11];
int maxE;
int nbActi;


int dyn(int posActi, int curE)
{
    if (posActi == nbActi)
        return 0;
    if (best[posActi][curE] == -1)
    {
        if (posActi == nbActi+1)
        {
            best[posActi][curE] = curE*val[nbActi];
        }
        else
        {
            int tmp = 0;
            for (int i = 0; i <= curE; i++)
            {
                tmp = max(tmp, dyn(posActi+1, min(maxE, curE-i+regain))+i*val[posActi]);
            }

            best[posActi][curE] = tmp;
        }
    }

    return best[posActi][curE];
}

int main()
{
    freopen("small.in", "r", stdin);
    //freopen("small.out", "w", stdout);

    int nbT;
    cin >> nbT;

    for (int t = 1; t <= nbT; t++)
    {

        cin >> maxE >> regain >> nbActi;

        for (int i = 0; i < nbActi; i++)
            cin >> val[i];
        for (int i = 0; i < nbActi; i++)
            for (int j = 0; j <= maxE; j++)
                best[i][j] = -1;
        cout << "Case #" << t << ": " << dyn(0, maxE) << "\n";
    }

    return 0;
}
