//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#define FI first
#define SE second
#define MP make_pair
using namespace std;
typedef long long LL;

int dlg(LL x)
{
    int ret = 0;
    while(x)
    {
        ret++;
        x /= 10;
    }
    return ret;
}
LL odwr(LL x)
{
    LL ret = 0;
    while(x)
    {
        ret = ret*10+x%10;
        x /= 10;
    }
    return ret;
}
int niezerow(LL x)
{
    int ret = 0;
    while(x%10 == 0)
    {
        ret++;
        x /= 10;
    }
    return ret;
}
LL pot(LL a, int k)
{
    LL ret = 1;
    for(int i = 1;i <= k;i++)
        ret *= a;
    return ret;
}

pair<LL,LL> podziel(LL orx)
{
    int dlug = dlg(orx);
    pair<LL,LL> ret = MP(0,0);
    
    LL x = odwr(orx);
    for(int i = 1;i <= dlug/2;i++)
    {
        ret.FI = ret.FI*10+x%10;
        x /= 10;
    }
    for(int i = 1;i <= (dlug+1)/2;i++)
    {
        ret.SE = ret.SE*10+x%10;
        x /= 10;
    }
    
    return ret;
}

LL obl(LL n, LL cur)
{
    LL ret = n-cur;
    
    pair<LL, LL> podzial = podziel(n);
    //cerr << "Podzial: " << podzial.FI << " " << podzial.SE << endl;
    LL ret2 = odwr(podzial.FI)+1+podzial.SE-1;
    
    LL Kret = ret;
    if(podzial.SE != 0) Kret = min(Kret, ret2);
    return Kret;
}

LL algorytm(LL n)
{
    LL wyn = 1, cur = 1;
    
    LL a = 9, b = 0;
    while(dlg(cur) < dlg(n))
    {
        wyn += a+(b>0)+b;
        cur *= 10;
        if(a < b) swap(a,b);
        b = b*10+9;
    }
    
    //cerr << "Cur: " << cur << " Wyn: " << wyn << endl;
    
    LL wyn2 = obl(n, cur);

    return wyn+wyn2;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int ti = 1;ti <= t;ti++)
    {
        LL n;
        scanf("%lld", &n);
        
        LL Kwyn = min(algorytm(n-1)+1, algorytm(n));
        
        printf("Case #%d: %lld\n", ti, Kwyn);
    }
    return 0;
}
