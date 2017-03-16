#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

using namespace std;

const int maxn = 55;
const int maxl = maxn * maxn * 4;
const int maxv = maxl * maxn;
const double eps = 1e-11;

int n;
bool side[maxn];
int speed[maxn];
int pos[maxn];

int fa[maxv];
bool color[maxv];

void clearF()
{
    memset(fa, -1, sizeof(fa));
    memset(color, false, sizeof(color));
}

int getF(int a)
{
    if (fa[a] == -1) {
        return a;
    }
    int r = getF(fa[a]);
    if (color[a]) {
        color[a] = !color[fa[a]];
    } else {
        color[a] = color[fa[a]];
    }
    fa[a] = r;
    return r;
}

bool mergeF(int a, int b)
{
    if (getF(a) == getF(b)) {
        if (color[a] == color[b])
            return false;
    } else {
        bool flag = true;
        if (color[a])
            flag = !flag;
        if (color[b])
            flag = !flag;
        a = getF(a);
        b = getF(b);
        fa[a] = b;
        color[a] = flag;
    }
    return true;
}

bool double_equal(double a, double b)
{
    return fabs(a - b) < eps;
}

int nvars;
int lastVar[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &n);
        char buf[10];
        for (int i = 0; i < n; i++) {
            scanf("%s%d%d", buf, speed + i, pos + i);
            side[i] = *buf == 'L';
        }
        vector<double> events;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++) {
                for (int dx = -1; dx <= 1; dx += 2) {
                    if (speed[i] != speed[j]) {
                        double t = (pos[i] + dx * 5.0 - pos[j]) / (speed[j] - speed[i]);
                        if (t > eps) {
                            events.push_back(t);
                            events.push_back(t + 1e-6);
                        }
                    }
                }
            }
        sort(events.begin(), events.end());
        events.erase(unique(events.begin(), events.end(), double_equal), events.end());
        clearF();
        nvars = 2;
        mergeF(0, 1);
        for (int i = 0; i < n; i++) {
            lastVar[i] = nvars++;
            mergeF(lastVar[i], side[i] ? 0 : 1);
        }
        double ans = -1;
        for (int i = 0; i < events.size(); i++) {
            double t = events[i];
            vector<pair<double, int> > V;
            for (int j = 0; j < n; j++)
                V.push_back(make_pair(pos[j] + speed[j] * t, j));
            sort(V.begin(), V.end());
            for (int j = 0; j < V.size(); j++) {
                bool safe = true;
                if (j > 0 && V[j].first - V[j-1].first + eps < 5)
                    safe = false;
                if (j + 1 < n && V[j+1].first - V[j].first + eps < 5)
                    safe = false;
                //printf("%.10lf %d %d\n", V[j].first, V[j].second, (int)safe);
                if (safe) {
                    lastVar[V[j].second] = nvars++;
                }
            }
            bool found = false;
            for (int j = 0; j < V.size(); j++) {
                for (int k = j + 1; k < V.size(); k++) {
                    if (V[k].first - V[j].first + eps < 5) {
                        if (!mergeF(lastVar[V[k].second], lastVar[V[j].second])) {
                            found = true;
                            break;
                        }
                    }
                    if (V[k].first > V[j].first + 5 + eps)
                        break;
                }
            }
            if (found) {
                ans = t;
                break;
            }
        }
        if (ans < 0)
            printf("Case #%d: Possible\n", cas);
        else
            printf("Case #%d: %.10lf\n", cas, ans);
    }
}
