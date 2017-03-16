#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T; cin >> T;
    for(int t = 1; t <= T; ++t) {
        int A, B, K;
        cin >> A >> B >> K;
        int num = 0;
        for(int a = 0; a < A; ++a) {
            for(int b = 0; b < B; ++b) {
                num += ((a & b) < K);
            }
        }
        
        cout << "Case #" << t << ": " << num << endl;
    }
}