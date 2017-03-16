#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

#define MAXP 10
#define MAXK 16

vector<int> p;
char marca[MAXP];
int r, n, m, k;
int v[MAXK];

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

void criva() {
    memset(marca, 0, sizeof(marca));

    p.push_back(2);
    for (int i = 3; i < MAXP; i += 2) {
        if (marca[i]) continue;

        p.push_back(i);
        for (int j = i*i; j < MAXP; j += i)
            marca[j] = 1;
    }
}

vector<int> fatora(int n) {
    vector<int> ans;

    for (int i = 0; i < (int) p.size(); ++i) {
        int k = 0;
        while (n % p[i] == 0) {
            ++k;
            n /= p[i];
        }

        ans.push_back(k);
    }

    return ans;
}

int main () {
    int casos;
    scanf ("%d", &casos);

    criva();

    for (int caso = 1; caso <= casos; ++caso) {
        printf ("Case #%d:\n", caso);

        scanf ("%d %d %d %d", &r, &n, &m, &k);
        while (r--) {
            int mmc = 1;
            for (int i = 0; i < k; ++i) {
                scanf ("%d", &v[i]);
                mmc = v[i] / gcd(v[i], mmc) * mmc;
            }

            int a = 2, b = 2, c = 2;
            while (a <= m && b <= m && c <= m) {
                bool ok = true;

                for (int i = 0; i < k; ++i) {
                    if (v[i] == 1) continue;
                    if (v[i] == a || v[i] == b || v[i] == c) continue;
                    if (v[i] == a*b || v[i] == a*c || v[i] == b*c) continue;
                    if (v[i] == a*b*c) continue;

                    ok = false;
                    break;
                }

                if (ok) break;

                ++c;
                if (c > m) {
                    ++b;
                    c = b;
                }

                if (b > m) {
                    ++a;
                    b = a;
                    c = b;
                }
            }

            if (a > m) {
                a = 2; b = 2; c = 2;
            }

            printf ("%d%d%d\n", a, b, c);
        }
    }

    return 0;
}

