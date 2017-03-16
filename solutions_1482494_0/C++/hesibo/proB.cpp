#include <iostream>
using namespace std;

int main() {
    freopen("B-small-attempt3.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int task;
    cin >> task;
    for (int t = 1; t <= task; t++) {
        int n, star[1000][2], complete[1000];
        memset(complete, 0, sizeof(complete));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> star[i][0] >> star[i][1];
        }
        int bleft = n, cur = 0, time = 0;
        while (bleft) {
            int p = 0, l = -1;
            for (int i = 0; i < n; i++) {
                if (cur >= star[i][1] && complete[i] == 1) {
                    p = i;
                    l = 2;
                    break;
                }
            }
            if (l == -1 ) {
                for (int i = 0; i < n; i++) {
                    if (cur >= star[i][1] && complete[i] < 2) {
                        p = i;
                        l = 2;
                        break;
                    }
                }
            }    
            if (l == -1) {
                for (int i = 0; i < n; i++) {
                    if (cur >= star[i][0] && complete[i] < 1) {
                        if (l == -1 || star[i][0] > star[p][0]) {
                            p = i;
                            l = 1;
                        }
                    }
                }
            }        
            if (l == -1) {
                printf("Case #%d: Too Bad\n", t);
                break;
            } else {
                cur += l - complete[p];
                time++;
                complete[p] = l;
                if (complete[p] == 2) {
                    bleft--;
                }
            }
        }
        if (bleft == 0) {
            printf("Case #%d: %d\n", t, time);
        }
    }
}
