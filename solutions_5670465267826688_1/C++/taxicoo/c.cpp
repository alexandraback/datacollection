#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back

bool mi;

char mul(char a, char b)
{
    if (a=='1')
        return b;
    if (b=='1')
        return a;
    if (a==b)
    {
        mi=!mi;
        return '1';
    }
    if (a=='i')
    {
        if (b=='j')
            return 'k';
        mi=!mi;
        return 'j';
    }
    if (a=='j')
    {
        if (b=='k')
            return 'i';
        mi=!mi;
        return 'k';
    }
    if (b=='i')
        return 'j';
    mi=!mi;
    return 'i';
}

int main()
{
    freopen("inputc.txt", "r", stdin);
    freopen("outputc.txt", "w", stdout);
    int T;
    ll l, x, n, last;
    string s;
    cin >> T;
    for (int t=1; t<=T; ++t)
    {
        cin >> l >> x;
        cin >> s;
        n=l*x;
        last=4*l;
        char prev='1', opa='1';
        mi=false;
        for (int i=0; i<l; ++i)
            opa=mul(opa, s[i]);
        bool mi2=mi;
        mi=false;
        bool ok;
        int i1=0;
        for (int mode=1; mode<4; ++mode)
        {
            ok=false;
            for (ll j=0; (j<last) && (i1<n); ++i1, ++j)
            {
                prev=mul(prev, s[i1%l]);
                if (t==2)
                    cout << "";
                if ((mode==1) && (prev=='i') && (!mi))
                {
                    ok=true;
                    prev='1';
					++i1;
                    break;
                }
                else if ((mode==2) && (prev=='j') && (!mi))
                {
                    ok=true;
                    prev='1';
					++i1;
                    break;
                }
                else if ((mode==3) && (prev=='k') && (!mi) && ((i1+1)%l==0))
                {
                    ok=true;
                    break;
                }
            }
            if (!ok)
                break;
        }
        if (!ok)
        {
            printf("Case #%d: NO\n", t);
            continue;
        }
        ok=false;
        if (((n-i1-1)%l==0) && (((n-i1-1)/l)%4==0) || ((opa=='1') && ((!mi2) || ((n-i1-1)/l)%2==0)))
            ok=true;
        if (ok)
            printf("Case #%d: YES\n", t);
        else
            printf("Case #%d: NO\n", t);
    }


    return 0;
}

