#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int s;
        int sum = 0;
        int ans = 0;
        cin >> s;
        for (int j = 0; j < s + 1; j++) {
            if (sum < j) {
                ans += j - sum;
                sum = j;
            }

            char c;
            cin >> c;
            int val = c - '0';
            sum += val;
        }
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    return 0;
}
