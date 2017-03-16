#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;
typedef int typec;

#define MAXN 1005
#define INF 0x3f3f3f3f
#define MOD 1000000009

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

int main(void) {
    FILE *fp, *fp2;
    //freopen_s(&fp, "A-small-attempt1.in", "r", stdin);
    //freopen_s(&fp2, "A.out", "w", stdout);
    int nCase;
    while (cin >> nCase) {
        for (int cas = 1; cas <= nCase; ++cas) {
            char str[100];
            cin >> str;
            LL a = 0;
            LL b = 0;
            int i = 0;
            int n = strlen(str);
            for (; i < n; ++i) {
                if (str[i] == '/') {
                    ++i;
                    break;
                }
                a = 10 * a + str[i] - '0';
            }
            for (; i < n; ++i) {
                b = 10 * b + str[i] - '0';
            }
            int k = 0;
            LL p = gcd(a, b);
            a /= p;
            b /= p;

            //test
            //cout << a << endl;
            //cout << b << endl;
            //end

            bool bFlag = true;
            while (b > a) {
                if (b & 1) {
                    bFlag = false;
                    break;
                }
                else {
                    b /= 2;
                    ++k;
                }
            }
            if (bFlag) {
                a -= b;
                while (b != 1 && a != 0) {
                    if (b > a) {
                        if (b & 1) {
                            bFlag = false;
                            break;
                        }
                        else {
                            b /= 2;
                        }
                    }
                    else {
                        a -= b;
                    }
                }
            }

            printf("Case #%d: ", cas);
            if (bFlag) {
                printf("%d\n", k);
            }
            else {
                printf("impossible\n");
            }
        }
    }
    return 0;
}