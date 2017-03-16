#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int Smax;
        string Stmp;
        cin >> Smax >> Stmp;

        vector<int> S(Smax + 1);
        for (int i = 0; i <= Smax; ++i) {
            S[i] = Stmp[i] - 48;
        }

        int stood_up = 0;
        int invite_sum = 0;
        for (int i = 0; i <= Smax; ++i) {
            if (! S[i]) {
                continue;
            }
            if (i > stood_up) {
                int invite = i - stood_up;
                invite_sum += invite;
                stood_up += invite;
            }
            stood_up += S[i];
        }

        cout << "Case #" << (t + 1) << ": " << invite_sum << endl;
    }

    return 0;
}
