//
//  ijk.cpp
//  
//
//  Created by John Nevard on 4/11/15.
//
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> VI;

enum {E, I, J, K, II, KJ, IK, JI};

const int inv[] = {E, KJ, IK, JI, II, I, J, K};
const int mm[][4] = {
    {E, I,  J,  K},
    {I, II, K,  IK},
    {J, JI, II, I},
    {K, J,  KJ, II}
};

int mul(int x, int y) {
    if (x < II && y < II)
        return mm[x][y];
    if (x < II)
        return II + mm[x][y - II] & 7;
    if (y < II)
        return II + mm[x - II][y] & 7;
    return mm[x - II][y - II];
}

VI convert(const string& s) {
    VI a(s.size());
    for (int i = 0; i < s.size(); ++i)
        switch (s[i]) {
        case 'i':
                a[i] = I; break;
        case 'j':
                a[i] = J; break;
        case 'k':
                a[i] = K; break;
        }
    return a;
}

bool ijk(const VI& b, long long x) {
    int l = b.size();
    VI a(l);
    a[0] = b[0];
    for (int i = 1; i < l; ++i)
        a[i] = mul(a[i - 1], b[i]);
    int blk = a[l - 1];
    int xm4 = (int) (x & 3);
    if (xm4 == 0) return false;
    int prod = E;
    for (int i = 0; i < xm4; ++i)
        prod = mul(prod, blk);
    if (prod != II)
        return false;
    int i0 = -1;
    int p = E;
    for (int k = 0; k < 4 && i0 < 0; ++k) {
        for (int i = 0; i < l && i0 < 0; ++i) {
            if (mul(p, a[i]) == I)
                i0 = k * l + i;
        }
        p = mul(p, blk);
    }
    if (i0 < 0 || i0 >= l * x)
        return false;
    
    p = E;
    long long k0 = -1;
    for (int k = 0; k < 4 && k < x && k0 == -1; ++k) {
        for (int i = l - 1; i >= 1 && k0 == -1; --i)
            if (mul(mul(inv[a[i - 1]], blk), p) == K)
                k0 = l * (x - k - 1) + i;
        if (mul(blk, p) == K)
            k0 = l * (x - k - 1);
        p = mul(blk, p);
    }
    return k0 > i0;
}

int main() {
    int n_cases;
    cin >> n_cases;
    for (int c = 1; c <= n_cases; ++c) {
        int l;
        long long x;
        cin >> l >> x;
        string s;
        cin >> s;
        VI b = convert(s);
        bool answer = ijk(b, x);
        cout << "Case #" << c << ": " << (answer ? "YES" : "NO") << '\n';
    }
    return 0;
}