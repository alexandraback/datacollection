#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DOW(i, a, b) for(int i=a; i>=b; i--)
#define FOREACH(it, c) for(typeof(c.begin()) it=c.begin(); it!=c.end(); it++)
#define RESET(c, val) memset(c, val , sizeof(c))

#include <conio.h>
int test, k, n, a[10000];

int main() {
    freopen("r1b_1s.in", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> test;
    FOR(t, 1, test) {
        cin >> k;
        cin >> n;
        FOR(i, 1, n) scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        int res=n, cc=0;
        if (k==1) res=n; else
        FOR(i, 1, n) {
           while (k<=a[i]) k=k*2-1, cc++;
           k+=a[i];
           res=min(res, cc+n-i);
        }
        printf("Case #%d: %d\n", t, res);
    }
    //getch();
    return 0;
}
