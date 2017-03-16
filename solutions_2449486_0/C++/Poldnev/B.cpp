#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

#define pb push_back

ifstream in("B-small-attempt0.in");
ofstream out("output.txt");

int main()
{
    int t;
    in >> t;
    for (int z = 0; z < t; ++z) {
        bool ok = true;
        int n, m;
        in >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                in >> a[i][j];
            }
        }
        for (int k = 1; k <= 100; ++k) {
            vector<bool> row(n, false), col(m, false);
            for (int i = 0; i < n; ++i) {
                row[i] = true;
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] != k) {
                        row[i] = false;
                        break;
                    }
                }
            }
            for (int j = 0; j < m; ++j) {
                col[j] = true;
                for (int i = 0; i < n; ++i) {
                    if (a[i][j] != k) {
                        col[j] = false;
                        break;
                    }
                }
            }
            bool tok = true;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] == k) {
                        if (!row[i] && !col[j]) {
                            tok = false;
                            break;
                        } else {
                            ++a[i][j];
                        }
                    }
                }
                if (!tok) {
                    break;
                }
            }
            if (!tok) {
                ok = false;
                break;
            }
        }
        out << "Case #" << z + 1 << ": " << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
