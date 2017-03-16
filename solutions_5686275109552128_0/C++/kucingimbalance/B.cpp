#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MX(a,b) a = max(a,b);
#define MN(a,b) a = min(a,b);
#define INF 1000000000

int main() {
    int ntc;
    cin >> ntc;
    for (int itc = 1; itc <= ntc; ++itc) {
        int n;
        cin >> n;
        int arr[n+5];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        int ans = INF;
        for (int bound = 1; bound <= 1000; ++bound) {
           int specost = 0, maxcost = 0; 
           for (int i = 0; i < n; ++i) {
               if (arr[i] > bound) {
                   specost += (arr[i] - 1) / bound;
               }
               MX(maxcost, arr[i]);
           }
           MN(maxcost, bound);
           MN(ans, maxcost + specost);
        }
        cout << "Case #" << itc << ": " << ans << endl;
    }
}
