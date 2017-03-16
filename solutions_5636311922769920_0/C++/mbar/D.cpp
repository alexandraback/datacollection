#include <iostream>
#include <vector>

using namespace std;

typedef long long unsigned ll_t;

int main() {
    int T;
    cin >> T;
    for (int cs=1; cs<=T; ++cs) {
        cout << "Case #" << cs << ":";
        int K, C, S;
        cin >> K >> C >> S;
        if (S*C<K) {
            cout << " IMPOSSIBLE\n";
            continue;
        }
        for (int k=0; k<K;) {
            ll_t n=0;
            ll_t p=1;
            for (int i=0; i<C && k<K; ++i, ++k) {
                n += k*p;
                p *= K;
            }
            cout << " " << 1+n;
        }
        cout << "\n";
    }
}
