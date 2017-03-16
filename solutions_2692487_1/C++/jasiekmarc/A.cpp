#include <algorithm>
#include <cstdio>
using namespace std;

int testcase() {
    int a, n;
    scanf("%d %d", &a, &n);
    int motes[n];
    for(int i = 0; i < n; i ++)
        scanf("%d", &motes[i]);
    sort(motes, motes + n);

    int ans = 0;
    int mina = n;
    int curmot = a;

    for(int i = 0; i < n; i ++) {
        while(curmot <= motes[i]) {
            if(curmot == 1)
                return mina;
            curmot += curmot - 1;
            ans ++;
        }
        curmot += motes[i];
        mina = min(mina, ans + n - i - 1);
    }
    return mina;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i ++) {
        printf("Case #%d: %d\n", i, testcase());
    }
}