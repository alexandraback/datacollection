#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
long long arr[100];
void init() {
    arr[0] = 1;
    for (int i = 1; i <= 61; i++) {
        arr[i] = arr[i-1]*2LL;
    }
}
int main(int argc, char *argv[])
{
    long long int T, a, b;
    init();
    scanf("%lld", &T);
    for (int ct = 1; ct <= T; ct++) {
        scanf("%lld/%lld", &a, &b);
        long long tmp = __gcd(a, b);
        int fg = -1, fg2 = -1;
        a /= tmp;
        b /= tmp;
        for (int i = 0; i <= 61; i++) {
            if (b == arr[i]) {
                fg = i;
            }
        }
        for (int i = 61; i >= 0; i--) {
            if (a >> i == 1) {
                fg2 = i;
            }
        }
        if (fg == -1) {
            cout << "Case #" << ct <<": impossible" << endl;
        } else {
            cout << "Case #" << ct <<": " << fg-fg2 <<endl;
        }
    }
    return 0;
}
