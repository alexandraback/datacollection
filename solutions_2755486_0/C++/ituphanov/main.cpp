#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>

using namespace std;

typedef double real;
typedef long long TT;

#define PB push_back
#define SQR(x) ((x)*(x))
#define PII pair<int, int>
#define VI vector<int>
#define VVI vector<VI >
#define VS vector<string>
#define VTT vector<TT>
#define VR vector<real>
#define A first
#define B second

struct attack
{
    int d, L, R, s;
    attack(int _d, int _L, int _R, int _s): d(_d), L(_L), R(_R), s(_s) {}
};

bool lss(const attack& a, const attack& b)
{
    return a.d < b.d;
}

const int maxn = 1000;
const int SZ = 1000;
const int off = 500;

vector<attack> a;
int ans;
int paint[SZ];

int success(int L, int R, int s)
{
    for (int i = L; i <= R; i++)
        if (paint[i+off] < s) return 1;
    return 0;
}

int update(int L, int R, int s)
{
    for (int i = L; i <= R; i++)
        paint[i+off] = max(paint[i+off], s);
}

void process(int L, int R)
{
    for (int i = L; i <= R; i++) {
        ans += success(a[i].L, a[i].R, a[i].s);
    }
    for (int i = L; i <= R; i++) {
        update(a[i].L, a[i].R, a[i].s);
    }
}

int main()
{
    int T;
    cin >> T;
    for (int sc = 0; sc < T; sc++) {
        memset(paint, 0, sizeof(paint));
        a.clear();

        int i, j;
        int N;
        cin >> N;
        for (i = 0; i < N; i++) {
            int d, n, w, e, s, dd, dp, ds;
            cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
            for (j = 0; j < n; j++) {
                a.PB(attack(d+j*dd, w+j*dp, e+j*dp-1, s+j*ds));
            }
        }
        sort(a.begin(), a.end(), lss);

        j = 0;
        ans = 0;
        for (i = 1; i < a.size(); i++) {
            if (a[i].d != a[i-1].d) {
                process(j, i-1);
                j = i;
            }
        }
        process(j, a.size()-1);

        cout << "Case #" << sc+1 << ": ";
        cout << ans;
        cout << endl;
    }

    return 0;
}
