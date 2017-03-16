#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	int T;

    cin >> T;
    for (int t=1; t <= T; ++t) {
        int A, B, K;
        cin >> A >> B >> K;

        int ans = 0;
        for (int i=0; i < A; ++i) {
            for (int j=0; j < B; ++j) {
                ans += (i & j) < K;
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
	
	return 0;
}
