#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
const int N = 1000 + 10;
const int MAX = 1000;

int a[N];

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = (int)2e9;
        for (int num = 1; num <= MAX; num++) {
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                sum += (a[i] + num - 1) / num - 1;
            }
            ans = min(ans, sum + num);
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
