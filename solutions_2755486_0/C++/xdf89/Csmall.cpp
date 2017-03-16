#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>

const int INF = 100000000;
const int MAXN = 10;

int N;
int d[MAXN], n[MAXN], w[MAXN], e[MAXN], s[MAXN];
int d_d[MAXN], d_p[MAXN], d_s[MAXN];

std::vector<int> height;
int min_p, max_p;

std::vector<std::pair<int, int> > atk;

bool init() {
    height.clear();
    for (int i = 0; i < max_p - min_p; i ++)
        height.push_back(0);
}

bool attack(int cw, int ce, int cs) {
    cw -= min_p; ce -= min_p;
    for (int i = cw; i < ce; i ++)
        if (height[i] < cs) return true;
    return false;
}

bool update(int cw, int ce, int cs) {
    cw -= min_p; ce -= min_p;
    for (int i = cw; i < ce; i ++)
        height[i] = std::max(height[i], cs);
}

void solve(int ct) {
    std::cin >> N;
    atk.clear();
    min_p = INF; max_p = -INF;
    for (int i = 0; i < N; i ++) {
        std::cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i];
        std::cin >> d_d[i] >> d_p[i] >> d_s[i];

        for (int j = 0; j < n[i]; j ++) {
            int cd = d[i] + d_d[i]*j;
            atk.push_back(std::make_pair(cd, i));
        }

        if (d_p[i] > 0) {
            max_p = std::max(max_p, e[i] + d_p[i]*(n[i]-1));
            min_p = std::min(min_p, w[i]);
        } else {
            max_p = std::max(max_p, e[i]);
            min_p = std::min(min_p, w[i] + d_p[i]*(n[i]-1));
        }
    }
    std::sort(atk.begin(), atk.end());

    init();
    int ans = 0;

    int i = 0;
    while (i < atk.size()) {
        int j = i;
        while (j < atk.size() && atk[i].first == atk[j].first)
            j ++;
        for (int k = i; k < j; k ++) {
            int p = atk[k].second;
            int c = (atk[k].first - d[p]) / d_d[p];
            int cw = w[p]+d_p[p]*c, ce = e[p]+d_p[p]*c;
            int cs = s[p] + d_s[p]*c;
            //printf("%d %d ", p, c);
            //printf("attack %d,%d,%d\n", cw, ce, cs);
            if (attack(cw, ce, cs)) ans ++;
        }
        for (int k = i; k < j; k ++) {
            int p = atk[k].second;
            int c = (atk[k].first - d[p]) / d_d[p];
            int cw = w[p]+d_p[p]*c, ce = e[p]+d_p[p]*c;
            int cs = s[p] + d_s[p]*c;
            update(cw, ce, cs);
        }
        i = j;
    }

    printf("Case #%d: %d\n", ct, ans);
}

int main() {
    int T;
    std::cin >> T;
    for (int ct = 1; ct <= T; ct ++) 
        solve(ct);
}
