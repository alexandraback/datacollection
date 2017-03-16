#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int testcase = 1; testcase <= T; ++testcase) {
        int R, C, W;
        cin >> R >> C >> W;

        int len = W - 1, res = (C / W) * R;

        if (C % W != 0) ++res;
        res += len;

        cout << "Case #" << testcase << ": " << res << endl;
    }

    return 0;
}
