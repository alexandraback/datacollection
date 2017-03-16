#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#pragma comment(linker, "/STACK:167772160")

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.);

const int MX = 1e7;

ll X[1000500];
int cnt = 0;

char s[10];
bool isPal(int x)
{
    int l = 0;
    while(x)
    {
        s[l++] = x%10 + '0';
        x /= 10;
    }
    for (int i = 0; i < l; ++i)
        if (s[i] != s[l - i - 1])
            return false;
    return true;
}

void init()
{
    for (ll i = 1; i < MX; ++i)
    {
        if (isPal(i) && isPal(i*i))
        {
            X[cnt++] = i*i;
//            printf("%lld ", i*i);
        }
    }
}

void solve()
{
    ll A, B;
    scanf("%lld%lld", &A, &B);
    printf("%d\n", upper_bound(X, X + cnt, B) - lower_bound(X, X + cnt, A));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("test.txt", "r", stdin);
#endif
    init();
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        printf("Case #%d: ", i + 1);
        solve();
    }
	return 0;
}