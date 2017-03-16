#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int result;
int n, m, k;

void dfs(int use_row, int use_col, int num, int use)
{
    if (use > result)
        return;
    result = min(result, max(0, k - num) + use);
    if (use_row + 1 <= n - 2) dfs(use_row + 1, use_col, num + use_col + 2, use + 2);
    if (use_col + 1 <= m - 2) dfs(use_row, use_col + 1, num + use_row + 2, use + 2);
}

void Solved(int nT)
{
    
    cin >> n >> m >> k;
    printf("Case #%d: ", nT);
    if (n > m) swap(n, m);
    if (n <= 2)
    {
        cout << result << endl;
        return;
    }
    result = k;
    dfs(1, 1, 5, 4);
    cout << result << endl;
}

int main()
{
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);

    int T = 1;
    cin >> T;
    for (int nT = 1; nT <= T; ++nT)
    {
        Solved(nT);
    }

    return 0;
}