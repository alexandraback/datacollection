#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <set>
using namespace std;

int p[2000];
int a[2000];

int main()
{
    int tests;
    cin >> tests;

    for (int test = 1; test <= tests; test++) {
        int n;
        double s = 0, add = 0;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> p[i];
            a[i] = p[i];
            s += p[i];
        }

        sort (a, a + n);
        add = s;
        double y = s / n;

        int i = n - 1, m = n;
        while (i >= 0 && a[i] * m > (s + add)) m--, s -= a[i], i--;

        cout << "Case #" << test << ":";

        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(6);

        for (int i = 0; i < n; i++)
            if (m * p[i] <= s + add) cout << " " << 100 * ((s + add) / m - p[i]) / add;
            else cout << " " << 0;
        cout << endl;
    }
}
