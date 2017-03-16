#include <cstdio>
#include <algorithm>
using namespace std;
int n, s, p;

int notSpri(int x) {
    if (x % 3 == 0) {
        return x / 3;
    } else if (x % 3 == 1) {
        return x / 3 + 1;
    } else if (x % 3 == 2) {
        return x / 3 + 1;
    }
}

int Spri(int x) {
    if (x % 3 == 0)
        return x / 3 + 1;
    else if (x % 3 == 1) {
        return x / 3 + 1;
    } else if (x % 3 == 2) {
        return x / 3 + 2;
    }
}

struct node {
    int sco;
    int r;
    bool can = true;

    void read() {
        scanf("%d", &sco);
        if (sco <= 1)can = false;
        else {
            can = true;
            r = (Spri(sco) >= p) - (notSpri(sco) >= p);
        }
    }

    bool operator<(const node & a)const {
        if (can != a.can)
            return can > a.can;
        else if (r != a.r)return r > a.r;
        else return notSpri(sco) < notSpri(a.sco);
    }
} data[105];

int main() {
    freopen("in", "r", stdin);
    freopen("out","w",stdout);
    int T;
    scanf("%d", &T);
    int cas = 1;
    while (T--) {
        scanf("%d%d%d", &n, &s, &p);
        for (int i = 0; i < n; i++)
            data[i].read();
        sort(data, data + n);
        int ans = 0;
        for (int i = 0; i < s; i++)
            ans += Spri(data[i].sco) >= p;
        for (int i = s; i < n; i++)
            ans += notSpri(data[i].sco) >= p;
        printf("Case #%d: %d\n", cas++, ans);
    }
}