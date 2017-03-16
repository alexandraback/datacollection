#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        long long K, C, S;
        cin >> K >> C >> S;
        cout << "Case #" << i << ":";
        if(K > C*S) {
            cout << " IMPOSSIBLE\n";
            continue;
        }
        long long d = 0;
        long long n = 0;
        long long a = 0;
        while(n < K) {
            d *= K; ++a;
            d += n; ++n;
            if(a == C) {
                cout <<" "<<d+1;
                a = 0;
                d = 0;
            }
        }
        if(a != 0) {
            cout << " " <<d + 1;
        }
        cout << "\n";
    }
    return 0;
}
