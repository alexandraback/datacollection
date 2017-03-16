
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t ++) {
        string S;
        cin >> S;
        string T = "";
        for (int l = 0; l < S.length(); l ++) {
            char ch = S[l];
            if (l == 0 || ch >= T[0]) {
                T.insert(0, 1, ch);
            }
            else {
                T.insert(l, 1, ch);
            }
        }
        cout << "Case #" << (t+1) << ": " << T << '\n';
    }
}

