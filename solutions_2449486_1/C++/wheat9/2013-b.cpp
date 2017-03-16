#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solve()
{
        int m, n;
        cin >> n >> m;
        vector<vector<int> > d(n);
        vector<int> row_max(n), col_max(m);
        for (int i = 0; i < n; ++i) {
                d[i].resize(m);
                for (int j = 0; j < m; ++j)
                        cin >> d[i][j];
                row_max[i] = *max_element(d[i].begin(), d[i].end());
        }

        for (int i = 0; i < m; ++i) {
                int max_col = d[0][i];
                for (int j = 1; j < n; ++j)
                        max_col = max(max_col, d[j][i]);
                col_max[i] = max_col;
        }

        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j)
                        if (d[i][j] != row_max[i] && d[i][j] != col_max[j])
                                return "NO";
        }
        return "YES";
}

int main()
{
        int t;
        cin >> t;
        for (int i = 1; i <= t; ++i) {
                cout << "Case #" << i << ": " << solve() << "\n";
        }
                
}
