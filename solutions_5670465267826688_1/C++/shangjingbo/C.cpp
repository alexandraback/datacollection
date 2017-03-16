#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int multi[4][4] = {
{1, 2, 3, 4},
{2, 1, 4, 3},
{3, 4, 1, 2},
{4, 3, 2, 1}
};

const int signs[4][4] = {
{1, 1, 1, 1},
{1, -1, 1, -1},
{1, -1, -1, 1},
{1, 1, -1, -1}
};

int sign(int x)
{
    return x < 0 ? -1 : x > 0;
}

int multiply(int a, int b)
{
    return sign(a) * sign(b) * sign(signs[abs(a) - 1][abs(b) - 1]) * multi[abs(a) - 1][abs(b) - 1];
}

const int maxL = 10000;
int L, X;
int prefix[maxL + 1], suffix[maxL + 1];
char s[maxL + 1];

int getNumber(char x)
{
    if (x == 'i') {
        return 2;
    }
    if (x == 'j') {
        return 3;
    }
    if (x == 'k') {
        return 4;
    }
    cerr << "ERROR! " << x << endl;
    return -1;
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);

    int test = 1, tests;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        scanf("%d%d%s", &L, &X, s);
        prefix[0] = 1;
        for (int i = 0; i < L; ++ i) {
            prefix[i + 1] = multiply(prefix[i], getNumber(s[i]));
        }
        suffix[L] = 1;
        for (int i = L; i > 0; -- i) {
            suffix[i - 1] = multiply(getNumber(s[i - 1]), suffix[i]);
        }

        int whole = prefix[L], cycle[20], length = 0;
        cycle[0] = 1;
        for (int i = 1; ; ++ i) {
            cycle[i] = multiply(cycle[i - 1], whole);
            if (cycle[i] == 1) {
                length = i;
                break;
            }
        }
        cerr << "length = " << length << endl;

        if (cycle[X % length] != -1) {
            printf("Case #%d: NO\n", test);
            continue;
        }
        bool found = false;
        for (int i = 0; i < length && !found; ++ i) {
            for (int pre = 0; pre <= L && !found; ++ pre) {
                if (multiply(cycle[i], prefix[pre]) != 2) {
                    continue;
                }
                for(int j = 0; j < length && !found; ++ j) {
                    for (int suf = 0; suf <= L && !found; ++ suf) {
                        if (i + j + (pre > suf) >= X) {
                            continue;
                        }
                        if (multiply(suffix[suf], cycle[j]) != 4) {
                            continue;
                        }

                        found = true;
                    }
                }
            }
        }

        printf("Case #%d: %s\n", test, found ? "YES" : "NO");
    }
    return 0;
}
