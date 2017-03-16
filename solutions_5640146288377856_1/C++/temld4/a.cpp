#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        int result = 0;

        int R, C, S;
        cin >> R >> C >> S;
        int A = C % S > 0 ? 1 : 0;

        result = (C / S) * R + S - 1 + A;

        cout << result << endl;
    }

    return 0;
}
