#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl; 

int n, m, k;

void readInput()
{
    cin >> n >> m >> k;
}

vector<string> transpose(vector<string> a)
{
    vector<string> ret(a[0].size());
    for (int i = 0; i < ret.size(); i++)
    {
        ret[i].resize(a.size());
        for (int j = 0; j < ret[i].size(); j++)
            ret[i][j] = a[j][i];
    }
    return ret;
}

bool solve(vector<string> &field)
{
    bool tr = false;
    if (n > m)
    {
        tr = true;
        swap(n, m);
    }
    field.assign(n, string(m, '.'));
    if (n == 2 && k % 2 == 1 && k != n * m - 1)
        return false;
    int ck = 0, z = 0;
    for (int j = 0; j < m - 2 && ck < k; j++)
        for (int i = 0; i < n - 2 && ck < k; i++)
        {
            if (i == n - 3 && j == m - 3)
            {
                if ((k - ck - 1) % 2 == 1 && k != n * m - 1)
                {
                    z = 1;
                    break;
                }
            }
            field[i][j] = '*';
            ck++;
        }
    //dbg(ck);
    //dbg(k);
    if (n != 1)
    {
        if (k != ck && (n * m - k == 2 || (k - ck) % 2 == 1) && k != n * m - 1)
            return false;
        if (z && k > n * m - 9)
            return false;
    }
    //dbg(ck);
    if (ck != k)
    {
        for (int j = 0; j < m - 2 - z && ck < k; j++)
            for (int i = max(0, n - 2); i < n && ck < k; i++)
            {
                field[i][j] = '*';
                ck++;
            }
        for (int i = 0; i < n && ck < k; i++)
            for (int j = max(0, m - 2); j < m && ck < k; j++)
            {
                field[i][j] = '*';
                ck++;
            }
    }
    field[n - 1][m - 1] = 'c';
    if (tr)
    {
        field = transpose(field);
        swap(n, m);
    }
    return true;
}

int main()
{
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ":\n";
        readInput();
        vector<string> field;
        if (solve(field))
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    cout << field[i][j];
                cout << "\n";
            }
        }
        else cout << "Impossible\n";
    }
    return 0;
}
