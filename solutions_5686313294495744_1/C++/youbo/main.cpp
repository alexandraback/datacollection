#include <cassert>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cstddef>
#include <cctype>
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <list>
#include <string>
#include <functional>
#include <utility>
using namespace std;
typedef long long llint;
void readin(int &n, vector <string> &fw, vector <string> &sw)
{
    cin >> n;
    fw.resize(n);
    sw.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> fw[i];
        cin >> sw[i];
    }
}
bool dfs(int u, int const L, int const R, vector <vector <bool> > const &G, vector <int> &match, vector <bool> &visited)
{
    if (visited[u])
    {
        return false;
    }
    visited[u] = true;
    for (int v = 0; v < R; ++v)
    {
        if (!G[u][v])
        {
            continue;
        }
        if (match[v] == -1 || dfs(match[v], L, R, G, match, visited))
        {
            match[v] = u;
            return true;
        }
    }
    return false;
}
int calc(int const L, int const R, vector <vector <bool> > const &G)
{
    int ret = 0;
    vector <int> match(R, -1);
    vector <bool> visited(L);
    for (int i = 0; i < L; ++i)
    {
        fill(visited.begin(), visited.end(), false);
        if (dfs(i, L, R, G, match, visited))
        {
            ++ret;
        }
    }
    return ret;
}
int solve(int const &N, vector <string> const &F, vector <string> const &S)
{
    map <string, int> fm;
    map <string, int> sm;
    int fn = 0, sn = 0;
    for (int i = 0; i < N; ++i)
    {
        if (fm.find(F[i]) == fm.end())
        {
            fm[F[i]] = fn++;
        }
        if (sm.find(S[i]) == sm.end())
        {
            sm[S[i]] = sn++;
        }
    }
    vector <vector <bool> > g(fn, vector <bool>(sn));
    for (int i = 0; i < N; ++i)
    {
        g[fm[F[i]]][sm[S[i]]] = true;
    }
    return N - (fn + sn - calc(fn, sn, g));
}
int main()
{
    int tc;
    int n;
    vector <string> fw, sw;
    cin >> tc;
    for (int cc = 1; cc <= tc; ++cc)
    {
        readin(n, fw, sw);
        cout << "Case #" << cc << ": "
             << solve(n, fw, sw)
             << endl;
    }
}
