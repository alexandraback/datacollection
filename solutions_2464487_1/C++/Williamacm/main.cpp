#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;

class Big
{
public:
    static const int Maxn = 100, Bit = 10000;
    int a[Maxn],l;
    Big()
    {
        memset(a, 0, sizeof(a));
        a[(l = 0)++] = 0;
    }
    Big(int v)
    {
        memset(a, 0, sizeof(a)), l = 0;
        while(v)
        {
            a[l++] = v % Bit;
            v /= Bit;
        }
        if(!l) a[l++] = 0;
    }    Big(char *s)
    {
        memset(a, 0, sizeof(a)), l = 0;
        for(int i = strlen(s) - 1; i >= 0; i -= 4)
        {
            int t = 0;
            for(int j = max(i - 3, 0); j <= i; j++) t = t * 10 + s[j] - '0';
            a[l++] = t;
        }
    }
    bool operator < (const Big &o)
    {
        if(l != o.l) return l < o.l;
        for(int i = l - 1; i >= 0; i--)
        {
            if(a[i] != o.a[i]) return a[i] < o.a[i];
        }
        return 0;
    }
    bool operator == (const Big &o)
    {
        if(l != o.l) return 0;
        for(int i = l - 1; i >= 0; i--)
        {
            if(a[i] != o.a[i]) return 0;
        }
        return 1;
    }
    Big operator + (const Big &o)
    {
        Big r;
        r.l = max(l, o.l);
        for(int i = 0; i < r.l; i++)
        {
            r.a[i] += a[i] + o.a[i];
            r.a[i + 1] += r.a[i] / Bit;
            r.a[i] %= Bit;
        }
        while(r.a[r.l]) r.a[r.l + 1] += r.a[r.l] / Bit, r.a[r.l++] %= Bit;
        return r;
    }
    Big operator * (const Big &o)
    {
        Big r;
        for(int i = 0; i < l; i++)
        {
            for(int j = 0; j < o.l; j++)
            {
                r.a[i + j] += a[i] * o.a[j];
                r.a[i + j + 1] += r.a[i + j] / Bit;
                r.a[i + j] %= Bit;
            }
        }
        r.l = l + o.l;
        while(r.l - 1 && !r.a[r.l - 1]) r.l --;
        return r;
    }
    Big operator - (const Big &o)
    {
        Big r = *this;
        for(int i = 0; i < l; i++)
        {
            if((r.a[i] -= o.a[i]) < 0) r.a[i] += Bit, r.a[i + 1] --;
        }
        while(r.l - 1 && !r.a[r.l - 1]) r.l --;
        return r;
    }
    Big operator / (const int &o)
    {
        Big r;
        int t = 0;
        for(int i = l - 1; i >= 0; i--)
        {
            t = t * Bit + a[i];
            r.a[i] = t / o, t %= o ;
        }
        r.l = l;
        while(r.l - 1 && !r.a[r.l - 1]) r.l --;
        return r;
    }
    void out() const
    {
        printf("%d", a[l - 1]);
        for(int i = l - 2; i >= 0; i--)
        {
            printf("%04d",a[i]);
        }
                puts("");
//        }
    }
};

char tt[22],ss[22];
Big r,t;
Big cal(Big n)
{
    Big ans;
    return ans=r*n*2+n*n*2-n;
}
void init()
{
    scanf("%s%s",ss,tt);
    r=ss,t=tt;
    Big l=1,r("1000000000000000000");
    while(l<r||l==r)
    {
        Big mid=(l+r)/2;
        if(t<cal(mid)) r=mid-1;
        else l=mid+1;
    }
    r.out();
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int w;cin>>w;
    for(int id=1;id<=w;id++)
    {
        printf("Case #%d: ",id);
        init();
    }
//    cout << "Hello world!" << endl;
    return 0;
}
