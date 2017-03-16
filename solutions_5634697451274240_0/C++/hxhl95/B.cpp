#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        string S;
        cin >> S;

        int flips = 0;
        for (int k = S.size()-1; k >= 0; k--) {
            if (S[k] == '-') {
                for (int i = k; i >= 0; i--) {
                    if (S[i] == '-') S[i] = '+';
                    else if (S[i] == '+') S[i] = '-';
                }
                flips++;
            }
        }
        
        cout << "Case #" << c << ": " << flips << endl;
    }
    return 0;
}
