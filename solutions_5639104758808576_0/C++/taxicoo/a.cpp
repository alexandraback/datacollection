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



int main()
{
    freopen("inputa.txt", "r", stdin);
    freopen("outputa.txt", "w", stdout);
    int T, n, ans, num, temp;
    string s;
    cin >> T;
    for (int t=1; t<=T; ++t)
    {
        cin >> n >> s;
        ans=0;
        num=s[0]-'0';
        for (int i=1; i<=n; ++i)
        {
            temp=i-num;
            if (temp>0)
            {
                ans+=temp;
                num+=temp;
            }
            num+=s[i]-'0';
        }
        printf("Case #%d: %d\n", t, ans);
    }


    return 0;
}

