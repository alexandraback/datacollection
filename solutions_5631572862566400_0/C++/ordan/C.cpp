#include <bits/stdc++.h>

using namespace std;

int bf[1001];

bool ok (int *p, int n){
    for (int i = 2; i < n; i++)
        if (bf[p[i]] != p[i + 1] && bf[p[i]] != p[i - 1])
            return false;
    if (bf[p[1]] != p[2] && bf[p[1]] != p[n]) return false;
    if (bf[p[n]] != p[n-1] && bf[p[n]] != p[1]) return false;
    return true;
}

int main(){
    int t, c = 1;
    scanf ("%d", &t);

    while (t--){
        printf ("Case #%d: ", c++);
        int p[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int n;
        scanf ("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf ("%d", bf + i);
        }
        int ans = 0;
        do{
            for (int i = 2; i <= n; i++) if (ok(p, i)){
                ans = max (ans, i);
                }
        } while (next_permutation(p + 1, p + n + 1));
        printf ("%d\n", ans);
    }
    return 0;
}
