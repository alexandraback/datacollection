#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string>

#include <algorithm>

#include <vector>

#include <stack>
#include <queue>

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int Case = 1; Case <= t; Case++) {
        int a, b, k;
        cin >> a >> b >> k;
        int c = 0;
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
//                printf("%d: %d\n", (i & j), k);
                if ((i & j) < k) {
                    c++;
                }
            }
        }
        printf("Case #%d: %d\n", Case, c);
//        cout << "Case<< c << endl;
 //       break;
    }
}
