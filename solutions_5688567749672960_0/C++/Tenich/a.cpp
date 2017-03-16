#include <iostream>
#include <queue>
#include <map>

using namespace std;

int reverse(int x) {
    int rev = 0;
    while (x) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev;
}

int main() {
    int T;
    cin >> T;

    for (int iter = 1; iter <= T; ++iter) {
        map<int, int> res;
        res[1] = 1;

        int target;
        cin >> target;

        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            if (res.count(target) > 0) {
                break;
            }
            int cur = q.front();
            q.pop();

            if (res.count(cur + 1) == 0) {
                res[cur + 1] = res[cur] + 1;
                q.push(cur + 1);
            }
            int rev = reverse(cur);
            if (res.count(rev) == 0) {
                res[rev] = res[cur] + 1;
                q.push(rev);
            }
        }
    cout << "Case #" << iter << ": " << res[target] << "\n";
    }
    return 0;
}
