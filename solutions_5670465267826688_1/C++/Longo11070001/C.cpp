#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define pb push_back
using namespace std;

const int maxn = 10010;
char str[maxn];
int num[maxn];

int calc(int a,int b)
{
    int t = 1;
    if(a*b < 0) t = -1;
    a = abs(a);
    b = abs(b);
    if(a == 1) return t*b;
    if(b == 1) return t*a;
    if(a == b) return -1*t;
    if(a == 2 && b == 3) return 4*t;
    if(a == 2 && b == 4) return -3*t;
    if(a == 3 && b == 2) return -4*t;
    if(a == 3 && b == 4) return 2*t;
    if(a == 4 && b == 2) return 3*t;
    return -2*t;
}

int main()
{
    //freopen("C-large.in","r",stdin);
    //freopen("C-large.out","w",stdout);
    int T,cas,L,i,cur,tmp,pas,p1,p2;
    long long x;
    scanf("%d",&T);
    for(cas=1; cas<=T; cas++)
    {
        scanf("%d%lld",&L,&x);
        scanf("%s",str);
        printf("Case #%d: ",cas);
        cur = 1;
        for(i=0; i<L; i++) num[i] = str[i] - 'i' + 2, cur = calc(cur,num[i]);
        tmp = x%4; pas = 1;
        for(i=0; i<tmp; i++)
        {
            pas = calc(pas,cur);
        }
        if(pas != -1)
        {
            puts("NO"); continue;
        }
        tmp = 1;
        p1 = p2 = -1;
        for(i=0; i<4*L; i++)
        {
            tmp = calc(tmp,num[i%L]);
            if(tmp == 2)
            {
                p1 = i; break;
            }
        }
        tmp = 1;
        for(i=4*L-1; i>=0; i--)
        {
            tmp = calc(num[i%L],tmp);
            if(tmp == 4)
            {
                p2 = i; break;
            }
        }
        if(p1 == -1 || p2 == -1 || 1LL*(p1+1+4*L-p2) >= x*L)
        {
            puts("NO"); continue;
        }
        else
        {
            puts("YES"); continue;
        }
    }
    return 0;
}
