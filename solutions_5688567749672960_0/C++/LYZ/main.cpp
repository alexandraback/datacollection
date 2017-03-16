#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

long long now,ans;
long long tar;
int WStar,WSnow;
int T,nowT;

inline long long Turn(long long x)
{
    int Temp[100];
    int Len;

    for (Len=0;x>0;Len++)
    {
        Temp[Len]=x%10LL;
        x/=10LL;
    }
    long long ret=0LL;
    for (int i=0;i<Len;i++)
        ret=10LL*ret+Temp[i];

    return ret;
}
inline int WS(long long x)
{
    int ret=0;
    for (;x>0;ret++) x/=10LL;
    return ret;
}
inline long long MakeDivision(int Len)
{
    long long ret=1;
    for (int i=1;i<Len;i++)
    {
        ret*=10;
        if (i*2>=Len) ret+=9;
    }
    return ret;
}
inline long long MakeDivision(int Len,long long Ref)
{
    int Temp[100];
    int RefLen;

    for (RefLen=0;Ref>0;RefLen++)
    {
        Temp[RefLen]=Ref%10LL;
        Ref/=10LL;
    }

    long long ret=1;
    RefLen=RefLen/2+RefLen%2;
    for (int i=1;i<Len;i++)
    {
        ret*=10;
        if (i*2>=Len) ret+=Temp[RefLen++];
    }
    return ret;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0_lyz.out","w",stdout);

    scanf("%d",&T);
    for (nowT=1;nowT<=T;nowT++)
    {
        scanf("%lld",&tar);
        now=1LL;ans=1LL;
        if (tar%10==0) {tar--;ans++;}
        WStar=WS(tar);
        while (now!=tar)
        {
            cerr << now <<"  " << ans<< endl;
            WSnow=WS(now);
            if (WSnow<WStar)
            {
                if (WSnow+1<WStar)
                {
                    ans+=MakeDivision(WSnow+1)-now;
                    now=MakeDivision(WSnow+1);
                    now=Turn(now);
                    ans++;
                }
                else
                {
                    ans+=MakeDivision(WSnow+1,tar)-now;
                    now=MakeDivision(WSnow+1,tar);
                }

            }
            else
                if ( tar-Turn(now)  < tar-now )
                {
                    ans++;
                    now=Turn(now);
                }
                else
                {
                    ans+=tar-now;
                    now=tar;
                }
        }

        printf("Case #%d: %lld\n",nowT,ans);
    }

    return 0;
}
