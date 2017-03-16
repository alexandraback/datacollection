#include <iostream>
#include <string>

using namespace std;

int main() {

    int N;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        string S, out = "";
        cin >> S;
        for (int j = 0; j < S.size(); ++j) {
            if (S[j] < out[0]) {
                out += S[j];
            } else {
                out = S[j] + out;
            }
        }
        cout << "Case #" << i+1 << ": " << out << endl;
    }
    return 0;
}
