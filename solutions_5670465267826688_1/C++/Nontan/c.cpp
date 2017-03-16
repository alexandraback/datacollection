#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>

using namespace std;

typedef long long ll;

enum { Q1 = 1, Qi, Qj, Qk };

char c2q(char c) {
    char q = 0;
    switch (c) {
        case '1':
            q = Q1;
            break;
        case 'i':
            q = Qi;
            break;
        case 'j':
            q = Qj;
            break;
        case 'k':
            q = Qk;
            break;
        default:
            assert(false);
            break;
    }
    return q;
}

char sgn(char i) {
    if (i == 0) { assert(false); }
    else if (i < 0) { return -1; }
    return 1;
}

char mul(char l, char r) {
    char la = abs(l);
    char ra = abs(r);
    char p = 1;
    switch (la) {
        case Q1:
            p = ra;
            break;
        case Qi:
            switch (ra) {
                case Q1:
                    p = Qi;
                    break;
                case Qi:
                    p = -Q1;
                    break;
                case Qj:
                    p = Qk;
                    break;
                case Qk:
                    p = -Qj;
                    break;
                default:
                    assert(false);
            }
            break;
        case Qj:
            switch (ra) {
                case Q1:
                    p = Qj;
                    break;
                case Qi:
                    p = -Qk;
                    break;
                case Qj:
                    p = -Q1;
                    break;
                case Qk:
                    p = Qi;
                    break;
                default:
                    assert(false);
            }
            break;
        case Qk:
            switch (ra) {
                case Q1:
                    p = Qk;
                    break;
                case Qi:
                    p = Qj;
                    break;
                case Qj:
                    p = -Qi;
                    break;
                case Qk:
                    p = -Q1;
                    break;
                default:
                    assert(false);
            }
            break;
        default:
            assert(false);
            break;
    }
    p *= sgn(l) * sgn(r);
    return p;
}

char qpow(char q, ll n) {
    char p = 0;
    char qa = abs(q);

    if (qa == Q1) {
        p = 1;
    } else {
        switch (n % 4) {
            case 0:
                p = 1;
                break;
            case 1:
                p = qa;
                break;
            case 2:
                p = -1;
                break;
            case 3:
                p = -qa;
                break;
        }
    }

    if (q < 0 && n % 2 != 0) {
        p = -p;
    }

    return p;
}

int T;
ll L, X;
char S[10001];
char fwd[10000];
char bck[10000];
ll first_x_in_blk[9];
ll last_x_in_blk[9];

bool solve() {
    char p = Q1;
    for (int i = 0; i < L; i++) { fwd[i] = p = mul(p, c2q(S[i])); }

    p = Q1;
    for (int i = L - 1; i >= 0; i--) { bck[i] = p = mul(c2q(S[i]), p); }

    char block = fwd[L - 1];
    if (qpow(block, X) != -Q1) { return false; }

    for (int i = 0; i < 9; i++) {
        first_x_in_blk[i] = last_x_in_blk[i] = -1;
    }

    for (int i = 0; i < L; i++) {
        int index = fwd[i] + 4;
        if (first_x_in_blk[index] == -1) {
            first_x_in_blk[index] = i;
        }
    }

    for (int i = L - 1; i >= 0; i--) {
        int index = bck[i] + 4;
        if (last_x_in_blk[index] == -1) {
            last_x_in_blk[index] = i;
        }
    }

    ll first_i = LLONG_MAX;
    ll last_k = -LLONG_MIN;

    // -Qk, -Qj, -Qi, -Q1, (0), Q1, Qi, Qj, Qk
    for (int i = -4; i <= 4; i++) {
        if (first_x_in_blk[i + 4] != -1) {
            for (ll j = 0; j < min(4ll, X); j++) {
                if (mul(qpow(block, j), i) == Qi) {
                    first_i = min(first_i, first_x_in_blk[i + 4] + L * j);
                }
            }
        }

        if (last_x_in_blk[i + 4] != -1) {
            for (ll j = 0; j < min(4ll, X); j++) {
                if (mul(i, qpow(block, j)) == Qk) {
                    last_k = max(last_k, L * (X - (j + 1)) + last_x_in_blk[i + 4]);
                }
            }
        }
    }

    return first_i + 1 < last_k;
}

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%lld%lld ", &L, &X);
        scanf("%s", S);
        printf("Case #%d: %s\n", i, (solve() ? "YES" : "NO"));
    }
    return 0;
}

