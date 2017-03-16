/*
Author: LotK
LANG: C++
*/

#include <cstdio>

int main() {
    int t, tt, n, s, p, i, j, cnt;
    int a[110];
    scanf("%d", &tt);
    for(t=0 ; t<tt ; t++) {
        cnt = 0;
        scanf("%d%d%d", &n, &s, &p);
        for(i=0 ; i<n ; i++) {
            scanf("%d", &a[i]);
            if(a[i]%3 == 0) {
                if(a[i]/3 >= p) cnt++;
                else if(a[i]/3+1 >= p && a[i]>0 && s>0) {
                    cnt++;
                    s--;
                }
            }
            else if(a[i]%3 == 1) {
                if(a[i]/3+1 >= p) cnt++;
            }
            else {
                if(a[i]/3+1 >= p) cnt++;
                else if(a[i]/3+2 >= p && s>0) {
                    cnt++;
                    s--;
                }
            }
        }


        printf("Case #%d: %d\n", t+1, cnt);

    }

}
