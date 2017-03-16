#include <bits/stdc++.h>
using namespace std;

const int maxN = 1111;

int n, a[maxN];

int main(){
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int t, cases = 0; scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        int all = 0, res = 0;
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        sort(a, a + n, greater<int>());
        res = a[0];

        for (int l = 1; l < a[0]; l++){
            int all = l, A;
            for (int i = 0; i < n; i++) all += (a[i]-1)/l;
            res = min(res, all);
        }

        printf("Case #%d: %d\n", ++cases, res);
    }
    return 0;
}

