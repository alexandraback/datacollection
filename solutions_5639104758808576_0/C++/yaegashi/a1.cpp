#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int Smax;
        string S;
        cin >> Smax >> S;
        int total = 0, claques = 0;
        for (int i = 0; i <= Smax; i++) {
            if (total < i) {
                claques += i - total;
                total = i;
            }
            total += S[i] - '0';
        }
        cout << "Case #" << t+1 << ": " << claques << endl;
    }
    return 0;
}

// vim: set sw=4:
