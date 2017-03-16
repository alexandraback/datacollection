#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define ll long long
#define point pair<double, double>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define uint unsigned int
#define double long double
#define merge botva
#define M_PI 3.14159265358979323846

const int maxn = 120, maxt = 100020, INF = 1200000000;

int gi;

int n, m, minf;
int fr[maxn], fc[maxn], a[maxn][maxn];

bool good() {
        for (int i = 0; i < n; ++i) {
                fr[i] = 1;
                for (int j = 0; j < m; ++j)
                        if (a[i][j] != minf) fr[i] = 0;
        }
        for (int i = 0; i < m; ++i) {
                fc[i] = 1;
                for (int j = 0; j < n; ++j)
                        if (a[j][i] != minf) fc[i] = 0;
        }
        for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                        if (a[i][j] == minf && !fr[i] && !fc[j]) return 0;
        return 1;
}

int main() {
        //freopen("ellipse.in", "r", stdin);
        //freopen("ellipse.out", "w", stdout);

        int t;
        scanf("%d\n", &t);
        for (gi = 1; gi <= t; ++gi) {
                cin >> n >> m;
                for (int i = 0; i < n; ++i)
                        for (int j = 0; j < m; ++j)
                                cin >> a[i][j];
                minf = 1;
                while (1) {
                        if (good()) {
                                int hm = 0;
                                for (int i = 0; i < n; ++i)
                                        for (int j = 0; j < m; ++j)
                                                if (a[i][j] == minf) ++a[i][j], ++hm;
                                ++minf;
                                if (hm == n * m) {
                                        printf("Case #%d: YES\n", gi);
                                        break;
                                }
                        } else {
                                //cout << "bad minf " << minf << endl;
                                        printf("Case #%d: NO\n", gi);
                                        break;
                        }
                }
        }
}
