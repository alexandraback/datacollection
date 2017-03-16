#include <iostream>
#include <set>
#include <cmath>
#include <cstdint>

using namespace std;

typedef uint64_t u64;

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

        set<u64> output;

        for (u64 j = 1; j <= K; j += C) {

            u64 begin = j;
            u64 end = (j + C - 1 < K ? j + C - 1 : K);
            //cout << "(" << begin << " -> " << end << ") "<< endl;

            // cout << "arr :";

            u64 * arr = new u64[C];
            for (u64 l = 0; l < C; l++) {
                u64 tmp = begin + l;
                if (tmp > end)
                    tmp = end;

                arr[l] = tmp;

                // cout << ' ' << arr[l];
            }
            // cout << endl;

            // a for answer
            u64 a = begin;
            u64 *k = arr;
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

        for (u64 e : output) {
            cout << " " << e;
        }

        cout << endl;
    }

    return 0;
}