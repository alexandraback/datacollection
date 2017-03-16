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

//#include <conio.h>
int test;
long long r, t;

bool check(long long m) {
    long long k=m*2-1;
    long long res=(k+1)/2;
    if ((double)r*2+k > (double)t/res+1) return false;
    return (r*2+k)*res<=t;
}
int main() {
    freopen("r1a.in", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> test;
    FOR(te, 1, test) {
        cin >> r >> t;
        long long l=1, h=10000000000000LL;
        while (l+1<h) {
            long long m=(l+h)/2;
            if (check(m)) l=m; else h=m-1;
        }
        printf("Case #%d: ", te);
        if (check(h)) cout << h << endl;
        else cout << l << endl;
    }
    //getch();
    return 0;
}
