#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define rep(i,n) for (int i = 0; i < int(n); i++)
#define show(x) #x " = " << (x)

int main() {
    int T; cin >> T;
    rep (t,T) {
        cout << "Case #" << t+1 << ": ";
        size_t A, B, K;
        cin >> A >> B >> K;
        int count = 0;
        rep (i,A) rep (j,B) {
            if ((i&j) < K) count++;
        }
        cout << count << endl;
    }
}
