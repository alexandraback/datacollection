#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 100, MAXL = 1000, MOD = 1000000007;

int NQ, out[26], from[26], d[26];
bool mark[26];

bool add(char *st)
{
    int L = strlen(st);

    if (st[0] == st[L-1]) {
        for (int i = 1; i < L-1; ++i)
            if (st[i] != st[0]) return false;

        mark[st[0]-'a'] = true;
        ++d[st[0]-'a'];
    } else {
        int l = 1, r = L-2;
        while (l < L && st[l] == st[0]) ++l;
        while (r >= 0 && st[r] == st[L-1]) --r;

        mark[st[0]-'a'] = mark[st[L-1]-'a'] = true;

        for (int i = l; i <= r; ++i) {
            if (st[i] == st[i-1]) continue;
            if (mark[st[i]-'a']) return false;
            mark[st[i]-'a'] = true;
        }

        if (out[st[0]-'a'] != -1) return false;
        out[st[0]-'a'] = st[L-1]-'a';

        if (from[st[L-1]-'a'] != -1) return false;
        from[st[L-1]-'a'] = st[0]-'a';
    }

    return true;
}

int main()
{
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        printf("Case #%d: ", t+1);

        int N; scanf("%d", &N);
        char st[MAXL+1];

        bool good = true;

        fill(mark, mark+26, false);
        fill(from, from+26, -1);
        fill(out, out+26, -1);
        fill(d, d+26, 0);

        for (int i = 0; i < N; ++i) {
            scanf("%s", st);
            if (!add(st)) good = false;
        }

        if (!good) { printf("0\n"); continue; }

        long long res = 1;
        for (int i = 0; i < 26; ++i)
            for (int j = 2; j <= d[i]; ++j) res = (res*j) % MOD;

        fill(mark, mark+26, false);
        int NQ = 0;

        for (int i = 0; i < 26; ++i)
            if (!mark[i] && (d[i] > 0 || from[i] != -1)) {
                ++NQ;

                int j = i;
                while (from[j] != i && from[j] != -1) j = from[j];

                if (from[j] == i) { good = false; break; }
                while (j != -1) { mark[j] = true; j = out[j]; }
            }

        if (!good) { printf("0\n"); continue; }

        for (int j = 2; j <= NQ; ++j) res = (res*j) % MOD;

        printf("%lld\n", res);
    }

    return 0;
}
