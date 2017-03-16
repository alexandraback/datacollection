#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <memory.h>

using namespace std;

string zi[200];
int n,m;
int e[200][200];
string way;
string best;
int v[200];
vector<int> w;

void ans(int pos, int pr, int vi, string way)
{
    if (way >= best)
        return;

    if (vi == 0)
    {
        best = way;
        return;
    }

    v[pos]++;

    if (w.size() != 0)
    {
        int t = w[w.size()-1];
        w.pop_back();
        ans(t, pos, vi, way);
        w.push_back(t);
    }

    w.push_back(pos);
    int mini = -1;
    for (int i = 0; i < n; i++)
        if (e[pos][i] == 1 && v[i] == 0)
            if (mini == -1 || zi[mini] > zi[i])
                mini = i;

    if (mini != -1)
        ans(mini, pos, vi-1, way+zi[mini]);

    v[pos]--;
    w.pop_back();
}


void solve(int TT)
{
    cerr << endl;
    cerr << TT << endl;
    string res;

    cin >> n >> m;

    int mini = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> zi[i];
        if (zi[i] < zi[mini])
            mini = i;
    }
    memset(e, 0, sizeof e);
    memset(v, 0, sizeof v);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        e[a][b]=1;
        e[b][a]=1;
    }

    way = "";
    best = "99";
    best[0]++;
    ans(mini, -1, n-1, zi[mini]);

    cout << "Case #" << TT << ": " << best << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}

