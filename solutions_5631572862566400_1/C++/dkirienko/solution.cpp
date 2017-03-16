#include<iostream>
#include<vector>
#include<sstream>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

int n;
int ans;
vector <int> forw;
vector <vector<int> > back;

int dfs(int start, int prev)
{
    int ans = 0;
    for (auto next: back[start])
        if (next != prev)
            ans = max(ans, dfs(next, start));
    return ans + 1;
}

int solve()
{
    int n;
    cin >> n;
    forw.resize(n + 1);
    back.resize(0);
    back.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int j;
        cin >> j;
        forw[i] = j;
        back[j].push_back(i);
    }
    ans = 0;
    // Ищем длину наибольшего цикла
    for (int start = 1; start <= n; ++start)
    {
        int len = 1;
        int next = forw[start];
        while (next != start && len <= n)
        {
            ++len;
            next = forw[next];
        }
        if (next == start)
            ans = max(ans, len);
    }
    int curr_ans = 0;
    // Теперь ищем терминальные вершины
    for (int a = 1; a <= n; ++a)
    {
        int b = forw[a];
        if (b < a || forw[b] != a)
            continue;
        curr_ans += dfs(a, b) + dfs(b, a);
    }
    ans = max(ans, curr_ans);
    return ans;
}

int main()
{
    int T, t;
    cin >> T;
    for (t = 1; t <= T; ++t)
    {
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}

