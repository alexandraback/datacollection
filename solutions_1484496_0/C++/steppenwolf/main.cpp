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

int a[20];
int sum[2000001];

int main()
{
    int tests;
    cin >> tests;

    for (int test = 1; test <= tests; test++) {
        int n, s;
        memset(sum, 0, sizeof(sum));
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];

        int i;
        bool yes = false;
        for (i = 1; i < 1 << n; i++) {
            s = 0;
            for (int j = 0; j < n; j++)
                if (i & (1 << j)) s += a[j];
            if (sum[s]) {
                yes = true;
                break;
            }
            sum[s] = i;
        }

        cout << "Case #" << test << ":" << endl;

        if (yes) {
            int w = 0;
            for (int j = 0; j < n; j++)
                if (sum[s] & (1 << j)) {
                    if (w) cout << " ";
                    cout << a[j];
                    w = 1;
                }
            cout << endl;
            w = 0;
            for (int j = 0; j < n; j++)
                if (i & (1 << j)) {
                    if (w) cout << " ";
                    cout << a[j];
                    w = 1;
                }
            cout << endl;
        }
        else cout << "Impossible" << endl;
    }
}
