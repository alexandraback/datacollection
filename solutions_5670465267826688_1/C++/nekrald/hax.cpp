#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int SZ = 333, BSZ = 11111, CT = 16;

char cmap[SZ][SZ];
short smap[SZ][SZ], prefsign[CT * BSZ], sufsign[CT * BSZ];
char s[CT * BSZ], prefval[CT * BSZ], sufval[CT * BSZ];


void init() {
    cmap['1']['1'] = '1'; smap['1']['1'] = 1;
    cmap['i']['i'] = '1'; smap['i']['i'] = -1;
    cmap['j']['j'] = '1'; smap['j']['j'] = -1;
    cmap['k']['k'] = '1'; smap['k']['k'] = -1;

    cmap['i']['j'] = 'k'; smap['i']['j'] = 1;
    cmap['j']['i'] = 'k'; smap['j']['i'] = -1;

    cmap['i']['k'] = 'j'; smap['i']['k'] = -1;
    cmap['k']['i'] = 'j'; smap['k']['i'] = 1;

    cmap['k']['j'] = 'i'; smap['k']['j'] = -1;
    cmap['j']['k'] = 'i'; smap['j']['k'] = 1;

    cmap['1']['i'] = 'i'; smap['1']['i'] = 1;
    cmap['i']['1'] = 'i'; smap['i']['1'] = 1;

    cmap['1']['j'] = 'j'; smap['1']['j'] = 1;
    cmap['j']['1'] = 'j'; smap['j']['1'] = 1;

    cmap['1']['k'] = 'k'; smap['1']['k'] = 1;
    cmap['k']['1'] = 'k'; smap['k']['1'] = 1;
}

bool solve() {
    memset(s, 0, sizeof(s));
    ll ix; int l, x;
    scanf("%d%lld\n", &l, &ix);
    if (ix > 15) ix = 12 + (ix & 3);
    x = ix; while (x > 12) x -= 4;
    scanf("%s", s + 1);
    for (int i = 1; i < x; ++i) {
        int cdst = i * l;
        memcpy(s + 1 + cdst, s + 1, l);
    }
    prefval[0] = '1'; prefsign[0] = 1;
    sufval[x * l + 1] = '1'; sufsign[x * l + 1] = 1;
    int firi = 0, lstk = 0;
    for (int i = 1; i <= x * l; ++i) {
        prefval[i] = cmap[prefval[i - 1]][s[i]];
        prefsign[i] = prefsign[i - 1] * smap[prefval[i - 1]][s[i]];
        if (prefval[i] == 'i' && !firi) firi = i;
        int ri = x * l - i + 1;
        sufval[ri] = cmap[s[ri]][sufval[ri + 1]];
        sufsign[ri] = sufsign[ri + 1] * smap[s[ri]][sufval[ri + 1]];
        if (sufval[ri] == 'k' && !lstk) lstk = ri;
    }
    return (prefval[x * l] == '1' && prefsign[x * l] == -1 && firi && lstk && firi < lstk);
}

int main() {
    init();
    int T = 0; scanf("%d", &T);
    for (int _ = 1; _ <= T; ++_) {
        printf("Case #%d: ", _);
        if (solve()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}
