#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define iter(v, i) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const double eps = 1e-9;
const double pi = 3.141592653589793238462;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("C-small.in", "rt", stdin);
    freopen("C-small.out", "wt", stdout);
    int t, tc = 1;

    scanf("%d", &t);

    while (t--) {
        int j, p, s, k;
        scanf("%d %d %d %d", &j, &p, &s, &k);

        vector<pair<ii, int> > foo;
        pair<ii, int> prev = mp(mp(0, 0), 0);
        map<ii, int> seen_ab, seen_ac, seen_bc;
        int ans = 0;
        while (ans < 10000) {
            bool found = false;
            for (int a = 1; a <= j; a++)
                for (int b = 1; b <= p; b++)
                    for (int c = 1; c <= s; c++) {
                        //printf("next: %d %d %d\n", a, b, c);
                        if (prev == mp(mp(a, b), c))
                            continue;
                        if (seen_ab[mp(a, b)] == k)
                            continue;
                        if (seen_ac[mp(a, c)] == k)
                            continue;
                        if (seen_bc[mp(b, c)] == k)
                            continue;
                        found = true;
                        prev = mp(mp(a, b), c);
                        seen_ab[mp(a, b)]++;
                        seen_ac[mp(a, c)]++;
                        seen_bc[mp(b, c)]++;
                        goto stop;
                    }
            stop: ;
            if (!found) break;
            foo.pb(prev);
            ans++;
        }

        printf("Case #%d: %d\n", tc++, ans);

        iter(foo, it)
            printf("%d %d %d\n", it->fi.fi, it->fi.se, it->se);
    }

    return 0;
}

