#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

const int VMAX = 2200;
const int CENTER = 1000;

int wall[2][VMAX];


struct t_t {
    int d;
    int n;
    int w,e;
    int s;
    int del_d;
    int del_p;
    int del_s;

    int c_d;
};

t_t para[1100];
int n;

int next_attack(t_t &p) {
    return p.d + p.c_d * p.del_d;
}

int get_next() {
    int d = 6760600;
    int ret = -1;
    for (int i = 0; i < n; i++) {
        if (para[i].c_d < para[i].n && d > next_attack(para[i])) {
            d = next_attack(para[i]);
            ret = i;
        }
    }

    return ret;
}

int imit() {
    int round = 0;
    memset(wall, 0, sizeof(wall));
    int k = 1;
    int last_day = -1;
    while (1) {
        int att = get_next();
        if (att == -1)
            break;

        if (last_day != para[att].d + para[att].del_d * para[att].c_d) {
            last_day = para[att].d + para[att].del_d * para[att].c_d;
            k = 1 - k;
            for (int i = 0; i < VMAX; i++) {
                wall[1-k][i] = wall[k][i];
            }
        }

        int s = para[att].s + para[att].del_s * para[att].c_d;
        int w = para[att].w + para[att].del_p * para[att].c_d;
        int e = para[att].e + para[att].del_p * para[att].c_d;



        int flag = 0;
        for (int i = w; i < e; i++) {
            if (wall[k][i] < s) {
                //printf("%d ", wall[k][i]);
                flag = 1;
                if (wall[1-k][i] < s)
                    wall[1-k][i] = s;
            }
        }
        //printf("\n");

        if (flag) round++;
        para[att].c_d++;

        //printf("?%d %d %d %d %d\n", att, s, w, e, flag);

    }
    return round;
}

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    //freopen("test.dat", "r", stdin);
    freopen("answer", "w", stdout);

    int t;
    scanf("%d", &t);
    for (int idx = 1; idx <= t; idx++) {
        printf("Case #%d: ", idx);

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d %d %d %d %d", &para[i].d, &para[i].n, &para[i].w,
                  &para[i].e, &para[i].s, &para[i].del_d, &para[i].del_p,
                  &para[i].del_s);

            para[i].w += CENTER;
            para[i].e += CENTER;
            para[i].c_d = 0;
        }

        printf("%d\n", imit());
    }
}
