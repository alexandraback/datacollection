#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int op[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4},
    {0, 2, -1, 4, -3},
    {0, 3, -4, -1, 2},
    {0, 4, 3, -2, -1},
};

int toInt[300];

int inline mult(int a, int b) {
    int sign = 1;

    if (a < 0) {
        a *= -1;
        sign *= -1;
    }

    if (b < 0) {
        b *= -1;
        sign *= -1;
    }

    return sign * op[a][b];
}

const int N = 10000;
const int INF = 5;

int prefix[N + 1];
int suffix[N + 1];

int getMin(int need, int left, int have, int right) {

    int i = 0;
    for (; i < INF && have != need; ++i) {
        if (!left) have = mult(have, right);
        else have = mult(left, have);
    }

    return i;
}

int main()
{
    int T;
    cin >> T;

    toInt['i'] = 2;
    toInt['j'] = 3;
    toInt['k'] = 4;

    prefix[0] = suffix[0] = 1;

    for (int test = 1; test <= T; ++test) {
        int l, x;
        cin >> l >> x;

        string s;
        cin >> s;

        for (int i = 1; i <= s.size(); ++i) {
            prefix[i] = mult(prefix[i - 1], toInt[s[i - 1]]);
        }

        for (int i = 1, j = s.size() - 1; j >= 0; --j, ++i) {
            suffix[i] = mult(toInt[s[j]], suffix[i - 1]);
        }

        int block = prefix[l];

        bool yes = false;
        for (int prefLen = 1; prefLen < l - 1 && !yes; ++prefLen) {
            int prefBlock = getMin(2, block, prefix[prefLen], 0);
            if (prefBlock == INF || prefBlock + 1 > x) continue;

            int midVal = 1;
            for (int midLen = 1; prefLen + midLen <= l; ++midLen) {
                midVal = mult(midVal, toInt[s[prefLen + midLen - 1]]);

                if (midVal == 3) {
                    int blockVal = 1;
                    for (int i = 0; i < (x - 1 - prefBlock) % 4; ++i) {
                        blockVal = mult(blockVal, block);
                    }

                    int sufVal = mult(suffix[l - prefLen - midLen], blockVal);

                    if (sufVal == 4) {
                        yes = true;
                        break;
                    }
                }
            }
        }

        for (int prefLen = 1; prefLen <= l && !yes; ++prefLen) {
            int prefBlock = getMin(2, block, prefix[prefLen], 0);

            if (prefBlock == INF || prefBlock + 1 > x) continue;

            for (int sufLen = 0; sufLen <= l; ++sufLen) {
                int sufBlock = getMin(4, 0, suffix[sufLen], block);

                int blocksRemain = x - prefBlock - sufBlock - 2;
                if (sufBlock == INF || blocksRemain < 0) continue;

                int val = suffix[l - prefLen];

                for (int i = 0; i < (blocksRemain % 4); ++i) {
                    val = mult(val, block);
                }

                val = mult(val, prefix[l - sufLen]);

                if (val == 3) {
                    yes = true;
                    break;
                }
            }
        }

        cout << "Case #" << test << ": " << (yes ? "YES" : "NO") << endl;

    }

    return 0;
}
