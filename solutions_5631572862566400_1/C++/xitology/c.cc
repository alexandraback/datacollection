
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t ++) {
        int N;
        cin >> N;
        vector<int> likes(N);
        for (int n = 0; n < N; n ++) {
            int k;
            cin >> k;
            likes[n] = k-1;
        }
        int max_len = 0;
        vector<int> pairs(N, 0);

        for (int n = 0; n < N; n ++) {
            vector<bool> seen(N, false);
            seen[n] = true;
            int k = n;
            int l = 1;
            while (true) {
                int j = likes[k];
                if (!seen[j] && likes[j] == k) {
                    if (l > pairs[k]) {
                        pairs[k] = l;
                    }
                }
                if (j == n) {
                    break;
                }
                if (seen[j]) {
                    l = 0;
                    break;
                }
                k = j;
                seen[k] = true;
                l ++;
            }
            if (l > max_len) {
                max_len = l;
            }
        }
        int pairs_size = 0;
        for (int n = 0; n < N; n ++) {
            pairs_size += pairs[n];
        }
        if (pairs_size > max_len) {
            max_len = pairs_size;
        }
        cout << "Case #" << (t+1) << ": " << max_len << '\n';
    }

}

