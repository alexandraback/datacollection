#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int rowMask(int start, int len)
{
    return ((1 << len) - 1) << start;
}

static int bitCount[1 << 20];
static int bitPos[1 << 20];
void initBitCounts()
{
    bitCount[0] = 0;
    for (int mask = 1;mask < (1 << 20); mask++)
        bitCount[mask] = bitCount[mask >> 1] + (mask % 2);

    for (int mask = 1;mask < (1 << 20); mask++)
        for (int i = 0;i < 20; ++i)
            if (mask & (1 << i))
                bitPos[mask] = i;

    return;
}

int solve(int C, int W, int askSet = 0, int yesSet = 0)
{
    int noSet = askSet ^ yesSet;
    
    const int ALL = (1 << (C - W + 1)) - 1;

    int possSet = ALL;
    for (int tmp = noSet;tmp > 0;tmp ^= 1<<bitPos[tmp]) {
        int i = bitPos[tmp];
        int lft = max(0, i - W + 1);
        int rgt = i;
        possSet &= ALL ^ rowMask(lft, rgt - lft + 1);
    }

    for (int tmp = yesSet;tmp > 0;tmp ^= 1<<bitPos[tmp]) {
        int i = bitPos[tmp];
        int lft = max(0, i - W + 1);
        int rgt = i;

        possSet &= rowMask(lft, rgt - lft + 1);
    }

    if (!possSet)
        return -100000;

    if (bitCount[possSet] == 1) {
        int ret = 0, i = bitPos[possSet];
        for (int a = i;a < i + W; a++)
            if (! (askSet & (1 << a)))
                ret++;
        return ret;
    }

    int ret = 100000;
    for (int ask = 0;ask < C; ask++) {
        if (! (askSet & (1 << ask))) {
            int tmp = solve(C, W, askSet | (1 << ask), yesSet | (1 << ask));
            tmp = max(tmp, 1 + solve(C, W, askSet | (1 << ask), yesSet));

            ret = min(ret, tmp);
        }
    }

    return ret;
}

int main(int argc, char **argv)
{
    initBitCounts();

    int T;
    cin >> T;

    for (int t = 1;t <= T; ++t) {
        int R, C, W;
        cin >> R >> C >> W;
        cout << "Case #" << t << ": " << (R * solve(C, W)) << endl;
    }

    return 0;
}
