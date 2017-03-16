/*
 g++ --std=c++11 -Wl,--stack=0x1000000 C.cc
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <gmpxx.h>

using namespace std;

int T, N;

int main()
{
    ios::sync_with_stdio(false);
    cout.precision(8);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;

        int H[2501] = {0};
        for (int i = 0; i < 2 * N - 1; i++)
            for (int j = 0; j < N; j++) {
                int h;
                cin >> h;
                H[h]++;
            }

        cout << "Case #" << t << ": ";
        for (int i = 1; i < 2501; i++)
            if (H[i] % 2 == 1) cout << i << " ";
        cout << endl;
    }
}
