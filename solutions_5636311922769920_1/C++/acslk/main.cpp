#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <bits/stl_set.h>

using namespace std;
int T;
long long K, C, S;

string calc (int val) {

}

int main () {

    cin >> T;

    for (int t = 0; t < T; t++) {

        cin >> K >> C >> S;

        printf("Case #%d: ", t + 1);

        if (S * C < K)
            cout << "IMPOSSIBLE\n";
        else {
            long val = 0;
            while (val < K) {
                long long cur = 1;
                long long mult = 1;
                for (int i = 0; i < C; i++) {
                    if (val == K)
                        val--;
                    cur += val * mult;
                    mult *= K;
                    val++;
                }
                cout << " " << cur;
            }
            cout << "\n";
        }
    }
}