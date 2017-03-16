#include <stdio.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define M 2000000
using namespace std;

int flag[M];

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas;
    scanf("%d", &cas);
    for (int i = 0; i < cas; i++) {
        int n;
        scanf("%d", &n);
        int num[100];
        memset(flag, 0, sizeof (flag));
        for (int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }
        int p1 = 0, p2 = 0;
        bool yes = false;
        for (int i = 0; i < n; i++) {
            for (int j = M; j >= 1; j--) {
                if (j == num[i]) {
                    if (flag[j] == 0)
                        flag[j] = (1 << i);
                    else {
                        p1 = flag[j];
                        p2 = (1 << i);
                        yes = true;
                        break;
                    }
                    //printf("%d ", j);
                }
                else if (flag[j] != 0) {
                    int t = j + num[i];
                    if (flag[t] == 0)
                        flag[t] = flag[j] + (1 << i);
                    else {
                        p1 = flag[t];
                        p2 = flag[j] + (1 << i);
                        yes = true;
                        break;
                    }
                    //printf("%d ", j);
                }
            }
            //printf("\n");
            if (yes) break;
        }
        printf("Case #%d:\n", i + 1);
        bool first = true;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & p1) {
                if (first){
                    first = false;
                }
                else printf(" ");
                printf("%d", num[i]);
            }
        }
        printf("\n");
        first = true;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & p2) {
                if (first){
                    first = false;
                }
                else printf(" ");
                printf("%d", num[i]);
            }
        }
        printf("\n");
    }
    return 0;
}