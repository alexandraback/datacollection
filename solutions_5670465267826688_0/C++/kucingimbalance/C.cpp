#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int matrix[4][4] = {
    { 1, 2, 3, 4 },
    { 2, -1, 4, -3 }, 
    { 3, -4, -1, 2 },
    { 4, 3, -2, -1 },
};
inline int mult(int a, int b) {
    int sgn = (a*b) / abs(a*b);
    a = abs(a); b = abs(b);
    --a; --b;
    return sgn * matrix[a][b];
}

string s;
int fwd[10005], bwd[10005];

int main() {
    cin.sync_with_stdio(false);
    int ntc;
    cin >> ntc;
    for (int itc = 1; itc <= ntc; ++itc) {
        int L, X;
        cin >> L >> X >> s;

        for (int i = 0; i < L; ++i) {
            fwd[i] = (i) ? mult(fwd[i-1], s[i]-'g') : s[i]-'g';
        }
        for (int i = L-1; i >= 0; --i) {
            bwd[i] = (i == L-1) ? s[i]-'g' : mult(s[i]-'g', bwd[i+1]);
        }
        int full[4];
        full[0] = 1;
        for (int i = 1; i < 4; ++i) {
            full[i] = mult(full[i-1],fwd[L-1]);
        }

        cout << "Case #" << itc << ": ";
        bool ans = false;
        int visi[10][10];
        memset(visi, 0, sizeof(visi));
        for (int i = 0; i < L; ++i) {
            int ltmp = 1;
            int mfs = (i+1 < L) ? bwd[i+1] : 1;
            if (visi[fwd[i]+4][mfs+4]) continue;
            visi[fwd[i]+4][mfs+4] = 1;
            for (int j = 0; j < L; ++j) {
                int mls = (j-1 >= 0) ? fwd[j-1] : 1;
                if (i < j) {
                    // di segment yg sama       
                    for (int f = 0; f < 4; ++f)
                        for (int l = 0; l < 4; ++l) {
                            int fs = full[f], ms = ltmp, ls = full[l];
                            fs = mult(fs, fwd[i]);
                            ls = mult(bwd[j], ls);

                            if ( (f+l+1) % 4 == X % 4) {
                                if (fs == 2 && ms == 3 && ls == 4)
                                    ans = true;
                            }
                        } 
                    ltmp = mult(ltmp, s[j]-'g');
                }
                // ini di dua segment yg berbeda
                if (X > 1) {
                    for (int f = 0; f < 4; ++f) 
                        for (int l = 0; l < 4; ++l) {
                            int fs = full[f], ls = full[l];
                            fs = mult(fs, fwd[i]);
                            ls = mult(bwd[j], ls);
                            int rem = (X-2-l-f)%4;
                            if (rem < 0) continue;
                            int ms = full[rem];
                            ms = mult(mult(mfs, ms), mls);
                            
                            if (fs == 2 && ms == 3 && ls == 4)
                                ans = true;

                        }
                }
            }
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
