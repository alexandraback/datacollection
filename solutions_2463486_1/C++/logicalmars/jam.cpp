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
            printf("%lldLL, ", i*i);
        }                
    }

    // printf("%lld\n", count);
}

ll list[] = 
{
    1LL, 4LL, 9LL, 121LL, 484LL, 10201LL, 12321LL, 14641LL, 40804LL, 44944LL, 1002001LL, 1234321LL, 
    4008004LL, 100020001LL, 102030201LL, 104060401LL, 121242121LL, 123454321LL, 125686521LL, 400080004LL, 
    404090404LL, 10000200001LL, 10221412201LL, 12102420121LL, 12345654321LL, 40000800004LL, 1000002000001LL, 
    1002003002001LL, 1004006004001LL, 1020304030201LL, 1022325232201LL, 1024348434201LL, 1210024200121LL, 
    1212225222121LL, 1214428244121LL, 1232346432321LL, 1234567654321LL, 4000008000004LL, 4004009004004LL
};

void work_fast()
{
    scanf("%lld%lld", &a, &b);
    int count = 0;
    for (int i = 0;i<39;i++)
    {
        if (list[i] >= a && list[i] <= b)
        {
            count ++;
        }                
    }

    printf("%d\n", count);
}

int main()
{
    // printf("%d\n", is_hui(11 * 11));
    freopen("C-large-1.in", "r", stdin);
    // freopen("A-large-practice.in", "r", stdin);    
    // freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
 
    int cs, t;
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++)
    {
        printf("Case #%d: ", cs);
        work_fast();
    }
 
    return 0;
}