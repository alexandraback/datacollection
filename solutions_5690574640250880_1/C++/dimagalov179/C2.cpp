#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int t, n, m, amount;
    cin >> t;
    for (int q = 0; q < t; ++q)
    {
        cin >> n >> m >> amount;
        vector<vector<bool> > field(n, vector<bool> (m, false));
        if (amount == n * m - 1)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    field[i][j] = true;
        else
        {
            int used_rows = 0, used_columns = 0;

            while (true)
            {
                if (n - used_rows >= m - used_columns)
                {
                    bool changed = false;
                    int rows = max(0, min(amount / (m - used_columns), n - used_rows - 2));

                    if (rows != 0)
                        rows = 1;

                    for (int i = 0; i < rows; ++i)
                        for (int j = 0; j < m - used_columns; ++j)
                            field[n - used_rows - i - 1][j] = true;
                    changed |= (rows * (m - used_columns) != 0);
                    amount -= rows * (m - used_columns);
                    used_rows += rows;

                    int columns = max(0, min(amount / (n - used_rows), m - used_columns - 2));

                    if (columns != 0)
                        columns = 1;

                    for (int j = 0; j < columns; ++j)
                        for (int i = 0; i < n - used_rows; ++i)
                            field[i][m - used_columns - j - 1] = true;
                    changed |= (columns * (n - used_rows) != 0);
                    amount -= columns * (n - used_rows);
                    used_columns += columns;

                    if (!changed)
                        break;
                }
                else
                {
                    bool changed = false;

                    int columns = max(0, min(amount / (n - used_rows), m - used_columns - 2));

                    if (columns != 0)
                        columns = 1;

                    for (int j = 0; j < columns; ++j)
                        for (int i = 0; i < n - used_rows; ++i)
                            field[i][m - used_columns - j - 1] = true;
                    changed |= (columns * (n - used_rows) != 0);
                    amount -= columns * (n - used_rows);
                    used_columns += columns;


                    int rows = max(0, min(amount / (m - used_columns), n - used_rows - 2));

                    if (rows != 0)
                        rows = 1;

                    for (int i = 0; i < rows; ++i)
                        for (int j = 0; j < m - used_columns; ++j)
                            field[n - used_rows - i - 1][j] = true;
                    changed |= (rows * (m - used_columns) != 0);
                    amount -= rows * (m - used_columns);
                    used_rows += rows;

                    if (!changed)
                        break;
                }
            }
            // for (int i = 0; i < n; ++i)
            //     for (int j = 0; j < m; ++j)
            //         cout << ((i == 0 && j == 0) ? "c" : (field[i][j] ? "*" : ".")) << (j == m - 1 ? "\n" : "");

            while (used_rows < n - 2 && amount != 0)
            {
                bool changed = false;
                int range = min(amount, m - used_columns - 2);
                for (int i = 0; i < range; ++i)
                {
                    field[n - used_rows - 1][m - used_columns - i - 1] = true;
                    --amount;
                    changed = true;
                }
                ++used_rows;
                if (!changed)
                    break;
            }
            while (used_columns < m - 2 && amount != 0)
            {
                bool changed = false;
                int range = min(amount, n - used_rows - 2);
                for (int i = 0; i < range; ++i)
                {
                    field[n - used_rows - i - 1][m - used_columns - 1] = true;
                    --amount;
                    changed = true;
                }
                ++used_columns;
                if (!changed)
                    break;
            }
        }
        bool found = (amount == 0 || amount == n * m - 1);
        // if (!found)
        //     cout << 0 << endl;
        // else
        //     cout << 1 << endl;
        cout << "Case #" << q + 1 << ":" << endl;
        if (!found)
            cout << "Impossible" << endl;
        else
        {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    cout << ((i == 0 && j == 0) ? "c" : (field[i][j] ? "*" : ".")) << (j == m - 1 ? "\n" : "");
        }
    }
}