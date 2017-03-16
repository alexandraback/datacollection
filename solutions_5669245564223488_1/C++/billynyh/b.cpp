#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

int DEBUG = 0;
int N = 26;
long long M = 1000000007;

int a[26][26]; 
int solved[26];

long long fact(int x) {
    if (x <=1 ) return 1;
    return (x * fact(x-1)) % M;
}

long long solve(int u) {
    long long t = fact(a[u][u]);
    if (DEBUG) printf("solve %d t:%d\n", u, t);
    solved[u] = true;
    if (t == 0) t = 1;
    for (int i=0;i<N;i++) {
        if (u != i) {
            if (a[u][i]) {
                return (t * solve(i)) %M;
            }
        }
    }
    return t;
}

int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        int n; scanf("%d", &n);

        memset(a, 0, sizeof(a));
        memset(solved, 0, sizeof(solved));

        char s[n][200];
        bool valid = true;
        for (int i=0;i<n;i++) {
            scanf("%s", &s[i]);
        }
        // validate
        // no aba
        // if have abc, b should not appear in other string
        bool middle[26];
        memset(middle, 0, sizeof(middle));
        for (int i=0;i<n;i++) {
            int l = strlen(s[i]);
            int p[200];
            int pn = 0;
            bool vis[26]; memset(vis, 0, sizeof(vis));

            p[0] = s[i][0] - 'a';
            vis[p[0]] = true;
            for (int j=1;j<l;j++) {
                int t = s[i][j] - 'a';
                if (p[pn] != t) {
                    if (vis[t]) {
                        valid = false;
                    } else {
                        pn ++;
                        p[pn] = t;
                        vis[t] = true;
                    }
                }
            }

            pn ++;

            if (DEBUG) {
                printf("- ");
                for (int j=0;j<pn;j++) {
                    printf("%d ", p[j]);
                }
                puts("");
            }

            int st = p[0];
            int ed = p[pn-1];

            bool same = st == ed;
            if (middle[st]) valid = false;
            if (middle[ed]) valid = false;
            for (int j=1;j<pn-1 && valid;j++) {
                if (middle[p[j]]) {
                    valid = false;
                }
                if (p[j] != st || p[j] != ed) {
                    middle[p[j]] = true;
                }
            }


            a[st][ed] ++;
        }


        // count in deg
        int in[N], out[N];
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                if (i != j) {
                    in[i] += a[j][i];
                    out[i] += a[i][j];
                }
            }
            if (in[i] > 1 || out[i] > 1) valid = false;
        }

        if (DEBUG) {
            printf("valid: %d\n", valid);
            for (int i=0;i<N;i++) {
                for (int j=0;j<N;j++) {
                    printf("%d", a[i][j]);
                }
                puts("");
            }
        }
        if (DEBUG) {
            for (int i=0;i<N;i++)printf("%d ", in[i]); puts("");
            for (int i=0;i<N;i++)printf("%d ", out[i]); puts("");
        }

        long long ans = 0;
        long long way[N];
        int component = 0;
        if (valid) {
            for (int i=0;i<N;i++) {
                //printf("i %d: %d %d\n", i, in[i], out[i]);
                if ((in[i] == 0 && out[i] == 1) || (a[i][i] > 0 && in[i]==0)) {
                    way[component] = solve(i);
                    component ++;
                }
            }

            // check cycle
            for (int i=0;i<N;i++) {
                if (a[i][i] > 0 || in[i] > 0 || out[i] > 0) {
                    if (!solved[i]) valid = false;
                }
            }

            if (DEBUG) {
                for (int i=0;i<component;i++) {
                    printf("%lld ", way[i]);
                }
                puts("");
            }

            if (valid) {
                ans = fact(component);
                for (int i=0;i<component;i++) {
                    ans = (ans * way[i]) % M;
                }
            }
        }

        printf("Case #%d: %lld\n",ti,ans);
    }
    return 0;
}
