#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

bool check(unsigned long long a, unsigned long long b) {

    // cerr << a << " " << b << endl;
    if (a == b) return true;
    if (a == 1 && b == 1) return true;
    if (a == 0 && b == 1) return true;
    if (b == 0) return false;
    if (b >= a) {
        if (b % 2 == 1) return false;
        return check(a, b / 2);
    }
    return check(b, b) && check(a - b, b);
}


int main() {
    int tcc;
    scanf("%d", &tcc);
    for (int tc = 1; tc <= tcc; tc++) {
        unsigned long long a, b;
        scanf("%llu/%llu", &a, &b);
        // cout << a << endl;4
        // cout << b << endl;
        printf("Case #%d: ", tc);
        int i = 1;
        bool possible = check(a, b);
        while (b > a && possible) {
            b /= 2;
            if (b > a) i++;
        }
        if (possible) {
            printf("%d\n", i);
        } else {
            printf("impossible\n");
        }

    }
    return 0;
}
