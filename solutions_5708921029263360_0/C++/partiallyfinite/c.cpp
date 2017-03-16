#include <iostream>
#include <vector>

using namespace std;

int t;
int j, p, s, k;
int wa[10][10], wb[10][10];
vector<int> x, y, z;

int main() {
    cin >> t;
    for (int C = 0; C ++< t;) {
        cin >> j >> p >> s >> k;
        x.clear(), y.clear(), z.clear();
        for (int i = 10; i --> 0;) for (int j = 10; j --> 0;) wa[i][j] = wb[i][j] = k;
        for (int a = 0; a < j; ++a) {
            for (int b = 0; b < p; ++b) {
                for (int i = 0, c = 0; i < k && c < s; ++c) if (wa[a][c] && wb[b][c]) {
                    ++i;
                    --wa[a][c];
                    --wb[b][c];
                    x.push_back(a + 1), y.push_back(b + 1), z.push_back(c + 1);
                }
            }
        }
        cout << "Case #" << C << ": " << x.size() << '\n';
        for (int i = 0; i < x.size(); ++i) cout << x[i] << ' ' << y[i] << ' ' << z[i] << '\n';
    }
}

