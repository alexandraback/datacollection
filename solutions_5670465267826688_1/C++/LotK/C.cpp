/*
 *
 * Only small case!
 */

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char temp[1000010];
long long l, x;
char str[10010];

void update_now_sign(int &now, int &sign, char x) {
    if(now == 0) {
        now = (x-'i') + 1;
    }
    else if(now == 1) {
        if(x == 'i') {
            now = 0;
            sign *= -1;
        }
        else if(x == 'j') {
            now = 3;
        }
        else {          // i*k
            now = 2;
            sign *= -1;
        }
    }
    else if(now == 2) {
        if(x == 'i') {     // j*i
            now = 3;
            sign *= -1;
        }
        else if(x == 'j') {
            now = 0;
            sign *= -1;
        }
        else {          // j*k
            now = 1;
        }
    }
    else if(now == 3) {
        if(x == 'i') { // k*i
            now = 2;
        }
        else if(x == 'j') {    // k*j
            now = 1;
            sign *= -1;
        }
        else {          // k*k
            now = 0;
            sign *= -1;
        }
    }
}

bool check() {
    int now = 0, sign = 1;
    for(int i=0 ; i<l ; i++) {
        update_now_sign(now, sign, str[i]);
    }
    if(now > 0) {
        if(x%4 == 2) return true;
        else return false;
    }
    else {
        if(sign == 1) return false;
        else if(x%2 == 0) return false;
        return true;
    }
}
int main() {
    int tt;
    scanf("%d", &tt);
    for(int t=0; t<tt ; t++) {
        scanf("%lld%lld", &l, &x);
        scanf("%s", str);
        strcpy(temp, str);
        for(int i=1 ; i<x ; i++) {
            strcat(temp, str);
            if(strlen(temp) > 200000) break;
        }

        int state = 1;
        int now = 0;    // 0: 1, 1: i, 2: j, 3: k
        int sign = 1;
        for(int i=0 ; i<l*x && i < 200000; i++) {
            update_now_sign(now, sign, temp[i]);

            if(sign == 1 && now == state) {
                state++;
                now = 0;
                sign = 1;
                if(state > 3) break;
            }
        }
        if(state > 3 && check())
            printf("Case #%d: YES\n", t+1);
        else
            printf("Case #%d: NO\n", t+1);
    }
}
