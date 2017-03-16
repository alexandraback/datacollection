#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <hash_map>
#include <string>
#include <map>
#include <set>
#include <queue>

#if 0
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
typedef int256_t lll;
typedef uint256_t ulll;
#endif

using namespace std;
using namespace std::tr1;
using namespace stdext;

typedef __int64 ll;
typedef unsigned __int64 ull;

int T, R, C, M;
char a[64][64];

void assert(bool b) {
    if (!b) cout << "BBBBBBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAADDDDDDDDDDDDDDDDDD!!!\n";
}

int main(int argc, char* argv[]) {
    cin >> T;
    for (int t = 0; t != T; ++t) {
        cout << "Case #" << (t + 1) << ":\n";
        cin >> R >> C >> M;
        for (int y = 0; y != R; ++y) {
            for (int x = 0; x != C; ++x) {
                a[y][x] = '.';
            }
        }
        a[0][0] = 'c';
        int C1 = C, R1 = R;
        if (R == 1) {
            for (int x = C - M; x != C; ++x)
                a[0][x] = '*';
            M = 0;
        }
        if (C == 1) {
            for (int y = R - M; y != R; ++y)
                a[y][0] = '*';
            M = 0;
        }
        if (R * C - 1 == M) {
            for (int y = 0; y != R; ++y) {
                for (int x = 0; x != C; ++x) {
                    a[y][x] = '*';
                }
            }
            a[0][0] = 'c';
            M = 0;
        }
        while (M > 0) {
            if (C1 <= R1 && R1 >= 3 && M >= C1) {
                for (int x = 0; x != C1; ++x)
                    a[R1 - 1][x] = '*';
                M -= C1;
                R1--;
                continue;
            }
            if (R1 <= C1 && C1 >= 3 && M >= R1) {
                for (int y = 0; y != R1; ++y)
                    a[y][C1 - 1] = '*';
                M -= R1;
                C1--;
                continue;
            }
            if (R1 >= 4 && C1 >= 3) {
                int M1 = (M / 2) + (M & 1);
                int M2 = M - M1;
                for (int x = C1 - M1; x != C1; ++x)
                    a[R1 - 1][x] = '*';
                for (int x = C1 - M2; x != C1; ++x)
                    a[R1 - 2][x] = '*';
                M -= (M1 + M2);
                break;
            }
            if (C1 >= 4 && R >= 3) {
                int M1 = (M / 2) + (M & 1);
                int M2 = M - M1;
                for (int y = R1 - M1; y != C1; ++y)
                    a[y][C1 - 1] = '*';
                for (int y = R1 - M2; y != C1; ++y)
                    a[y][C1 - 2] = '*';
                M -= (M1 + M2);
                break;
            }
            if (R1 == 2 || C1 == 2)
                break; // fail
            if (R1 == 3 && C1 == 3) {
                a[2][2] = '*';
                M--;
                break;
            }
            assert(false);
        }
        if (M == 0) {
            for (int y = 0; y != R; ++y) {
                for (int x = 0; x != C; ++x) {
                    cout << a[y][x];
                }
                cout << "\n";
            }
        } else {
            cout << "Impossible\n"; 
        }
    }
    return 0;
}
