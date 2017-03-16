#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
using namespace std;

typedef long long ll;
ll a, b;
char digits[20];

int is_hui(ll x)
{
    sprintf(digits, "%lld", x);
    int len = strlen(digits);
    for (int i = 0, j = len-1;i < j; i++, j--)
    {
        if (digits[i] != digits[j])
            return 0;
    }

    return 1;
}

void work()
{
    scanf("%lld%lld", &a, &b);
    ll start = (ll) sqrt(a) - 2;    
    ll end = (ll) sqrt(b) + 2;

    ll count = 0;

    for (ll i = start;i<=end;i++)
    {        
        if (i * i < a)
            continue;
        if (i * i > b)
            break;

        if (is_hui(i) && is_hui(i * i))
        {
            count ++;
        }
    }

    printf("%lld\n", count);
}
 
int main()
{
    // printf("%d\n", is_hui(11 * 11));
    freopen("C-small-attempt0.in", "r", stdin);
    // freopen("A-large-practice.in", "r", stdin);    
    // freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
 
    int cs, t;
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++)
    {
        printf("Case #%d: ", cs);
        work();
    }
 
    return 0;
}