#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

class Q {
public:
    int w,x,y,z;
    Q(): w(0),x(0),y(0),z(0) {}
    Q(int w, int x, int y, int z): w(w),x(x),y(y),z(z) {}
    Q(char c) {
        w=x=y=z=0;
        if (c == 'i') x=1;
        if (c == 'j') y=1;
        if (c == 'k') z=1;
    }
    Q operator*(const Q & p) const { 
        return Q(this->w * p.w - this->x * p.x - this->y * p.y - this->z * p.z,
                 this->w * p.x + this->x * p.w + this->y * p.z - this->z * p.y,
                 this->w * p.y + this->y * p.w + this->z * p.x - this->x * p.z,
                 this->w * p.z + this->z * p.w + this->x * p.y - this->y * p.x
    ); }
    bool operator==(const Q & p) const {
        return this->w == p.w && this->x == p.x && this->y == p.y && this->z == p.z;
    }
};

Q id() {
    return Q(1,0,0,0);
}

Q mpow(Q x, ll n) {
    Q res = id();
    while (n) {
        if (n & 1) res = res * x;
        x = x * x;
        n /= 2;
    }
    return res;
}

void out(const Q & q) {
    cerr << q.w << ',' << q.x << ',' << q.y << ',' << q.z << endl;
}

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        printf("Case #%d: ", test);
        int n,x; string s;
        cin >> n >> x >> s;
        if (x <= 10) {
            string s1 = s;
            for (int i = 0; i < x-1; ++i) s1 += s;
            n *= x;
            x = 1;
            s.swap(s1);
        }
        vector<Q> v(n);
        Q totprod = id();
        for (int i = 0; i < n; ++i) {
            v[i] = Q(s[i]);
            totprod = totprod * v[i];
        }
//        out(totprod);
//        out(mpow(totprod, x));
        if (mpow(totprod, x) == Q(-1,0,0,0)) {
            vi hasi(n);
            vi hask(n);
            Q prod = id();
            bool oki = 0, okk = (totprod == 0);
            for (int i = 0; i < n; ++i) {
                prod = prod * v[i];
                Q I(0,1,0,0);
                if (prod == I) {
                    hasi[i] = 1;
                    oki = 1;
                }
                if ((totprod * prod) == I || (totprod * totprod * prod == I) || (totprod * totprod * totprod * prod == I))
                    oki = 1;
            }
            prod = id();
            for (int i = n-1; i >= 0; --i) {
                prod = v[i] * prod;
                Q K(0,0,0,1);
                if (prod == K) {
                    hask[i] = 1;
                    okk = 1;
                }
                if (prod * totprod == K || prod * totprod * totprod == K || prod * totprod * totprod * totprod == K)
                    okk = 1;
            }
            bool ok = 0;
            if (x == 1) {
                bool has = 0;
                for (int i = 0; i < n; ++i) {
                    if (hask[i] && has) {
                        ok = 1;
                        break;
                    }
                    has |= hasi[i];
                }
            } else {
                ok = oki && okk;
            }
            if (ok) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
