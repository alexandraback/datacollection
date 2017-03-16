#include <cstdio>
#include <algorithm>
#include <set>
#define scanf(args...) (scanf(args) ? : 0)
const int MAXN = 1e6;

double T1[MAXN], T2[MAXN];

int main() {
    int t;
    scanf("%d", &t);

    for (int test=1; test<=t; test++) {
        int n;
        scanf("%d", &n);
        
        for (int i=0; i<n; i++)
            scanf("%lf", &T1[i]);
        std::sort(T1, T1+n);

        for (int i=0; i<n; i++)
            scanf("%lf", &T2[i]);
        std::sort(T2, T2+n);

        std::set<double> set(T2, T2+n);
        int res1 = 0;
        for (int i=0; i<n; i++) {
            auto it = set.lower_bound(T1[i]);
            if (it == set.end())
                res1++;
            else 
                set.erase(it);
        }
    
        set = std::set<double>(T2, T2+n);
        int res2 = 0;
        for (int i=0; i<n; i++) {
            if (*set.begin() > T1[i]) {
                set.erase(--set.end());
            }
            else {
                set.erase(set.begin());
                res2++;
            }
        }

        printf("Case #%d: %d %d\n", test, res2, res1);
    }
}
