#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int main() {
    int tests; cin >> tests;
    for (int test_id = 1; test_id <= tests; ++test_id) {
        int x, y;
        cin >> x >> y;
        printf("Case #%d: ", test_id);
        if (x > 0) for (int i = 0; i < x; ++i) printf("WE");        
        else if (x < 0) for (int i = 0; i < -x; ++i) printf("EW");
        if (y > 0) for (int i = 0; i < y; ++i) printf("SN");
        else if (y < 0) for (int i = 0; i < -y; ++i) printf("NS");
        printf("\n");
    }
    return 0;
}
