#include <iostream>

using namespace std;

int n;
int A[1001];
int B[1001];
int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        cin>>n;
        for (int i=0;i<n;++i) {
            cin>>A[i] >> B[i];
        }

        int done[1000] = {0};
        int ans = 0;
        int cs = 0;
        while (cs < n*2) {
            bool found = false;
            for (int i=0;i<n;i++) {
                if (done[i] != 2 && cs >= B[i]) {
                    cs += 2 - done[i];
                    done[i] = 2;
                    found = true;
                    ans++;
                    break;
                }
            }

            if (found) continue;

            int most = -1;
            int mi = -1;
            for (int i=0;i<n;i++) {
                if (done[i] != 0 || A[i] > cs) continue;
                if (B[i] > most) {
                    most = B[i];
                    mi = i;
                }
            }

            if (mi == -1) {
                ans = -1;
                break;
            } else {
                ans++;
                cs++;
                done[mi] = 1;
            }
        }

        if (ans == -1) {
            cout << "Case #" << t << ": Too Bad" << endl;
        } else {
            cout << "Case #" << t << ": " << ans << endl;
        }
    }
    return 0;
}
