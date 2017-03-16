#include <iostream>
using namespace std;

int K, C, S;

int main() {
    int T, Case = 1;
    cin >> T;
    while (T--) {
        cin >> K >> C >> S;
        cout << "Case #" << Case++ << ": ";
        for (int i = 1; i <= K; i++) {
            cout << i;
            if (i == K) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}
