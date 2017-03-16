//
// https://code.google.com/codejam/contest/6224486/dashboard#s=p2
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MAX_L 10010
#define I 1
#define J 2
#define K 3

int mvalue[4][4] = {{0, I, J, K}, {I, 0, K, J}, {J, K, 0, I}, {K, J, I, 0}};
int msign[4][4] = {{0, 0, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 0, 1, 1}};

char input[MAX_L];

struct quat {
    int value;
    int sign;

    quat(int value, int sign) {
        this->value = value;
        this->sign = sign;
    }
};

bool kok[MAX_L];

quat mul(quat p, quat q) {
    return quat(mvalue[p.value][q.value], p.sign ^ q.sign ^ msign[p.value][q.value]);
}

int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int c=1;c<=cases;c++) {
        int l, x;
        scanf("%d %d %s", &l, &x, input);
        FOR(i, l)
            switch (input[i]) {
                case 'i': input[i] = I; break;
                case 'j': input[i] = J; break;
                case 'k': input[i] = K; break;
            }
        FORE(i, 1, x) FOR(j, l) input[i * l + j] = input[j];
        int total = l * x;

        quat right = quat(0, 0);
        for(int i=total-1;i>=0;i--) {
            right = mul(quat(input[i], 0), right);
            kok[i] = right.value == K && right.sign == 0;
        }
        quat left = quat(0, 0);
        bool found = false;
        FOR(i, total) {
            left = mul(left, quat(input[i], 0));
            if (left.value == I && left.sign == 0) {
                //printf("%d ", i);
                quat temp = quat(0, 0);
                FORE(j, i + 1, total - 1) {
                    temp = mul(temp, quat(input[j], 0));
                    if (temp.value == J && temp.sign == 0 && kok[j + 1]) {
                        found = true;
                        break;
                    }
                }
            }
            if (found) break;
        }


        printf("Case #%d: %s\n", c, found ? "YES" : "NO");
    }
}
