#include <cstdio>
#include <iostream>
using namespace std;
// #define For(i,x) for (int i=0; i<(int)(x); i++)

int calc(int a, int b, int k) {

    int ans = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            int x = i & j;
            if (x < k) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    int ncases;
    scanf("%d", &ncases);

    for (int cc = 0; cc < ncases; cc++) {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);

        printf("Case #%d: %d\n", cc+1, calc(a, b, k));
    }
}


