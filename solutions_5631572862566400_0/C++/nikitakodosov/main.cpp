#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:16777216")
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <time.h>
#include <iomanip>
#include <cstdio>

using namespace std;
int g[3000];
vector<vector<int>> p;


int sum;
int minh;
int minv;
int n;
int ans;
int kl;
int f[10000];
int hid[10000];
void dfs(int v, int l)
{
    hid[v] = l;
    f[v] = kl;
    if (f[g[v]] == kl)
    {
        int s = l - hid[g[v]] + 1;
        if (s > ans) ans = s;
        return;
    }
    if (f[g[v]] == 0)
    {
        dfs(g[v], l + 1);
    }

}
void find_cyclc()
{
    for (int i = 0; i < n; i++)
        if (f[i] == 0)
        {
            kl++;
            dfs(i, 1);
        }
}

void find(int v, int h)
{
    if (h > minh)
    {
        minh = h;
        minv = v;
    }
    for (int i(0); i < p[v].size(); i++)
    {
        int to = p[v][i];
        if (f[to] != 0) continue;
        find(to, h + 1);
    }
}

void make(int v)
{
    if (f[v] != 0) return;
    sum++;
    f[v] = 1;
    make(g[v]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;

        p.clear();
        p.resize(n);
        for (int i = 0; i < n; i++) {
            f[i] = 0;
        }
        ans = 1;
        kl = 1;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            x--;
            g[i] = x;
            p[x].push_back(i);
        }
        find_cyclc();
        for (int i = 0; i < n; i++)
            f[i] = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == g[g[i]])
            {
                f[i] = 2;
                f[g[i]] = 2;
            }
        }
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (f[i] != 2) continue;
            sum++;
            f[i] = 3;
            minh = -1; minv = -1;
            find(i, 0);
            make(minv);
        }
        ans = max(ans, sum);

        cout << "Case #" << test + 1 << ": " << ans <<endl;

    }
}























/*

*/












