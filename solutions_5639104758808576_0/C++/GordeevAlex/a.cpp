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

const int MAXN = 1010;

int n;
int cnt[MAXN];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d ", &T);
    forn(testNum, T) {
        printf("Case #%d: ", testNum + 1);

        scanf("%d", &n);
        forn(i, n + 1) {
            char c;
            scanf(" %c ", &c);
            cnt[i] = c - '0';
        }

        int ans = 0, sum = 0;
        forn(i, n + 1) {
            if (sum < i) {
                ans += i - sum;
                sum = i;
            }
            sum += cnt[i];
        }

        printf("%d\n", ans);
    }
    return 0;
}
