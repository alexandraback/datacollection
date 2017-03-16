// Ishraq Huda
// fairsquare
// Sat, Apr 13, 2013  1:30:35 PM

#include <cstdio>
#include <cctype>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for(int i=(a);i<(b);i++)
#define FR(i,a,b) for (int i=(a)-1;i>=(b);i--)
#define fi(a) FO(i,0,a)
#define fj(a) FO(j,0,a)
#define fk(a) FO(k,0,a)
#define all(c) (c).begin(), (c).end()
#define fit(c,i) \
    for (typeof((c).begin()) i=(c).begin(); i != (c).end(); i++)
#define sd(n) scanf(" %d ", &(n))

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

vector<ll> palin_sq;
char buff1[200];
char buff2[200];

void gen_palin(int len, int i) {
    if (i > len/2) {
        ll x;
        sscanf(buff1, "%lld", &x);
        x *= x;
        sprintf(buff2, "%lld", x);

        int slen = strlen(buff2);
        for (int j = 0; j < slen; j++) {
            if (buff2[j] != buff2[slen-1-j]) {
                return;
            }
        }
        palin_sq.push_back(x);
    } else {
        for (buff1[i] = (i == 0) + '0'; buff1[i] <= '9'; buff1[i]++) {
            buff1[len-1-i] = buff1[i];
            gen_palin(len, i+1);
        }
    }
}

int main() {
#ifndef DEBUG
    // freopen("fairsquare.in", "r", stdin);
    // freopen("fairsquare.out", "w", stdout);
#endif

    for (int i = 1; i <= 7; i++) {
        gen_palin(i, 0);
    }

    sort(all(palin_sq));

    int T;
    sd(T);
    FO(Z,1,T+1) {
        ll l, u;
        scanf("%lld %lld", &l, &u);
        printf("Case #%d: %d\n", Z, upper_bound(all(palin_sq), u) - lower_bound(all(palin_sq), l));
    }

    return 0;
}

