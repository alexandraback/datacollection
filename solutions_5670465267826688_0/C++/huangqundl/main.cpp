#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define total value[0][L-1]

int table[5][5] = {0, 0,  0,  0,  0,
                 0, 1,  2,  3,  4,
                 0, 2, -1,  4, -3,
                 0, 3, -4, -1,  2,
                 0, 4,  3, -2, -1};

inline int char2int(char c) {
    return c - 'i' + 2;
}

int cal(int a, int b) {
    if (a>0 && b>0) {
        return table[a][b];
    }
    else if (a>0 && b<0) {
        return -table[a][-b];
    }
    else if (a<0 && b>0) {
        return -table[-a][b];
    }
    else if (a<0 && b<0) {
        return table[-a][-b];
    }
    else {
        cout << "error" << a << ' ' << b << endl;
        return 0;
    }
}

int power(int a, int p) {
    int ret = 1;
    for (int i=0; i<p; i++) {
        ret = cal(ret, a);
    }
    return ret;
}

int value[10000][10000];

void prepare(string s, int L) {
    //memset(value, 0, sizeof(int)*10000*10000);
    for (int i=0; i<L; i++) {
        int cur = 1;
        for (int j=0; j<L; j++) {
            if (j<i) {
                value[i][j] = 1;
            }
            else {
                value[i][j] = cal(cur, char2int(s[j]));
                cur = value[i][j];
            }
        }
    }
}

int substring(int i, int j) {
    if (j<i) {
        return 1;
    }
    else {
        return value[i][j];
    }
}

bool solve1(int L, int X) {
    for (int x1=0; x1<=3; x1++) {
        for (int x2=0; x2<=3; x2++) {
            if (x1+x2+1 > X) {
                continue;
            }
            if ((X-x1-x2-1) % 4 != 0) {
                continue;
            }

            //printf("solve1 %d %d\n", x1, x2);

            int head = power(total, x1);
            int tail = power(total, x2);
            //printf("    head tail %d %d\n", head, tail);
            for (int i=0; i<L; i++) {
                for (int j=i; j<L; j++) {
                    int first = cal(head, substring(0, i-1));
                    int second = substring(i, j-1);
                    int third = cal(substring(j, L-1), tail);
                    if (first==2 && second==3 && third==4) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool solve2(int L, int X) {
    for (int x1=0; x1<=3; x1++) {
        for (int x2=0; x2<=3; x2++) {
            for (int x3=0; x3<=3; x3++) {
                if (x1+x2+x3+2 > X) {
                    continue;
                }
                if ((X-x1-x2-x3-2) % 4 != 0) {
                    continue;
                }

                int head = power(total, x1);
                int middle = power(total, x2);
                int tail = power(total, x3);
                for (int i=0; i<L; i++) {
                    for (int j=0; j<L; j++) {
                        int first = cal(head, substring(0, i-1));
                        int second = cal(substring(i, L-1), middle);
                        second = cal(second, substring(0, j-1));
                        int third = cal(substring(j, L-1), tail);
                        if (first==2 && second==3 && third==4) {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

void solve() {
    int L, X;
    string s;

    cin >> L >> X >> s;
    prepare(s, L);

    if (solve1(L, X)) {
        cout << "YES" << endl;
        return;
    }
    
    if (solve2(L, X)) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
