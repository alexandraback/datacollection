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

int a[1003];
int rest[1003];

int solve(int mini)
{
    int res=0;
    for (int i=1000; i>mini; --i)
        res+=a[i]*((i-1)/mini);
    return res+mini;
}

int main()
{
    freopen("inputb.txt", "r", stdin);
    freopen("outputb.txt", "w", stdout);
    int T, ans, temp, n;
    cin >> T;
    for (int t=1; t<=T; ++t)
    {
        ans=1000000009;
        scanf("%d", &n);
        for (int i=0; i<n; ++i)
        {
            scanf("%d", &temp);
            ++a[temp];
        }
        for (int i=1; i<1001; ++i)
            ans=min(ans, solve(i));
        printf("Case #%d: %d\n", t, ans);
        if (t==T)
            break;
        for (int i=0; i<1001; ++i)
            a[i]=0;
    }


    return 0;
}

