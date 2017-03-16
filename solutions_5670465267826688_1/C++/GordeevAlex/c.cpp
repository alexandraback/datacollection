#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ldb;

#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

const int MAXN = 2e5 + 10;

const int m[5][5] = {
    { 0, 0, 0, 0, 0},
    { 0, 1, 2, 3, 4},
    { 0, 2,-1, 4,-3},
    { 0, 3,-4,-1, 2},
    { 0, 4, 3,-2,-1}
};

int sgn(int x) {
    return (x > 0 ? 1 : -1);
}

int l;
ll x;
int n;
int s[MAXN];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int T;
    scanf("%d ", &T);
    forn(test, T) {
        printf("Case #%d: ", test + 1);

        cin >> l >> x;
        
        x = min(x, x % 4 + 12);
        n = l * x;

        forn(i, l) {
            char c;
            scanf(" %c ", &c);
            if (c == 'i')
                s[i] = 2;
            else if (c == 'j')
                s[i] = 3;
            else
                s[i] = 4;
        }
        forab(i, l, n)
            s[i] = s[i - l];

        int pr = 1;
        int k = 0;

        forn(i, n) {
            pr = sgn(pr) * m[abs(pr)][s[i]];

            if (k == 0 && pr == 2) 
                k = 1;

            if (k == 1 && pr == 4) 
                k = 2;
        }

        bool ans = ((pr == -1) && k == 2);

        printf(ans ? "YES\n" : "NO\n");
    }
    return 0;
}
