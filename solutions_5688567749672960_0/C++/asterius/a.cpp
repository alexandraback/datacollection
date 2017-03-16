#include <bits/stdc++.h>
using namespace std;
int ans[1000006];
// int solve(int a) {
//     if(ans[a]) return ans[a];
//     printf("solving a %d\n", a);
//     ans[a] = solve(a - 1) + 1;
// //     int b = 0, c = a;
// //     if(a % 10 > 0) {
// //         while(c) {
// //             b *= 10;
// //             b += c % 10;
// //             c /= 10;
// //         }
// //         if(b < a) {
// //             ans[a] = min(ans[a], solve(b) + 1);
// //         }
// //     }
//     return ans[a];
// }
int main() {
    int t, n;
    cin >> t;
    for(int i = 0; i <= 1000000; i++)
        ans[i] = 100000000;
    ans[1] = 1;
    for(int i = 1; i <= 1000000; i++) {
        int c = i, b = 0;
        while(c % 10 == 0)
            c /= 10;
        while(c) {
            b *= 10;
            b += c % 10;
            c /= 10;
        }
        if(b > i)
            ans[b] = min(ans[b], ans[i] + 1);
        ans[i + 1] = min(ans[i + 1], ans[i] + 1);
    }
    for(int i = 1; i <= t; i++) {
        cin >> n;
        printf("Case #%d: %d\n", i, ans[n]);
    }
}