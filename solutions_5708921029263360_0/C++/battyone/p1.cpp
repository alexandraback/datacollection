#include "std.h"
#define DBGLEVEL 1
#include "debug.h"

char buf[1024];
char ans[1024];
int A, B, C, K;

int cnt[1024];

int prt(int a, int b, int c) { cout << (a + 1) << " " << (b + 1) << " " << (c + 1) << endl; }

void prt(int s) { prt(s / 256 - 1, s % 256 / 16 - 1, s % 16 - 1); }

int id(int i, int a, int b, int c)
{
    return (i == 0 ? 0 : a + 1) * 256 + (i == 1 ? 0 : b + 1) * 16 + (i == 2 ? 0 : c + 1) * 1;
}

VI sol;

int check(int a, int b, int c)
{
    FOR(i, 3) if (cnt[id(i, a, b, c)] >= K) return 0;
    FOR(i, 3) cnt[id(i, a, b, c)]++;
    sol.pb(id(-1, a, b, c));
    return 1;
}

int main() {
    int T;
    cin >> T;
    FOR(tt, T)
    {
        cin >> A >> B >> C >> K;
        cout << "Case #" << (tt + 1) << ": ";

        ZERO(cnt);
        sol.clear();
        int n = 0;
        FOR(a, A) FOR(b, B) FOR(c, C)
            n += check(a, b, c);
        cout << n << endl;
        FOR(i, n) prt(sol[i]);
        //cout << endl;

        next:;       

    }
    return 0;
}
