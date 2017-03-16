#include <iostream>
#include <vector>
using namespace std;

int solve(long long a, vector<int> number) {
    int ans = number.size();
    int cur = 0;
    for (int i = 0; i < number.size(); i++) {
        if (a > number[i]) {
            a += number[i];
        } else {
            ans <?= cur + number.size() - i;
            while (a <= number[i] && cur < ans) {
                a = a * 2 - 1;
                cur++;
            }
            a += number[i];
            if (cur > ans) {
                return ans;
            }
        }
    }
    return min(ans, cur);
}


int main() {
    freopen("A-large.in", "r", stdin);
    freopen("large.txt", "w", stdout);
    
    int t;
    cin >> t;
    for (int task = 1; task <= t; task++) {
        int a, n;
        cin >> a >> n;
        vector<int> number;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            number.push_back(tmp);
        }
        sort(number.begin(), number.end());
        cout << "Case #" << task <<": " << solve(a, number) << endl;
    }
}
