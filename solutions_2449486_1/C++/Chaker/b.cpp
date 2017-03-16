#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

typedef vector <vector <int> > Map;
int n, m;
Map f;

bool check(int a, int b)
{
    bool vert = true,
        hor = true;
    for (int i = 0; i < n; ++i) {
        vert &= (f[i][b] <= f[a][b]);
    }
    for (int j = 0; j < m; ++j) {
        hor &= (f[a][j] <= f[a][b]);
    }
    return vert || hor;
}

int main()
{
    int TEST = 0;
    cin >> TEST;
    for (int test = 1; test <= TEST; ++test) {
        cout << "Case #" << test << ": ";
        cin >> n >> m;
        f.resize(n);
        for (int i = 0; i < n; ++i) {
            f[i].resize(m);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> f[i][j];
            }
        }
        bool is_ok = true;
        for (int i = 0; i < n && is_ok; ++i) {
            for (int j = 0; j < m; ++j) {
                is_ok &= check(i, j);
                if (is_ok == false) {
                    break;
                }
            }
        }
        cout << (is_ok ? "YES" : "NO") << endl;
    }
    return 0;
}