#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int a[4][4] = {{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
int b[4][4] = {{0,0,0,0},{0,1,0,1},{0,1,1,0},{0,0,1,1}};
char s[11111];
int sa[11111];
int trans(char c)
{
    switch (c)
    {
        case '1': return 0;
        case 'i': return 1;
        case 'j': return 2;
        case 'k': return 3;
        default : return 0;
    };
}
int main(int argv, char** argc)
{
    int T,t,n;
    if (argv > 1)
        freopen(argc[1], "r", stdin);
    if (argv > 2)
        freopen(argc[2], "w", stdout);
    scanf("%d",&T);
    for (int t = 1; t <= T; ++t)
    {
        int L;
        long long X;
        int fa,fb,ra,rb;
        scanf("%d%lld",&L,&X);
        //cerr << X << endl;
        scanf("%s",s);
        for (int i = 0; i < L; ++i)
            sa[i] = trans(s[i]);
        fa = 0, fb = 0;
        int ans1 = -1, ans2 = -1;
        for (int i = 0; i < 8*L; ++i)
        {
            fb = (fb + b[fa][sa[i%L]])%2;
            fa = a[fa][sa[i%L]];
            if (i == L-1)
                ra = fa, rb = fb;
            if (fa == 1 && fb == 0)
                if (ans1 == -1) ans1 = i+1;
        }
        fa = 0, fb = 0;
        for (int i = 0; i < 8*L; ++i)
        {
            fb = (fb + b[sa[L-1-i%L]][fa])%2;
            fa = a[sa[L-1-i%L]][fa];
            if (fa == 3 && fb == 0)
                if (ans2 == -1) ans2 = i+1;
        }
        fa = 0, fb = 0;
        for (int i = 0; i < int(X%4); ++i)
        {
            fb = (fb + b[fa][ra] + rb)%2;
            fa = a[fa][ra];
        }
        //printf("!!%d %d %d %d\n", ans1, ans2, ra, rb);
        if (fa || fb == 0 || ans1 == -1 || ans2 == -1 || ((long long)ans1+ans2>=X*L))
            printf("Case #%d: NO\n",t);
        else printf("Case #%d: YES\n",t);
    }
    return 0;
}