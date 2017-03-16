#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

typedef long long ll;


set<ll> powers;
ll power[30];


ll inverse(ll x)
{
    ll ret = 0;
    while (x)
        {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
    return ret;
}



ll calc(ll x)
{
    ll ret = x;
    ll cur = 1;
    ll interval = 1;
    ll base = 1;

    while (cur <= x)
        {
            ret = min(ret, interval + x - cur);

            if (cur == x)
                break ;

            ll up = * powers.upper_bound(cur);

            if (up <= x)
                {
                    if (cur == 1)
                        {
                            cur = 10;
                            ++base;
                            interval = 10;
                            continue ;
                        }
                    cur += power[base / 2] - 1;
                    cur = inverse(cur);
                    interval += power[base / 2] + up - cur;
                    ++base;
                    cur = up;
                }
            else
                {
                    if (!(x % 10))
                        {
                            ++interval;
                            --x;
                        }
                    ll inv = inverse(x);
                    inv %= power[base >> 1];
                    cur += inv;
                    interval += inv;
                    cur = inverse(cur);
                    ++interval;
                    interval += x - cur;
                    cur = x;
                }
        }
    return ret;
}

void init()
{
    ll c = 1;
    power[0] = 1;
    for (int i = 1; i <= 18; ++i)
        {
            powers.insert(c);
            c = c * 10;
            power[i] = c;
        }
}



int main()
{
    init();
    int t;
    cin >> t;
    for (int case_id = 1; case_id <= t; ++case_id)
        {
            ll c;
            cin >> c;
            printf("Case #%d: %lld\n", case_id, calc(c));
        }
    return 0;
}
