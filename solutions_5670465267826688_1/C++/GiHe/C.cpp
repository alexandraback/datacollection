#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int qua[5][5];

int calc(int a, int b) {
    int tmp = 1;
    if (a < 0) {
        a = -a;
        tmp *= -1;
    }
    if (b < 0) {
        b = -b;
        tmp *= -1;
    }

    return tmp*qua[a][b];
}

int s[222222], leftside[222222], rightside[222222];

int main() {
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int testcase;
    scanf("%d", &testcase);
    int testnum = 0;
    qua[1][1] = 1; qua[1][2] = 2; qua[1][3] = 3; qua[1][4] = 4;
    qua[2][1] = 2; qua[2][2] = -1;qua[2][3] = 4; qua[2][4] = -3;
    qua[3][1] = 3; qua[3][2] = -4;qua[3][3] = -1;qua[3][4] = 2;
    qua[4][1] = 4; qua[4][2] = 3; qua[4][3] = -2;qua[4][4] = -1;

    int len;
    long long x;
    char c;
    while (testcase) {
        testcase--;testnum++;
        scanf("%d%I64d", &len, &x);getchar();
        for (int i = 1;i <= len ; i++) {
            c = getchar();
            switch (c) {
                case 'i' : s[i] = 2;break;
                case 'j' : s[i] = 3;break;
                case 'k' : s[i] = 4;break;
                default : s[i] = 0;break;
            }
        }

        x = min((x % 4)+16, x);

        for (int i = 2; i <= x; i++) {
            for (int j = 1; j <= len; j++)
                s[(i-1)*len+j] = s[j];
        }

        int totlen = len * x;
        int tmp = 1;
        for (int i = 1; i <= totlen; i++) {
            tmp = calc(tmp, s[i]);
            leftside[i] = tmp;
        }

        //for(int i = 1;i <= totlen; i++) printf("%d ", leftside[i]);printf("\n");

        tmp = 1;
        for (int i = totlen; i >= 1; i--) {
            tmp = calc(s[i], tmp);
            rightside[i] = tmp;
        }

        //for(int i = 1;i <= totlen; i++) printf("%d ", rightside[i]);printf("\n");

        bool emerge = false, ans = false;
        for (int i = 1; i < totlen; i++) {
            if (leftside[i] == 2) emerge = true;
            if (emerge && leftside[i] == 4 && rightside[i+1] == 4) {
                ans = true;break;
            }
        }

        if (ans) printf("Case #%d: YES\n", testnum);
        else printf("Case #%d: NO\n", testnum);
    }
}
