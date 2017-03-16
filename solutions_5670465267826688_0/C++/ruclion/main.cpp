#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <ctype.h>
#include <limits.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <bitset>
#define CLR(a) memset(a, 0, sizeof(a))
#define REP(i, a, b) for(ll i = a;i < b;i++)
#define REP_D(i, a, b) for(ll i = a;i <= b;i++)

typedef long long ll;

using namespace std;

const ll maxn = 1000000+10;
struct statue
{
    char ch;
    ll f;
};
statue change[1000][1000];
void getChange()
{
    change['1']['1'].ch = '1';
    change['1']['i'].ch = 'i';
    change['1']['j'].ch = 'j';
    change['1']['k'].ch = 'k';

    change['1']['1'].f = 1;
    change['1']['i'].f = 1;
    change['1']['j'].f = 1;
    change['1']['k'].f = 1;
////////////////////////////////////////
    change['i']['1'].ch = 'i';
    change['i']['i'].ch = '1';
    change['i']['j'].ch = 'k';
    change['i']['k'].ch = 'j';

    change['i']['1'].f = 1;
    change['i']['i'].f = -1;
    change['i']['j'].f = 1;
    change['i']['k'].f = -1;
///////////////////////////////////////
    change['j']['1'].ch = 'j';
    change['j']['i'].ch = 'k';
    change['j']['j'].ch = '1';
    change['j']['k'].ch = 'i';

    change['j']['1'].f = 1;
    change['j']['i'].f = -1;
    change['j']['j'].f = -1;
    change['j']['k'].f = 1;
//////////////////////////////////////////
    change['k']['1'].ch = 'k';
    change['k']['i'].ch = 'j';
    change['k']['j'].ch = 'i';
    change['k']['k'].ch = '1';

    change['k']['1'].f = 1;
    change['k']['i'].f = 1;
    change['k']['j'].f = -1;
    change['k']['k'].f = -1;
}
statue calcu_s_s(statue a, statue b)
{
    statue ans;
    ans.ch = change[a.ch][b.ch].ch;
    ans.f = change[a.ch][b.ch].f*a.f*b.f;
    return ans;
}
statue calcu_s_char(statue a, char b)
{
    statue ans;
    ans.ch = change[a.ch][b].ch;
    ans.f = change[a.ch][b].f*a.f;
    return ans;
}
ll ncase, l, x;
char s[maxn];
statue key;

void getS()
{
    key.ch = '1';
    key.f = 1;
    for(ll i = 0; i < l; i++)
    {
        key = calcu_s_char(key, s[i]);
    }
    for(ll i = 1; i <= 11; i++)
    {
        ll start = l*i;
        for(ll j = start; j-start < l; j++)
        {
            s[j] = s[j-start];
        }
    }
}

ll solve()
{
    getS();
    ll flag_i = 0, flag_j = 0;
    ll pos_i,pos_j;
    statue now;
    now.ch = '1';
    now.f = 1;
    for(ll i = 0; i < 10*l; i++)
    {
        now = calcu_s_char(now, s[i]);
        if(now.ch == 'i'&&now.f == 1)
        {
            flag_i = 1;
            pos_i = i;
            break;
        }
    }
    if(flag_i == 0)
        return 0;
    if(pos_i+2 >= (x*l))
        return 0;
    now.ch = '1';
    now.f = 1;
    for(ll i = (pos_i + 1)%l; i < 10*l; i++)
    {
        now = calcu_s_char(now, s[i]);
        if(now.ch == 'j'&&now.f == 1)
        {
            flag_j = 1;
            pos_j = i;
            break;
        }
    }
    if(flag_j == 0)
        return 0;
    pos_j = (pos_i + 1)/l*l + pos_j;
    if(pos_j + 1>= (x*l))
        return 0;
    pos_j++;
    ll last_kuai = x - (pos_j/l) - 1;
//    if(last_kuai < 0)
//    {
//        printf("dsafffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff\n");
//    }
    last_kuai %= 4;
    now.ch = '1';
    now.f = 1;
    for(ll i = (pos_j%l); i < l; i++)
    {
        now = calcu_s_char(now, s[i]);
    }
    for(ll i = 1; i <= last_kuai; i++)
    {
        now = calcu_s_s(now, key);
    }
    if(now.ch == 'k'&&now.f == 1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("C-small-attempt2.in", "r", stdin);
    //freopen("3Cin.txt", "r", stdin);
    freopen("3Cout.txt", "w", stdout);
    getChange();
    scanf("%lld", &ncase);
    for(ll _  =1; _ <= ncase; _++)
    {
        printf("Case #%lld: ", _);
        scanf("%lld%lld", &l, &x);
        scanf("%s", s);
        if(solve())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
