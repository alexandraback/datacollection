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

char s[25];
ll st10[20];

ll calc(ll x, int len)
{
    ll curx = x;
    x -= st10[len - 1];
    for (int i = 0; i < len; i++)
    {
        s[i] = (curx % 10);
        curx /= 10;
    }
    s[len - 1]--;
    ll curans2 = 0;
    for (int i = 0; i < len; i++) curans2 += s[i] * st10[min(i, len - i - 1)];
    if (s[0] == 0) curans2 = 1e18;
    s[len - 1]++;
    s[0]--;
    int t = 0;
    while (s[t] < 0)
    {
        s[t] += 10;
        s[t + 1]--;
        t++;
    }
    ll curans1 = 0;
    for (int i = 0; i < len; i++) curans1 += s[i] * st10[min(i, len - i - 1)];
//     cout << x << ' ' << len << ' ' << curans1 + 1 << ' ' << curans2 + 2 << endl;
    return min(min(curans2 + 2, curans1 + 1), x);
}

int main()
{
    st10[0] = 1;
    for (int i = 1; i < 20; i++) st10[i] = 10 * st10[i - 1];
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d: ", T);
        
        ll n;
        cin >> n;
        ll cur = 1;
        ll answer = 1;
        int curlen = 1;
        while (true)
        {
            if (n < 10 * cur)
            {
                answer += calc(n, curlen);
                printf(LLD "\n", answer);
                break;
            } else
            {
                answer += calc(10 * cur - 1, curlen);
                answer++;
            }
            cur *= 10;
            curlen++;
//             cout << cur << ' ' << answer << endl;
        }

        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
