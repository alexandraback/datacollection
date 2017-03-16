#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

typedef long long ll;

int table[4][4] = {
    { 0, 1, 2, 3 },
    { 1, 0, 3, 2 },
    { 2, 3, 0, 1 },
    { 3, 2, 1, 0 },
};

int sgntable[4][4] = {
    { 1, 1, 1, 1 },
    { 1, -1, 1, -1 },
    { 1, -1, -1, 1 },
    { 1, 1, -1, -1 },
};

struct Q {
    int sgn;
    int val;

    Q() : sgn(1), val(0) {}
    Q(int sgn, int val) : sgn(sgn), val(val) {}

    Q operator*(Q a) {
        int nextsgn = sgn * a.sgn * sgntable[val][a.val];
        int nextval = table[val][a.val];

        return Q(nextsgn, nextval);
    }
};

void printq(Q q) {
    if (q.sgn == -1) {
        cout << "-";
    }
    
    switch (q.val) {
        case 0:
            cout << 1;
            break;
        case 1:
            cout << "i";
            break;
        case 2:
            cout << "j";
            break;
        case 3:
            cout << "k";
            break;
    }
}

struct Mul {
    Q E;
    Mul() : E(1, 0) {}
    Q operator()(Q a, Q b) {
        return a * b;
    }   
};

template<int N, typename T, typename B>
struct segtree {
    T dat[N * 2];
    B bin;
    segtree() {
        fill_n(dat, N * 2, bin.E);
    }
    void init() {
        fill_n(dat, N * 2, bin.E);
    }
    void update(int k, T x) {
        k += N - 1;
        dat[k] = x;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = bin(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    T query(int k, int l, int r, int a, int b) {
        if (r <= a || b <= l) return bin.E;
        if (a <= l && r <= b) return dat[k];
        T vl = query(k * 2 + 1, l, (l + r) / 2, a, b);
        T vr = query(k * 2 + 2, (l + r) / 2, r, a, b);
        return bin(vl, vr);
    }
    T query(int a, int b) {
        return query(0, 0, N, a, b);
    }
};

segtree<1 << 18, Q, Mul> tree;

char str[20000];

bool solve(int L, ll X) {
    tree.init();
    int XL = L * min(X, 12 + X % 12);

    for (int i = 0; i < XL; i++) {
        switch (str[i % L]) {
            case 'i':
                tree.update(i, Q(1, 1));
                break;
            case 'j':
                tree.update(i, Q(1, 2));
                break;
            case 'k':
                tree.update(i, Q(1, 3));
                break;
        }
    }

    int pos1 = 0;
    
    for (int i = 1; i < XL; i++) {
        Q q = tree.query(0, i);

        if (q.sgn == 1 && q.val == 1) {
            pos1 = i;
            break;
        }
    }

    if (pos1 == 0) return false;

    int pos2 = 0;

    for (int i = pos1 + 1; i < XL; i++) {
        Q q = tree.query(pos1, i);

        if (q.sgn == 1 && q.val == 2) {
            pos2 = i;
            break;
        }
    }

    if (pos2 == 0) return false;

    Q right = tree.query(pos2, XL);

    return right.sgn == 1 && right.val == 3;
}

int main() {
    int T;
    cin >> T;
    
    for (int k = 1; k <= T; k++) {
        ll L, X;
        scanf("%lld%lld%s", &L, &X, str);

        printf("Case #%d: %s\n", k, solve(L, X) ? "YES" : "NO");
    }
}
