#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <list>
#include <set>
#include <ctime>
#include <list>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define vi vector<int>
#define vd vector<double>
#define pii pair<int,int>
#define pdd pair<double,double>
#define ll long long
#define INF (1<<30)
using namespace std;

int d[18], len;
vector<ll> all;
void check(ll pal)
{
    ll sq = pal * pal;
    ll V = sq;
    len = 0;
    while(sq > 0)
    {
        d[len++] = sq % 10;
        sq /= 10;
    }
    for(int i = 0; 2 * i <= len; ++i)
    {
        if(d[i] != d[len - i - 1]) return;
    }
    //cout << V << ' ' << pal << '\n';
    all.pb(V);
}

void process_pals()
{
    int i, j, k;
    for(i = 1; i < 10; ++i) check(i);
    for(i = 1; i < 10000; ++i)
    {
        ll t = i;
        j = i;
        while(j > 0)
        {
            t = 10 * t + j % 10;
            j /= 10;
        }
        check(t);
        for(k = 0; k < 10; ++k)
        {
            t = 10 * i + k;
            j = i;
            while(j > 0)
            {
                t = 10 * t + j % 10;
                j /= 10;
            }
            check(t);
        }
    }
}

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    ll A, B;
    cin >> A >> B;
    int i, ans = 0;
    for(i = 0; i < all.size(); ++i)
    {
        if(all[i] >= A && all[i] <= B) ++ans;
    }
    printf("%d\n", ans);
}

int main()
{
    process_pals();
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
