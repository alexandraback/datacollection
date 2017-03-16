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

        int res = R * C;
        if (R == 1) {
            for (int start = 0; start == 0; start++) {
                int tmp = 0;
                for (int i = start; i < C; i+= W) {
                    if (i < C) tmp++;
                }
                tmp += (W - 1);
                res = std::min(res, tmp);
            }
        }
        cout << "Case #" << cas << ": " << res << endl;
        
    }

    return 0;
}
