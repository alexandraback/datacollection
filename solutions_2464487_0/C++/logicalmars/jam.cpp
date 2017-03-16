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

void work()
{
    ll r, t;
    scanf("%lld%lld", &r, &t);

    double temp = 2.0 * r + 3;
    temp = (sqrt(temp * temp - 4 * 2 * (1+2*r-t)) - temp) / 4.0;

    ll n = (ll) floor(temp) - 2;
    // printf("init n = %lld\n", n);

    do
    {
        n ++;
        temp = 2.0 * n * n + (2.0 * r + 3.0) * n + 2.0 * r + 1; 
    }while (temp <= t);

    printf("%lld\n", n);
}
 
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
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