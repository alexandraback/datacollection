#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int n, a, c, l;
bool b[11];

int main() {
    int i, j;
    scanf("%d", &n);
    for (i=0; i<n; ++i) {
        scanf("%d", &a);
        if (a == 0) {
            printf("Case #%d: INSOMNIA\n", i+1);
        } else {
            c = 0;
            fill(b, b+10, 0);
            for (j=1; c<10; ++j) {
                l=j*a;
                while (l>0) {
                    if (b[l%10] == 0) {
                        b[l%10] = 1;
                        c++;
                    }
                    l/=10;
                }
            }
            printf("Case #%d: %d\n", i+1, a*(j - 1));
        }
    }
    return 0;
}
