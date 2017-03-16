#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

ll powten_smaller(ll n)
{
    ll pow10 = 1;
    while (pow10 * 10 <= n)
        pow10 *= 10;
    return pow10;
}

ll powten(int exp)
{
    ll p = 1;
    for (int i=0; i<exp; i++)
        p *= 10;
    return p;
}

string to_string(ll num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}

ll to_ll(string s)
{
    stringstream ss(s);
    ll num;
    ss >> num;
    return num;
}

string small_half(string s)
{
    return s.substr(0, s.size()/2);
}

int main()
{
    int T;
    cin >> T;
    for (int t=1; t<=T; t++)
    {
        ll n;
        cin >> n;
        ll sol;
        if (n <= 10)
            sol = n;
        else
        {
            sol = 10;
            ll cur = 10;
            int exp = 1;
            while (cur*10 <= n)
            {
                cur *= 10;
                exp++;
                ll small_p = powten(exp/2), big_p = cur / small_p;
                sol += small_p + big_p - 1;
            }
            exp++;
            ll small_p = powten(exp/2), big_p = 10*cur / small_p;
            //cout << "small_p " << small_p << "big_p " << big_p << endl;
            //cout << cur << endl;
            if (n > cur+big_p)
            {
                ll steps = 0;
                ll tmp = n-1;
                for (int i=exp/2; i<exp; i++)
                {
                    tmp /= 10;
                }
                for (int i=0; i<exp/2; i++)
                {
                    steps *= 10;
                    steps += tmp % 10;
                    tmp /= 10;
                }
                //cout << steps << endl;
                sol += steps;
                sol++; // reversing
                cur = (n-1) / big_p * big_p + 1;
                //cout << "cur: " << cur << endl;
                sol += n - cur;
            }
            else
            {
                sol += n - cur;
            }
        }
        printf("Case #%d: %lld\n", t, sol);
    }
}
