#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 1e4+10, SIZE = 110;

map<char, int> dict {{'1', 1}, {'i', 2}, {'j', 3}, {'k', 4}};

int table[][4] = {{1,  2,  3,  4},
                  {2, -1,  4, -3},
                  {3, -4, -1,  2},
                  {4,  3, -2, -1}};

struct Quaternion {
    int value;
    Quaternion(char c) { value = dict[c]; }
    Quaternion(int v) { value = v; }
    Quaternion(){};
    Quaternion operator* (Quaternion that) {
        int res = table[abs(value)-1][abs(that.value)-1];
        if(value < 0) res *= -1;
        if(that.value < 0) res *= -1;
        return Quaternion(res);
    }
    Quaternion operator*= (Quaternion that) {
        Quaternion ret = Quaternion(value) * that;
        value = ret.value;
        return ret;
    }
    Quaternion inv() { return Quaternion(abs(value) == 1 ? value : -value); }
    bool operator< (Quaternion that) const { return value < that.value; }
    bool operator==(Quaternion that) const { return value == that.value; }
    bool operator!=(Quaternion that) const { return value != that.value; }
    bool operator==(int that) const { return value == that; }
    bool operator!=(int that) const { return value != that; }
};

typedef pair<Quaternion, Quaternion> pqq;

Quaternion v[MAXN];
Quaternion pot[4];
int bucket[SIZE][10][10];
pqq acc[MAXN];
int n, q;

bool find(int pos, Quaternion ql, Quaternion qr) {
    int cur = (n-1) - ((n-1)%SIZE);
    int idx = cur / SIZE;
    pqq target(ql, qr);
    int q1 = ql.value + 4, q2 = qr.value + 4;
    while(cur >= pos) {
        if(bucket[idx][q1][q2])
            return 1;
        cur -= SIZE;
        idx--;
    }
    cur = min(cur+SIZE, n-1);
    for(int i = pos; i < cur; i++)
        if(acc[i] == target)
            return true;
    return false;
}

int main() {
    int t=1, T;
    for(scanf("%d",&T); t <= T; ++t) {
        memset(bucket,0,sizeof(bucket));
        scanf("%d%d", &n, &q);
        Quaternion total(1);
        for(int i = 0; i < n; i++) {
            char c;
            scanf(" %c",&c);
            v[i] = Quaternion(c);
            total *= v[i];
        }
        pot[0] = Quaternion(1);
        for(int i = 1; i < 4; i++)
            pot[i] = pot[i-1] * total;        
        Quaternion tmp(1);
        for(int i = 0; i < n; i++) {
            tmp *= v[i];
            acc[i] = pqq(tmp, tmp.inv() * total);
            bucket[i/SIZE][acc[i].first.value + 4][acc[i].second.value + 4] = 1;
        }
        bool found = 0;
        int l, r;
        Quaternion ql, qr;
        for(l = 0, ql = Quaternion(1); l < 4 && !found; l++, ql *= total) {
            for(r = 0, qr = Quaternion(1); r < 4 && !found; r++, qr *= total) {
                int m = ((q - l - r - 2)%4 + 4)%4;
                int m2 = ((q - l - r - 1)%4 + 4)%4;
                Quaternion qm = pot[m];
                for(int i = 0; i < n; i++) {
                    if(ql * acc[i].first != Quaternion('i')) continue;
                    if(l + r + m + 2 <= q && find(0, (acc[i].second * qm).inv() * Quaternion('j'), Quaternion('k') * qr.inv())) {                        
                        found = 1;
                        break;
                    }
                    if(m2 == 0 && l + r + 1 <= q && find(i+1, acc[i].first * Quaternion('j'), Quaternion('k') * qr.inv())) {
                        found = 1;
                        break;
                    }
                }
            }
        }
        printf("Case #%d: %s\n", t, found ? "YES" : "NO");                
    }        
    return 0;
}
