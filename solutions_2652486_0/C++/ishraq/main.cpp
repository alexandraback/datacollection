#include <cstdio>
#include <vector>
#include <algorithm>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for(int i=(a);i<(b);i++)
#define fit(c,i) \
    for (typeof((c).begin()) i=(c).begin(); i != (c).end(); i++)

using namespace std;

vector<int> products[6][6][6];

int a[3];
int m, n, K;

void gen(int i) {
    if (i == n) {
        FO(j,0,1<<n) {
            int prod = 1;
            FO(k,0,n) if (j & (1<<k)) {
                prod *= a[k];
            }
            products[a[0]][a[1]][a[2]].push_back(prod);
        }
#define PROD products[a[0]][a[1]][a[2]]
        sort(PROD.begin(),PROD.end());
        PROD.resize(unique(PROD.begin(),PROD.end())-PROD.begin());
        D("%d%d%d:", a[0], a[1], a[2]);
        fit(PROD,it) {
            D(" %d", *it);
        }
        D("\n");
    } else {
        FO(j,i==0?2:a[i-1],m+1) {
            a[i] = j;
            gen(i+1);
        }
    }
}

bool is_in(vector<int> &v, int elem) {
    return lower_bound(v.begin(),v.end(),elem) != v.end() && *lower_bound(v.begin(),v.end(),elem) == elem;
}

int prods[7];
bool find(int i) {
    if (i == 3) {
        FO(j,0,K) if (!is_in(products[a[0]][a[1]][a[2]],prods[j])) {
            return false;
        }
        return true;
    } else {
        FO(j,i==0?2:a[i-1],m+1) {
            a[i] = j;
            if (find(i+1)) return true;
        }
        return false;
    }
}

int main() {
#ifndef DEBUG
    // freopen("luck.in", "r", stdin);
    // freopen("luck.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    scanf("%d", &T);
    scanf("%d %d %d", &n, &m, &K);

    gen(0);

    printf("Case #1:\n");
    FO(Z,0,T) {
        FO(i,0,K) scanf("%d", &prods[i]);
        find(0);
        printf("%d%d%d\n", a[0], a[1], a[2]);
    }

    return 0;
}

