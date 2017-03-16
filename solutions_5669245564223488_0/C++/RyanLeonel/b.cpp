#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n;
vector <int> xmins[26], xmaxs[26];
vector <string> trains;

/*bool check_train(string train)
{
    bool ok = true;
    char ch;
    int i, len = train.length(), xmin;
    for (ch = 'a'; ch <= 'z'; ch++)
    {
        xmin = -1;
        for (i = 0; i < len; i++)
        {
            if (train[i] == ch) { xmin = i; break; }
        }
        if (xmin != -1)
        {
            for (i = xmin + 1; i < len; i++)
            {
                if ((train[i] == ch) && (train[i - 1] != ch)) { ok = false; break; }
            }
        }
        if (!ok) break;
    }
    return ok;
}*/

int getnum(int n1, string tr, int x[], int xmin[], int xmax[])
{
    bool ok;
    char ch;
    int i, j, k, len, len1, res;
    string train;
    int x1[10], xmax1[26], xmin1[26];
    len = tr.length();
    if (n1 == n)
    {
        return 1;
    }
    else
    {
        res = 0; for (i = 0; i < n1; i++) x1[i] = x[i];
        for (i = 0; i < n; i++)
        {
            ok = true;
            for (j = 0; j < n1; j++)
            {
                if (x[j] == i) { ok = false; break; }
            }
            if (ok)
            {
                train = tr + trains[i];
                // check if train is ok
                for (j = 0; j < 26; j++)
                {
                    if ((xmins[j][i] > 0) && (xmax[j] != -1)) { ok = false; break; }
                    if ((xmins[j][i] == 0) && (xmax[j] != -1) && (xmax[j] != len - 1)) { ok = false; break; }
                    xmin1[j] = xmin[j]; xmax1[j] = xmax[j];
                    if ((xmin1[j] == -1) && (xmins[j][i] != -1)) xmin1[j] = len + xmins[j][i];
                    if (xmaxs[j][i] != -1) xmax1[j] = len + xmaxs[j][i];
                }
            }
            if (ok)
            {
                x1[n1] = i;
                res += getnum(n1 + 1, train, x1, xmin1, xmax1);
                res %= 1000000007;
            }
        }
        return res;
    }
}

int main()
{
    bool first;
    int cnt, i, j, k, num, t;
    int temp[10], xmax[26], xmin[26];
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> n; trains.resize(n);
        for (i = 0; i < n; i++) cin >> trains[i];
        for (i = 0; i < 26; i++)
        {
            xmins[i].resize(n); for (j = 0; j < n; j++) xmins[i][j] = -1;
            xmaxs[i].resize(n); for (j = 0; j < n; j++) xmaxs[i][j] = -1;
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < 26; j++)
            {
                first = true;
                for (k = 0; k < trains[i].length(); k++)
                {
                    if (trains[i][k] == 'a' + j)
                    {
                        if (first) xmins[j][i] = k;
                        first = false; xmaxs[j][i] = k;
                    }
                }
            }
        }

        for (i = 0; i < 26; i++) xmin[i] = -1;
        for (i = 0; i < 26; i++) xmax[i] = -1;
        num = getnum(0, "", temp, xmin, xmax);
        cerr << "Case #" << cnt << ": " << num << endl;
        cout << "Case #" << cnt << ": " << num << endl;
    }
    return 0;
}
