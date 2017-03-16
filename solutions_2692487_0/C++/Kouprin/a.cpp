#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long d[130];
vector<int> v;
int t;
int x, A, N;

void upd() {
    for(int i = 1; i < 120; ++i) {
        d[i] = max(d[i], d[i - 1] * 2 - 1);
        d[i] = min(d[i], 1000000000LL);
    }
}

int main() {
    cin >> t;
    for(int T = 0; T < t; ++T) {

        v.clear();
        cin >> A >> N;
        for(int i = 0; i < N; ++i) {
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());


        int ans = 1000000000;
        for(int i = 0; i < 120; ++i) {
            d[i] = 0;
        }

        d[0] = A;
        upd();

        for(int i = 0; i <= N; ++i) {
            for(int j = 0; j < 120; ++j) {
                if (d[j]) {
                    ans = min(ans, N - i + j);
                }
            }
            for(int j = 115; j >= 0; --j) {
                if (d[j] > v[i]) {
                    d[j] = d[j] + v[i];
                } else {
                    d[j] = 0;
                }
            }
            upd();
        }

        cout << "Case #" << T + 1 << ": " << ans << endl;
    }
    return 0;
}
