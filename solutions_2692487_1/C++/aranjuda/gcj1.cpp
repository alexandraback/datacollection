# include <iostream>
# include <vector>
# include <fstream>
# include <sstream>
# include <string>
# include <cmath>
# include <algorithm>
# include <queue>

using namespace std;

int M[120];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int addd;
        priority_queue <int> large_motes;
        int A, N;
        cin >> A >> N;
        int curr_size = A;

        for (int j = 0 ; j < N; j++) {
            cin >> M[j];
            if (M[j] < curr_size) {
                curr_size+=M[j];
                M[j] = 0;
            }
            else {
                large_motes.push(-M[j]);
                //ac_large_motes.push(M[j]);
            }
        }
        while (large_motes.size() > 0) {
            int msize = large_motes.top();
            msize*= -1;
            if (curr_size > msize) {
                curr_size+= msize;
                large_motes.pop();
            }
            else {
                break;
            }
        }
        if (large_motes.size() > 0) {
            for (int qr = 0; qr < N; qr++) {
                if (M[qr] < -large_motes.top()) M[qr] = 0;
            }
        }
        int ans = large_motes.size();
        addd = 0;
        if (curr_size == 1) goto AB;
        while (large_motes.size() > 0) {
            while (curr_size <= -large_motes.top()) {
                curr_size += (curr_size -1);
                addd++;
            }
            curr_size+= -large_motes.top();
            int less = 0;
            for (int qr = 0; qr < N; qr++) {
                if (M[qr] >= curr_size) {
                    less++;
                }
                if (M[qr] <= -large_motes.top()) M[qr] = 0;
            }
            ans = min(less + addd, ans);
            large_motes.pop();
        }
        // All possible smaller motes are eaten, larger ones are left
AB:
        printf("Case #%d: %d\n", i+1, ans);
    }
    return 0;
}
