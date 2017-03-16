#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
const int MOD = 1000000007;
int n , a[N] , b[N];
bool check (int need , int eat) {
    int change = need - eat;
    for (int i = 0 ; i < n ; i ++) {
        b[i] = a[i];
    }
    int cost = 0;
    for (int i = n - 1 ; i >= 0 && b[i] > eat ; i --) {
        cost += (b[i] - eat + eat - 1) / eat;
    }
    return cost <= change;
}
bool check (int need) {
    for (int i = 1 ; i <= need ; i ++) {
        if (check (need , i))
            return true;
    }
    return false;
}
int main () {
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);  
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        int sum = 0 , high = 0;
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%d" , a + i);
            sum += a[i];
            high = max (high , a[i]);
        }
        sort (a , a + n);
        int low = 0 , mid , ans = high;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (check (mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        printf ("Case #%d: %d\n" , ++ cas , ans);
    }
    return 0;
}