#include <iostream>
#include <algorithm>

#define INF 0x7000000

using namespace std;

int T, N, a [1000], b [1000];

int main () {
    cin >> T;
    for (int t = 0; t < T; t ++) {
        cin >> N;
        for (int i = 0 ; i < N; i ++) {
            cin >> a [i] >> b [i];
        }
        int s = 0;
        int cnt = 0;
        bool done = false;
        while (!done) {
            done = true;
            for (int i = 0; i < N; i ++) {
                if (b [i] <= s) {
                    a [i] = INF;
                    b [i] = INF;
                    s += 2;
                    cnt ++;
                    done = false;
                }
            }
            if (done) {
                int ind = -1;
                int m = -1;
                for (int i = 0; i < N; i ++) {
                    if (a [i] <= s) {
                        if (b [i] > m) {
                            m = b [i];
                            ind = i;
                        }
                    }
                }
                if (ind != -1) {
                    a [ind] = b [ind];
                    b [ind] = INF;
                    s += 1;
                    cnt += 1;
                    done = false;
                }
            }
        }
        //cout << s << " " << 2 * N << endl;
        if (s == 2 * N) {
            cout << "Case #" << t + 1 << ": " << cnt << endl;
        } else {
            cout << "Case #" << t + 1 << ": " << "Too Bad" << endl;
        }
    }
}
