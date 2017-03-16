#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

typedef long long int ll_t;

int main() {
    int T;
    cin >> T;
    for (int cs=1; cs<=T; ++cs) {
        ll_t N;
        cin >> N;
        if (!N) {
            cout << "Case #" << cs << ": INSOMNIA\n";
            continue;
        }
        vector<short> saw(10);
        int saw_cnt = 0;
        ll_t m=N, n=N;
        for (;;) {
            n = m;
            while (m) {
                lldiv_t r = lldiv(m, 10);
                if (!saw[r.rem]) {
                    saw[r.rem] = 1;
                    ++saw_cnt;
                    if (saw_cnt == 10) goto saw_all;
                }
                m = r.quot;
            }
            m = n + N;
            if (m < n) {
                cerr << "OVERFLOW" << endl;
                break;
            }
        }
      saw_all:
        cout << "Case #" << cs << ": " << n << "\n";
    }
}
