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
    int T, l, x, n;
    string s;
    cin >> T;
    for (int t=1; t<=T; ++t)
    {
        string temp;
        cin >> l >> x;
        cin >> s;
        for (int i=0; i<x; ++i)
            temp+=s;
        n=temp.length();
        int mode=1;
        char prev='1';
        mi=false;
        for (int i=0; i<n; ++i)
        {
            prev=mul(prev, temp[i]);
            if ((mode==1) && (prev=='i') && (!mi))
            {
                mode=2;
                prev='1';
            }
            else if ((mode==2) && (prev=='j') && (!mi))
            {
                mode=3;
                prev='1';
            }
        }
        if ((mode==3) && (prev=='k') && (!mi))
            printf("Case #%d: YES\n", t);
        else
            printf("Case #%d: NO\n", t);
    }


    return 0;
}

