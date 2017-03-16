
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

bool isdig(char c) {
    if(c>='0' && c<='9') {
        return true;
    }
    return false;
}

void print(int x, int n) {
    int t = x, ct = 0;
    if(0 == t) ct = 1;
    while(t) {
        t /= 10;
        ++ct;
    }
    for(int i=0; i<n-ct; ++i) {
        putchar('0');
    }
    printf("%d", x);
}

int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    int icase;
    char chc[20], chj[20];
    scanf("%d", &icase);
    for(int i=1; i<=icase; ++i) {
        scanf("%s%s", chc, chj);
        //puts(chc); puts(chj);
        int c, j, min_d = 1000, min_c = 1000, min_j = 1000;
        int len = strlen(chc);
        if(1 == len) {
            chc[2] = chc[0];
            chj[2] = chj[0];
            chc[0] = chc[1] = chj[0] = chj[1] = '0';
        }
        if(2 == len) {
            chc[2] = chc[1];
            chc[1] = chc[0];

            chj[2] = chj[1];
            chj[1] = chj[0];
            chc[0] = chj[0] = '0';
        }
        //puts(chc);
        for(int a=0; a<1000; ++a) {
            if(isdig(chc[0])) {
                if(a/100 != chc[0]-'0') {
                    continue;
                }
            }

            if(isdig(chc[1])) {
                if(a/10%10 != chc[1]-'0') {
                    continue;
                }
            }

            if(isdig(chc[2])) {
                if(a%10 != chc[2]-'0') {
                    continue;
                }
            }

            for(int b=0; b<1000; ++b) {
                if(isdig(chj[0])) {
                    if(b/100 != chj[0]-'0') {
                        continue;
                    }
                }
                if(isdig(chj[1])) {
                    if(b/10%10 != chj[1]-'0') {
                        continue;
                    }
                }
                if(isdig(chj[2])) {
                    if(b%10 != chj[2]-'0') {
                        continue;
                    }
                }
                if(abs(a-b) < min_d) {
                    min_d = abs(a-b);
                    min_c = a;
                    min_j = b;
                }
                else if(abs(a-b) == min_d) {
                    if(a < min_c) {
                        min_c = a;
                        min_j = b;
                    }
                    else if(a == min_c) {
                        if(b < min_j) {
                            min_j = b;
                        }
                    }
                }
            }
        }

        printf("Case #%d:", i);
        putchar(' ');
        print(min_c, len);
        putchar(' ');
        print(min_j, len);
        putchar('\n');
    }
    return 0;
}
