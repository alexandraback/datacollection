#include <iostream>
#include <fstream>
using namespace std;

const int MAXN = 110;

int s[MAXN], n, xs[MAXN], xn[MAXN], x[MAXN], ans;

int main()
{
    int t, p, surprise, ans;
    ifstream fin("b.in", ios::in);
    ofstream fout("b.out", ios::out);
    fin >> t;
    for (int i = 1; i <= t; i++)
    {
        fin >> n >> surprise >> p;
        for (int j = 1; j <= n; j++)
            fin >> s[j];
        for (int j = 1; j <= n; j++)
        {
            if (s[j] == 0 || s[j] == 1)
                xn[j] = xs[j] = s[j];
            else if (s[j] == 2)
                xn[j] = 1, xs[j] = 2;
            else if (s[j] % 3 == 0)
                xn[j] = s[j] / 3, xs[j] = (s[j] + 3) / 3;
            else if (s[j] % 3 == 1)
                xn[j] = (s[j] + 2) / 3, xs[j] = (s[j] + 2) / 3;
            else if (s[j] % 3 == 2)
                xn[j] = (s[j] + 1) / 3, xs[j] = (s[j] + 4) / 3;
            if (xs[j] > 10)
                xs[j] = 10;
            if (surprise > 0 && xn[j] < p && xs[j] >= p)
            {
                surprise--;
                x[j] = xs[j];
            }
            else
                x[j] = xn[j];
        }
        ans = 0;
        for (int j = 1; j <= n; j++)
            if (x[j] >= p)
                ans++;
        fout << "Case #" << i <<": " << ans << endl;
    }
    fout.close();
    fin.close();
    return 0;
}
