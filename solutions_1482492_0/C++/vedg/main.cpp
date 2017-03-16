#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <cfloat>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);
    freopen("cout", "w", stdout);
#endif

    int cases;
    cin >> cases;

    for (int cas = 1;cas <= cases;++cas) {
        cout << "Case #" << cas << ":\n";

        double d;
        cin >> d;
        int n, a;
        cin >> n >> a;
        vector<double> time(n), pos(n);
        for (int i = 0;i < n;++i)
            cin >> time[i] >> pos[i];
        vector<double> acc(a);
        for (int i = 0; i < a;++i) {
            cin >> acc[i];

            double initial = sqrt(2 * d / acc[i]);
            if (n != 1) {
                double dis = d - pos[0];
                if (dis > 0) {
                    double t = time[1] - time[0];
                    double allD = pos[1] - pos[0];
                    double other = dis * t / allD;
                    if (other > initial)
                        initial = other;
                }
            }
            cout.precision(10);
            cout << initial << endl;
        }

    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    putchar('\n');
#endif
}

