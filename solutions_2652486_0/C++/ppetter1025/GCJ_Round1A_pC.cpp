#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    puts("Case #1:");

    int r, n, m, K;
    scanf("%d %d %d %d", &r, &n, &m, &K);

    while(r--) {
        int a[7];
        for(int i = 0; i < K; i++)  scanf("%d", &a[i]);

        int k = 0, num[6][7], m[6];
        memset(num, 0, sizeof(num));
        memset(m, 0, sizeof(m));
        for(int i = 0; i < K; i++){
            if(a[i] % 2 == 0)   m[2] = max(m[2], 1);
            if(a[i] % 4 == 0)   m[2] = max(m[2], 2);
            if(a[i] % 8 == 0)   m[2] = max(m[2], 3);
            if(a[i] % 3 == 0)   m[3] = max(m[3], 1);
            if(a[i] % 9 == 0)   m[3] = max(m[3], 2);
            if(a[i] % 81 == 0)   m[3] = max(m[3], 3);
            if(a[i] % 5 == 0)   m[5] = max(m[5], 1);
            if(a[i] % 25 == 0)   m[5] = max(m[5], 2);
            if(a[i] % 125 == 0)   m[5] = max(m[5], 3);
        }
        for(int i = 0; i < m[3] && k < 3; i++) {
            putchar('3');
            k++;
        }
        for(int i = 0; i < m[5] && k < 3; i++) {
            putchar('5');
            k++;
        }
        if(k == 3)  putchar('\n');
        if(k == 0)  {puts("222"); k = 3;}
        if(k == 1 && m[2] == 2) {puts("24"); k = 3;}
        if(k == 1 && m[2] == 1) {puts("22"); k = 3;}
        if(k == 2 && m[2] == 2) {puts("4");  k = 3;}
        if(k == 2 && m[2] == 1) {puts("2");  k = 3;}
        if(k != 3) {
            for(int i = k; i < 3; i++)   printf("2");
            putchar('\n');
        }


        //puts("--");
    }
}
