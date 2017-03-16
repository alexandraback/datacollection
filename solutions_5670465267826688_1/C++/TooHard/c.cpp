#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define INF (0x3f3f3f3f)

#define SZ(x) ((int)((x).size()))
#define PB(x) push_back(x)
#define MEMSET(x,v) memset(x,v,sizeof(x))
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))

typedef long long LL;
typedef pair<int, int> PII; typedef pair<PII, int> PII2;

#define MAXL (10005)

int L;
LL X;
int in[MAXL];

// i = 2, j = 3, k = 4;
int table[5][5] = {{0, 0, 0, 0, 0},
                   {0, 1, 2, 3, 4},
                   {0, 2, -1, 4, -3},
                   {0, 3, -4, -1, 2},
                   {0, 4, 3, -2, -1}};

int mult(int a, int b) {
    int sign = 1;
    if (a < 0) sign *= -1;
    if (b < 0) sign *= -1;
    return table[abs(a)][abs(b)] * sign;
}

int pre_mult[MAXL];
int pre_mult2[MAXL];

int mult_from_a_to_b(int a, int b) {
    for (int i = -4; i <= 4; i++) {
        if (i == 0) continue;
        if (mult(pre_mult[a - 1], i) == pre_mult[b])
            return i;
    }
    assert(false);
    return 0;
}

// solve: b * x = a
int bxa(int a, int b) {
    for (int i = -4; i <= 4; i++) {
        if (i == 0) continue;
        if (mult(b, i) == a) {
            return i;
        }
    }
    assert(false);
    return 0;
}
// solve: x * b = a
int xba(int a, int b) {
    for (int i = -4; i <= 4; i++) {
        if (i == 0) continue;
        if (mult(i, b) == a) {
            return i;
        }
    }
    assert(false);
    return 0;
}

int mypow(int a, LL exp) {
    if (exp == 0) return 1;
    int temp = mypow(a, exp / 2);
    temp = mult(temp, temp);
    if (exp % 2) temp = mult(temp, a);
    return temp;
}

LL check(LL pos) {
    if (pos < 1LL * X * L) return pos;
    return -1;
}

LL gen_i() {
    for (int i = 1; i <= L; i++) {
        if (pre_mult[i] == 2) return check(i - 1);
    }
    int pre = 1;
    for (int use = 1; use <= 3; use++) {
        pre = mult(pre, pre_mult[L]);
        int x = bxa(2, pre);
        for (int i = 1; i <= L; i++) {
            if (pre_mult[i] == x) return check(L * use + i - 1);
        }
    }
    return -1;
}

LL gen_k() {
    for (int i = L; i >= 1; i--) {
        if (pre_mult2[i] == 4) return check(1LL * (X - 1) * L + i - 1);
    }
    int pre = 1;
    for (int use = 1; use <= 3; use++) {
        pre = mult(pre_mult2[1], pre);
        int x = xba(4, pre);
        for (int i = L; i >= 1; i--) {
            if (pre_mult2[i] == x) return check(1LL * X * L - 1LL * use * L - L + i - 1);
        }
    }
    return -1;
}

void solve() {
    cin >> L >> X;
    string s;
    cin >> s;
    REP(i, L) {
        if (s[i] == 'i') in[i + 1] = 2;
        else if (s[i] == 'j') in[i + 1] = 3;
        else in[i + 1] = 4;
    }
    //    for (int i = 1; i <= L; i++) cout << in[i] << " ";
    //    cout << endl;
    pre_mult[0] = 1;
    for (int i = 1; i <= L; i++) {
        pre_mult[i] = mult(pre_mult[i - 1], in[i]);
    }
    pre_mult2[L + 1] = 1;
    for (int i = L; i >= 1; i--) {
        pre_mult2[i] = mult(in[i], pre_mult2[i + 1]);
    }
    LL pos1 = gen_i();
    LL pos2 = gen_k();
    if (pos1 == -1 || pos2 == -1 || pos1 + 1 >= pos2) {
        printf("NO\n");
        return ;
    }

    LL num_seg1 = pos1 / L;
    LL num_seg2 = pos2 / L;
    int res;
    if (num_seg1 == num_seg2) {
        pos1 %= L;
        pos2 %= L;
        res = mult_from_a_to_b(pos1 + 2, pos2);
    } else {
        pos1 %= L;
        pos2 %= L;
        res = 1;
        res = mult(res, mult_from_a_to_b(pos1 + 2, L));
        res = mult(res, mypow(mult_from_a_to_b(1, L), num_seg2 - num_seg1 - 1));
        res = mult(res, mult_from_a_to_b(1, pos2));
    }
    if (res == 3) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int test;
    cin >> test;
    REP(t, test) {
        printf("Case #%d: ", t + 1);
        solve();
    }
    
    return 0;
}
