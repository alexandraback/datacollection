
#include <iostream>
#include <string>

using namespace std;

int main() {

    int T;
    cin >> T;

    for (int t = 0; t < T; t ++) {
        string X;
        cin >> X;

        int N = 0;
        char ch = '+';
        for (int j = X.length(); j > 0; j --) {
            if (X[j-1] != ch) {
                ch = X[j-1];
                N ++;
            }
        }

        cout << "Case #" << t+1 << ": " << N << '\n';
    }

}

