#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl;

int main() {
    int T;
    cin >> T;
    for (int Ti = 1; Ti <= T; ++Ti) {
        int A, B, K;
        cin >> A >> B >> K;

        int res = 0;
        for (int a = 0; a < A; ++a) {
            for (int b = 0; b < B; ++b) {
                res += (a & b) < K;
            }
        }

        cout << "Case #" << Ti << ": " << res << endl;
    }
    return 0;
}