#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        int Smax;
        string S;
        cin >> Smax >> S;
        int needed = 0;
        int applauding = 0;
        for(int j = 0; j <= Smax; ++j) {
            int cnt = S[j] - '0';
            if(cnt > 0 && j > applauding) {
                needed += j - applauding;
                applauding = j;
            }
            applauding += cnt;
        }
        cout << "Case #" << i << ": " << needed << "\n";
    }
}