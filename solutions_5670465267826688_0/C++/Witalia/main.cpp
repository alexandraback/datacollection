#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

struct cplx {
    bool negative;
    int value;
};

const string seq = "1ijk";

// 1 -> 0, i -> 1, j -> 2, k -> 3
cplx mul_matr[4][4] = {
    { {false, 0}, {false, 1}, {false, 2}, {false, 3} },         //  1   i   j   k
    { {false, 1}, { true, 0}, {false, 3}, { true, 2} },         //  i  -1   k  -j
    { {false, 2}, { true, 3}, { true, 0}, {false, 1} },         //  j  -k  -1   i
    { {false, 3}, {false, 2}, { true, 1}, { true, 0} },         //  k   j  -i  -1
};
cplx cplx_one = {false, 0};

cplx operator* (cplx a, cplx b) {
    cplx res = mul_matr[a.value][b.value];
    res.negative ^= a.negative ^ b.negative;
    return res;
}
bool operator== (cplx a, cplx b) {
    return a.negative == b.negative && a.value == b.value;
}
bool operator!= (cplx a, cplx b) { return !(a==b); }
int to_int(cplx a) { return seq.size() * a.negative + a.value; }

const int period = 4;
string s;
vector<cplx> vals[2];
vector<cplx> a;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cout << "Case #" << (t + 1) << ": ";

        int l, x;
        cin >> l >> x >> s;
        a.resize(l);
        for (int i = 0; i < l; ++i)
            a[i] = cplx{false, seq.find(s[i % s.size()])};

        x = min(x, period * 3 + x % period);
        l *= x;

        for (int i = 0; i < 2; ++i)
            vals[i].resize(l);
        for (int i = 0, j = l - 1; i < l; ++i, --j) {
            vals[0][i] = (!i ? cplx_one : vals[0][i - 1]) * a[i % s.size()];
            vals[1][j] = a[j % s.size()] * (!i ? cplx_one : vals[1][j + 1]);
        }

        int pos1 = l, pos2 = -1;
        for (int i = 0; i < l; ++i) {
            if (i + 1 < l && vals[0][i] == cplx{false, 1}/* i */
                && vals[1][i + 1] == cplx{false, 2}*cplx{false, 3} /* j*k */)
            {
                pos1 = min(pos1, i);
            }
            if (i > 0 && vals[1][i] == cplx{false, 3}/* k */
                && vals[0][i - 1] == cplx{false, 1}*cplx{false, 2}/* i*j */)
            {
                pos2 = max(pos2, i);
            }
        }
        cout << (pos1 + 1 < pos2 ? "YES" : "NO") << endl;
    }

    return 0;
}
