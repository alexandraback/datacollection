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

const int maxn = 1024;

int a[maxn];

int main()
{
    freopen("input.txt" ,"rt", stdin); freopen("output.txt", "wt", stdout);

    int i, j;
    
    int T, sc;
    cin >> T;
    for (sc = 0; sc < T; sc++) {
        int n, s;
        cin >> n;
        s = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        
        cout << "Case #" << sc+1 << ": ";
        cout << fixed << setprecision(6);
        for (i = 0; i < n; i++) {
            double L = 0, R = 100.0;
            while (R-L > 1e-8) {
                double q = (L + R) / 2 / 100.0;
                double v = a[i] + q*s;
                double gave = q;
                for (j = 0; j < n; j++) {
                    if (j == i) continue;
                    if (v > a[j]) {
                        gave += (v-a[j]) / (double)s;
                    }
                }
                if (gave > 1) R = q*100.0; else L = q*100.0;
            }
            cout << L << " ";
        }
        cout << endl;
    }
    
    
    fclose(stdin); fclose(stdout);
    return 0;   
}