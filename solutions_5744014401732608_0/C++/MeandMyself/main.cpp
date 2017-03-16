#include <iostream>

#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <cmath>
#include <algorithm>

#include <fstream>

using namespace std;



int main()
{
    ifstream cin ("/Users/Roman/ClionProjects/Calculations/input.txt");
    ofstream cout ("/Users/Roman/ClionProjects/Calculations/output.txt");

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout.setf(ios_base::fixed);
    cout.precision(28);

    int tt;
    cin >> tt;
    //cout << tt;
    for (int t = 0; t < tt; ++t) {
        long long n, m;
        cin >> n;
        long long mx = (1 << (n - 2));
        cin >> m;
        if (m <= mx) {
            cout << "Case #" << t + 1 << ": POSSIBLE\n";
            vector < vector < int > > x (n, vector < int > (n, 0));
            if (m == mx) {
                for (int i = 0; i < n; ++i) {
                    for (int j = i + 1; j < n; ++j) {
                        x[i][j] = 1;
                    }
                }
            } else {
                for (int i = 1; i < n - 1; ++i) {
                    x[i][n - 1] = 1;
                }
                int v = n - 2;
                while (m != 0) {
                    if (m % 2 == 1) {
                        x[0][v] = 1;
                        for (int i = v; i < n; ++i) {
                            for (int j = i + 1; j < n; ++j) {
                                x[i][j] = 1;
                            }
                        }
                    }
                    v--;
                    m /= 2;
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << x[i][j];
                }
                cout << "\n";
            }
        } else {
            cout << "Case #" << t + 1 << ": IMPOSSIBLE\n";
        }
        //cout << endl;
    }
    return 0;
}