#include <cstdio>
#include <iostream>
using namespace std;


int matrix[101][101];

int max_row[101];
int max_col[101];

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int T = 0;
    cin >> T;
    for (int step = 1; step <= T; ++step)
    {
        int n = 0;
        int m = 0;
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> matrix[i][j];

        for (int i = 0; i < 100; ++i)
            max_col[i] = max_row[i] = -1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (max_row[i] < matrix[i][j])
                    max_row[i] = matrix[i][j];
                if (max_col[j] < matrix[i][j])
                    max_col[j] = matrix[i][j];
            }
        bool flag = true;
        for (int i = 0; flag && (i < n); ++i)
            for (int j = 0; j < m; ++j)
                if ((matrix[i][j] < max_row[i]) && (matrix[i][j] < max_col[j]))
                    flag = false;
        if (flag)
            cout << "Case #" << step << ": YES\n";
        else
            cout << "Case #" << step << ": NO\n";
    }
    return 0;
}
