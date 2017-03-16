//#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<climits>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
#include<map>
#include<queue>
#define lson l, mid
#define rson (mid+1), r
#define pb push_back

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, ca=1;
    scanf("%d", &t);
    while(t--)
    {
        int r, c, w;
        scanf("%d%d%d", &r, &c, &w);
        printf("Case #%d: ", ca++);
        printf("%d\n", r*(int)ceil(c*1.0/w)+(w-1));
    }
    return 0;
}
