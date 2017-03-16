#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <initializer_list>

using namespace std;

int main(int argc, char *argv[])
{
    int T = 0;

    if (argc > 1) {
        freopen(argv[1], "r", stdin);
    }
    
    cin >> T;

    for (int cas = 1; cas <= T; cas++) {
        int R = 0, C = 0, W = 0;
        cin >> R >> C >> W;
        
        if (C % W == 0) {
            cout << "Case #" << cas << ": " << (C / W * R + W - 1) << endl;
        } else {
            cout << "Case #" << cas << ": " << (C / W * R + W) << endl;
        }
    }

    return 0;
}
