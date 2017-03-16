#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long ll;

int solve(int R, int C, int W) {
    if (W == 1) {
        return R*C;
    }

    if (C % W != 0) {
        return C / W + W;
    } else {
        return C / W + W - 1;
    }
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 1; i <= t; ++i) {
        int R,C,W;
        cin >> R;
        cin >> C;
        cin >> W;
        cout << "Case #" << i << ": " << solve(R, C, W) << endl;
    }
    
    return 0;
}
