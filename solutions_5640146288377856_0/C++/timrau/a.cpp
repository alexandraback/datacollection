#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <climits>
#include <string>
#include <cstring>
#include <list>
#include <functional>
#include <iterator>

using namespace std;

int solve(int R, int C, int W)
{
    int ans = R * (C / W) - 1;
    int gap = (C%W) + W;
    if (gap == W)
        return ans + W;
    return ans + W + 1;
}

int main(void)
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int R, C, W;
        cin >> R >> C >> W;
        cout << "Case #" << i << ": " << solve(R, C, W) << endl;
    }
    return 0;
}
