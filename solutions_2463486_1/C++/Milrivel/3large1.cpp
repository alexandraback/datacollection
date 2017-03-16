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

bool check_palindrome (long long n) {
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

long long fs[40];

int main(void) {
    freopen("C-large-1.in", "r", stdin);
    freopen("dataout.txt", "w", stdout);
    int count = 0;
    for (int i = 1; i <= 10000000; i++) {
        if (check_palindrome(i)) {
            if (check_palindrome((long long)i * i)) {
                fs[count++] = (long long)i * i;
            }
        }
    }

    int t;
    scanf("%d", &t);
    for (int cases = 1; cases <= t; cases++) {
        long long a, b;
        int index1, index2;
        scanf("%I64d%I64d", &a, &b);
        if (a > b) {
            long long tmp = a; a = b; b = tmp;
        }
        for (index1 = 0; index1 < count; index1++) {
            if (a - 1 < fs[index1]) {
                break;
            }
        }
        for (index2 = 0; index2 < count; index2++) {
            if (b < fs[index2]) {
                break;
            }
        }
        printf("Case #%d: %d\n", cases, index2 - index1);
    }

    return 0;
}
