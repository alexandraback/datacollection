#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

bool check_square(int n) {
    if (fabs(sqrt(n) - (int)sqrt(n)) < 1e-8) {
        return true;
    } else {
        return false;
    }
}

bool check_palindrome (int n) {
    vector<int> digit;
    while (n) {
        digit.push_back(n % 10);
        n /= 10;
    }
    int sz = digit.size();
    for (int i = 0; i < sz / 2; i++) {
        if (digit[i] != digit[sz - 1 - i]) {
            return false;
        }
    }
    return true;
}

int total[1010];
void init() {
    int tot = 0;
    for (int i = 1; i <= 1000; i++) {
        if (check_square(i)) {
            if (check_palindrome((int)sqrt(i))) {
                if (check_palindrome(i)) {
                    tot++;
                }
            }
        }
        total[i] = tot;
    }
}

int main(void) {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("dataout.txt", "w", stdout);
    init();

    int t;
    scanf("%d", &t);
    for (int cases = 1; cases <= t; cases++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b) {
            int tmp = a; a = b; b = tmp;
        }
        printf("Case #%d: %d\n", cases, total[b] - total[a - 1]);
    }
    return 0;
}
