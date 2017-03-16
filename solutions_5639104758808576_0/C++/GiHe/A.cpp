#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int testcase;
    scanf("%d", &testcase);

    int testnum = 0, n;
    while (testcase) {
        testcase--;testnum++;
        scanf("%d", &n);
        getchar();
        char c;
        int sum = 0, ans = 0;
        for (int i = 0; i < n+1; i++) {
            c = getchar();
            if (sum < i) {
                ans += i - sum;
                sum = i;
            }
            sum += c - '0';
        }
        printf("Case #%d: %d\n", testnum, ans);
    }
}
