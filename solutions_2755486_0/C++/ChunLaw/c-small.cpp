#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Event {
    int d, w, e, s;
    bool operator< (const Event other) const {
         return d < other.d;
    }
} event[111];

const int os = 223456;
int wall[600000];
bool bb[111];

bool ko(int id) {
    int w = event[id].w;
    int e = event[id].e;
    int s = event[id].s;
    for (int i = w; i <= e; i++)
    if (wall[i] < s)
       return true;
    return false;
    
}

void repair(int id) {
    int w = event[id].w;
    int e = event[id].e;
    int s = event[id].s;
    for (int i = w; i <= e; i++)
    if (wall[i] < s)
    wall[i] = s;
}

int main() {
    int cnt, ee, T, N, d, n, w, e, s, dd, dp, ds;
    scanf("%d", &T);
    for (int k = 1; k <= T; k++) {
        scanf("%d", &N);
        cnt = ee = 0;
        memset(wall, 0, sizeof wall);
        memset(bb, false, sizeof bb);
        for (int i = 0; i < N; i++) {
                scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
                for (int j = 0; j < n; j++) {
                    event[ee++] = (Event) {d, 2*w + os, 2*e + os, s};
                    d += dd;
                    s += ds;
                    w += dp;
                    e += dp;
                }
        }
        sort(event, event + ee);
        event[ee].d = 67726001;
        for (int i = 0, j; i < ee; i = j + 1) {
            j = i;
            while (event[j+1].d == event[i].d) j++;
            for (int l = i; l <= j; l++)
                if (ko(l)) {
                    cnt++;
                    bb[l] = true;
                }
            for (int l = i; l <= j; l++)
                if (bb[l]) repair(l);
            
        }
        printf("Case #%d: %d\n", k, cnt);
    }
    return 0;
}
