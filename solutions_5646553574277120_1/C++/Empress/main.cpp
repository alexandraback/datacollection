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
    freopen("C-large.in","r",stdin);
    freopen("out.out","w",stdout);
    int t, ca=1;
    scanf("%d", &t);
    while(t--)
    {
        LL c, d, v;
        cin>>c>>d>>v;
        LL flag=0;
        int ans=0;
        for(int i=0;i<d;i++)
        {
            LL x;
            cin>>x;
            while(x>flag+1)
                flag+=c*(flag+1), ans++;
            flag+=c*x;
        }
        printf("Case #%d: ", ca++);
        while(flag<v)
            flag+=c*(flag+1), ans++;
        printf("%d\n", ans);
    }
    return 0;
}
