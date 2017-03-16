#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int CN = 1; CN <= t; CN++) {
        long long A, B, K;
        cin >> A >> B >> K;
        
        if (A > B) {
            swap(A, B);
        }

        if (K > A) {
            cout << "Case #" << CN << ": " << A*B << "\n";
            continue;
        }

        long long ans = K*B + K*A - K*K;
        for (long long a = K; a < A; a++) {
            for (long long b = K; b < B; b++) {
                if ((a & b) < K)
                    ans++;
            }
        }
        cout << "Case #" << CN << ": " << ans << "\n";
    }

    return 0;
}

