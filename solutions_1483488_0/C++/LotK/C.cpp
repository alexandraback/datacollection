/*
Author: LotK
LANG: C++
*/

#include <cstdio>
#include <cmath>

int findLength(int);
int reverse(int, int);
int a[10];
int main() {
    int t, tt, i, j, A, B, n, m, len, cnt;
    scanf("%d", &tt);
    for(t=0 ; t<tt ; t++) {
        cnt = 0;
        scanf("%d%d", &A, &B);
        for(n=A ; n<=B ; n++) {
            m = n;
            len = findLength(n);
            //printf("%d %d\n", len, n);
            for(j=0 ; j<len ; j++) {
                m = reverse(m, len);
                a[j] = m;
                //printf("m = %d\n", m);
                if(m>n && m<=B) {
                    for(i=0 ; i<j ; i++) {
                        if(m==a[i]) break;
                    }
                    if(i>=j) {
                        // printf("%d %d\n", n, m);
                        cnt++;
                    }
                }
            }
        }

        printf("Case #%d: %d\n", t+1, cnt);
    }
}

int findLength(int x) {
    int i = 1;
    while(x/10 > 0) { x/=10; i++;}
    return i;
}

int reverse(int x, int len) {
    int tmp = (int)(pow(10, len-1))*(x%10);
    // printf("%d\n", tmp);
    return x/10 + tmp;
}
