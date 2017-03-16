#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int max_bound = 2e7;

int tmp[20];
vector<ll> goods;

inline bool is_palindrome(ll a)
{
    int kv = 0;
    while (a)
    {
        tmp[kv++] = a % 10;
        a /= 10;
    }
    for (int i = 0; i < kv; i++) if (tmp[i] != tmp[kv - i - 1]) return false;
    return true;
}

int main()
{
    goods.resize(0);
    for (ll i = 1; i < max_bound; i++) if (is_palindrome(i) && is_palindrome(i * i)) goods.push_back(i * i);
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        ll l, r;
        scanf(LLD LLD, &l, &r);
        printf("Case #%d: ", T);
        printf("%d\n", lower_bound(goods.begin(), goods.end(), r + 1) - lower_bound(goods.begin(), goods.end(), l));
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
