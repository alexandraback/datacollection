#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
    ifstream cin("B-small-attempt3.in");
    ofstream cout("out.txt");
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, X, Y;
        cin >> N >> X >> Y;
        int k = 1;
        X = abs(X);
        int num = 1;
        int lvl = 0;
        while (num <= N) {
            k = 2*(k/2 + 1) + 3;
            num += k;
            lvl++;
        }
        num -= k;
        double res = 0;
        if (X+Y > 2*lvl)
            res = 0;
        else if (X+Y < 2*lvl)
            res = 1;
        else {
            // Solve
            //cout << "num = " << num << endl;
            //cout << "k = " << k << endl;
            if (k/2 + num + Y + 1 <= N)
                res = 1;
            else if (num + Y + 1 > N)
                res = 0;
            else if (X == 0 && num + Y * 2 + 1 > N)
                res = 0;
            else {
                // Solve
                int cur = Y + 1;
                int all = N - num;
                //cout << "cur = " << cur << endl;
                //cout << "all = " << all << endl;
                // C[all; cur] = C[n; k]
                int C = 1;
                for (int i = 0; i < cur; i++) {
                    C = C * (all - i) / (i + 1);
                }
                for (int i = cur; i <= all; i++) {
                    res += C;
                    C = C * (all - i) / (i + 1);
                }
                res *= pow(0.5, all);
            }
        }

        cout << "Case #" << t << ": ";
        cout.precision(15);
        cout << res;
        cout << endl;
    }
}

