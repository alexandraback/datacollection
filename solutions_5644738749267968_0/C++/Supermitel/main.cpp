#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

set<double> a;
set<double> b;
int T, n;

void citire()
{
    double x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &x);
        a.insert(x);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &x);
        b.insert(x);
    }
}

void solve_war()
{
    set<double>::iterator it;
    int win = 0;
    for(int i = 0; i < n; i++)
    {
        it = b.lower_bound(*a.begin());
        if(it == b.end())
        {
            win++;
            b.erase(b.begin());
        }
        else
            b.erase(it);
        a.erase(a.begin());
    }
    printf("%d\n", win);
}

void solve_cheating()
{
    int win = 0;
    set<double>::iterator it;
    set<double>::iterator bit = b.begin();
    for(it = a.begin(); it != a.end(); it++)
        if(*it > *bit)
        {
            win++;
            bit++;
        }
    printf("%d ", win);
}
int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    scanf("%d", &T);
    for(int i = 1; i <= T; i++)
    {
        printf("Case #%d: ", i);
        a.clear();
        b.clear();
        citire();
        solve_cheating();
        solve_war();
    }
    return 0;
}
