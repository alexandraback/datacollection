#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long double real;
typedef long long TT;

#define PB push_back
#define SQR(x) ((x)*(x))
#define PII pair<int, int>
#define VI vector<int>
#define VVI vector<VI >
#define VS vector<string>
#define VTT vector<TT>
#define VR vector<real>

const int maxn = 512;

int a[maxn];
map<int, int> m;

int main()
{
    freopen("input.txt" ,"rt", stdin); freopen("output.txt", "wt", stdout);

    int i, j;

    int T, sc;
    cin >> T;
    for (sc = 0; sc < T; sc++) {
        int n, m1 = -1, m2;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }

        m.clear();
        for (i = 1; i < (1 << n); i++) {
            int sum = 0;
            for (j = 0; j < n; j++) {
                if (i & (1 << j)) sum += a[j];
            }
            if (m.find(sum) != m.end()) {
                m1 = m[sum];
                m2 = i;
                break;
            }
            m[sum] = i;
        }

        cout << "Case #" << sc+1 << ": ";
        cout << endl;
        if (m1 == -1) {
            cout << "Impossible";
        } else {
            for (j = 0; j < n; j++) {
                if (m1 & (1 << j)) cout << a[j] << " ";
            }
            cout << endl;
            for (j = 0; j < n; j++) {
                if (m2 & (1 << j)) cout << a[j] << " ";
            }
        }
        cout << endl;
    }

    fclose(stdin); fclose(stdout);
    return 0;   
}