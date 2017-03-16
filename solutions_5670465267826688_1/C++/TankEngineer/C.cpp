#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

// 1 : 1 2 : i 3 : j 4 : k

const int table[4][4] = {
    1, 2, 3, 4,
    2, -1, 4, -3,
    3, -4, -1, 2,
    4, 3, -2, -1};

int mul(int a, int b) {
    int sign = (a < 0 == b < 0) ? 1 : -1;
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    return sign * table[a - 1][b - 1];
}

inline int trans(char ch) {
    if (ch == '1') {
        return 1;
    } else if (ch == 'i') {
        return 2;
    } else if (ch == 'j') {
        return 3;
    } else {
        return 4;
    }
}

int pow(int a, long long n) {
    int b = a, ret = 1;
    while (n) {
        if (n & 1) {
            ret = mul(ret, b);
        }
        n >>= 1;
        b = mul(b, b);
    }
    return ret;
}
    
const int L = 10005;

int l;

long long x;

char s[L];

int main() {
    int target = mul(mul(trans('i'), trans('j')), trans('k'));
    int t;
    scanf("%d", &t);
    while (t--) {
        cin >> l >> x;
        scanf("%s", s);
        int sum = 1;        
        for (int i = 0; i < l; ++i) {
            sum = mul(sum, trans(s[i]));
        }
        int allSum = pow(sum, x);
        static int id = 0;
        printf("Case #%d: ", ++id); 
        if (allSum != target) {
            puts("NO");
        } else {
            int cur = 1, left = -1;
            for (int i = 0; i < 4 && left == -1; ++i) {
                for (int j = 0; j < l; ++j) {
                    cur = mul(cur, trans(s[j]));
                    if (cur == 2) {
                        left = i * l + j + 1;
                        break;
                    }
                }
            }
            cur = 1;
            int right = -1;
            for (int i = 0; i < 4 && right == -1; ++i) {
                for (int j = 0; j < l; ++j) {
                    cur = mul(trans(s[l - j - 1]), cur);
                    if (cur == 4) {
                        right = i * l + j + 1;
                        break;
                    }
                }
            }
            if (left != -1 && right != -1 && left + right <= x * l) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
    return 0;
}
