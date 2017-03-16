#include <cstdio>
#include <algorithm>
#include <vector>

#define mod 2000003
#define pb push_back
using namespace std;
int n;
long long a[512];
int T;

struct nod {
    vector<int> a;
    long long S;
    nod *n;
};

nod *H[mod];

inline void insert(long long S, vector<int> sol) {
    int h = 0;
    h = int(S % mod);
    nod *p = new nod;
    p->n = H[h];
    p->a = sol;
    p->S = S;
    H[h] = p;
}

void afis(vector<int> &x) {
    for (int i = 0; i < x.size()  - 1; ++i)
        printf ("%lld ", a[x[i]]);
    printf ("%lld\n", a[x[x.size() - 1]]);
}

void rec(nod *p) {
    if (p == NULL) return;
    rec(p->n);
    delete p;
}
void clear_hash() {
    int i;
    for (i = 0; i < mod; ++i) {
        rec(H[i]);
        H[i] = 0;
    }
}
void solve(int test) {
    int i, j, k;

    for (i = 1; i <= n; ++i) {
        vector<int> x;
        x.pb(i);
        insert(a[i], x);
    }

    for (i = 1; i <= n; ++i) {
        vector<int> x;
        for (j = i + 1; j <= n; ++j) {
            x.clear();
            x.pb(i);
            x.pb(j);
            sort(x.begin(), x.end());
            insert(a[i] + a[j], x);
        }
    }

    
    fprintf (stderr, "Begining n^3\n");
    for (i = 1; i <= n; ++i)
        for (j = i + 1; j <= n; ++j)
            for (k = j + 1; k <= n; ++k) {
                vector<int> x;
                x.pb(i);
                x.pb(j);
                x.pb(k);
                sort(x.begin(), x.end());
                insert(a[i] + a[j] + a[k], x);
            }
   
    printf ("Case #%d:\n", test);
    
    for (i = 1; i <= n; ++i) {
        long long S = a[i];
        vector<int> x;
        x.pb(i);
        nod *p;
        int h = int (S % mod);
        for (p = H[h]; p ; p = p->n)
            if (p->S == S && p->a != x) {
                printf ("%lld\n", a[i]);
                afis(p->a);
                clear_hash();
                return;
            }
    }
    
    
    for (i = 1; i <= n; ++i)
        for (j = i + 1; j <= n; ++j) {
            long long S = a[i] + a[j];
            vector<int> x; x.pb(i); x.pb(j); sort(x.begin(), x.end());
            nod *p;
            int h = int(S % mod);
            for (p = H[h]; p ; p = p->n)
                if (p->S == S && p->a != x && x.size() > 0) {
                    afis(x);
                    afis(p->a);
                    clear_hash();
                    return;
                }
        }
    fprintf (stderr, "begining n^3\n"); 
    for (i = 1; i <= n; ++i)
        for (j = i + 1; j <= n; ++j)
            for (k = j + 1; k <= n; ++k) {
                long long S = a[i] + a[j] + a[k];
                vector<int> x; x.pb(i); x.pb(j); x.pb(k); sort(x.begin(), x.end());
                nod *p;
                int h = int(S % mod);
                for (p = H[h]; p; p = p->n)
                    if (p->S == S && p->a != x && x.size() > 0) {
                        afis(x);
                        afis(p->a);
                        clear_hash();
                        return;
                    }
            }

    printf ("Impossible\n");

    clear_hash();
}

int main() {
    freopen ("c.in", "r", stdin);
    freopen ("c.out", "w", stdout);
    scanf ("%d\n", &T);
    for (int test = 1; test <= T; ++test) {
        scanf ("%d ", &n);
        for (int i = 1; i <= n; ++i)
            scanf ("%lld", &a[i]);
        solve(test);
    }
}

