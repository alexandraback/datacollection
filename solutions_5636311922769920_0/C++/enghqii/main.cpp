#include <iostream>
#include <set>
#include <cmath>
#include <cstdint>

using namespace std;

typedef int64_t s64;

int main() {
    int count;
    cin >> count;

    for (int i = 1; i <= count; i++) {

        int K, C, S;
        cin >> K >> C >> S;

        if (C * S < K) {
            cout << "Case #" << i << ": IMPOSSIBLE" << endl;
            continue;
        }

        set<s64> output;

        for (s64 j = 1; j <= K; j += C) {
            s64 begin = j;
            s64 end = (j + C - 1 < K ? j + C - 1 : K);
            //cout << "(" << begin << " -> " << end << ") "<< endl;

            // cout << "arr :";

            s64 * arr = new s64[C];
            for (s64 l = 0; l < C; l++) {
                s64 tmp = begin + l;
                if (tmp > end)
                    tmp = end;

                arr[l] = tmp;

                // cout << ' ' << arr[l];
            }
            // cout << endl;

            // a for answer
            s64 a = begin;
            s64 *k = arr;
            for (int l = 1; l < C; l++) {
                //cout << "k : " << k << endl;
                k++;
                a = a - 1;
                a = a * K;
                a = a + (*k);
            }
            delete [] arr;

            output.insert(a);
            // cout << "insert : " << a << endl;

        }

        if (output.size() > S) {
            cout << "Case #" << i << ": IMPOSSIBLE" << endl;
            continue;
        }

        cout << "Case #" << i << ":";

        for (s64 e : output) {
            cout << " " << e;
        }

        cout << endl;
    }

    return 0;
}