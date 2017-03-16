#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>

#define inf 1000000000

using namespace std;

ifstream fin ("test.in");
ofstream fout("test2.out");

int v[30];
int d[2000010],t[2000010];
bool viz[2000010];

int rev(int x)
{
    int y = 0;

    while (x != 0)
    {
        y = y*10 + x%10;
        x /= 10;
    }

    return y;
}

long long solve()
{
    int n;
    fin >> n;

    memset(viz,0,sizeof(viz));

    for (int i = 1; i <= 2*n; ++i)
    {
        d[i] = inf;
    }
    d[1] = 1;

    queue<int> Q;
    Q.push(1);
    viz[1] = 1;

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        if (x == n)
            break;

        if (!viz[x+1])
        {
            viz[x+1] = 1;
            d[x+1] = d[x] + 1;
            t[x+1] = x;
            Q.push(x+1);
        }

        int y = rev(x);

        if (!viz[y])
        {
            viz[y] = 1;
            d[y] = d[x] + 1;
            t[y] = x;
            Q.push(y);
        }
    }

    /*for (int i = n; i != 0; i = t[i])
    {
        fout << i << " ";
    }
    fout << "\n";*/

    return d[n];
}

int main()
{
    int test;
    fin >> test;

    for (int k = 1; k <= test; ++k)
    {
        int ans = solve();

        fout << "Case #" << k << ": " << ans << "\n";
    }
}
