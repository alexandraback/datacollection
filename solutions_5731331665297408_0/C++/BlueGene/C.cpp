#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

using namespace std;

const int MaxN = 60, MaxE = MaxN*MaxN;

int n, m, ENum, Next[MaxE], v[MaxE], Head[MaxN];
pair<int, int> a[MaxN];
string str[MaxN];
int mapping[MaxN];
long long s[MaxN];
string ans;
int prev[MaxN];

inline void AddEdge(const int &x, const int &y)
{
    Next[++ENum] = Head[x];
    v[Head[x] = ENum] = y;
}

void DFS(const int &root, const int &t)
{
    s[root] |= 1ll << t;
    for (int i = Head[t]; i; i = Next[i])
        if (! ((s[root] >> v[i]) & 1))
            DFS(root, v[i]);
}

void Solve(const int &t, const long long &opt, const string &seq, const int &h)
{
    if (! opt)
    {
        if (ans == "" || seq < ans)
            ans = seq;
        return;
    }
    if (! h)
        return;
    for (int i = Head[t]; i; i = Next[i])
        if ((opt >> v[i]) & 1)
        {
            prev[v[i]] = t;
            Solve(v[i], opt ^ (1ll << v[i]), seq+str[v[i]], h-1);
        }
    Solve(prev[t], opt, seq, h-1);
}

int main()
{
    freopen("C-small-attempt0.in.txt", "r", stdin);
    freopen("C-small-attempt0.out.txt", "w", stdout);
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        cerr << Test << endl;
        cout << "Case #" << Test << ": ";
        memset(Head, 0, sizeof(Head));
        ENum = 0;
        memset(s, 0, sizeof(s));
        cin >> n >> m;
        for (int i = 0; (a[i].second = i) < n; ++i)
            cin >> a[i].first;
        sort(a, a+n);
        for (int i = 0; i < n; ++i)
        {
            mapping[a[i].second] = i;
            ostringstream buffer;
            buffer << a[i].first;
            str[i] = buffer.str();
        }
        for (int i = 0, x, y; i < m; ++i)
        {
            cin >> x >> y;
            --x, --y;
            if (x != y)
            {
                AddEdge(mapping[x], mapping[y]);
                AddEdge(mapping[y], mapping[x]);
            }
        }
        for (int i = 0; i < n; ++i)
            DFS(i, i);
        ans = "";
        prev[0] = -1;
        Solve(0, ((1ll << n)-1) ^ 1, str[0], n*2);
        cout << ans << endl;
    }
    return 0;
}
