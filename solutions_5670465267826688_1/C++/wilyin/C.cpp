#include<bits/stdc++.h>
#define scf scanf
#define ptf printf
#define forp(i,j,k) for(int i=j;i<k;i++)
#define form(i,j,k) for(int i=j;i>k;i--)
#define sz(x) (int)x.size()
#define pb push_back
#define fst first
#define scd second
#define m_p make_pair
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

int I='i',J='j',K='k';

int mt[1000][1000],str[100000],p[100000];
char s[100000];

int sgn(int x)
{
    return x>0?1:(x<0?-1:0);
}

int cc(int x,int y)
{
    return sgn(x*y)*mt[abs(x)][abs(y)];
}


int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    mt[1][1]=1;mt[1][I]=I;mt[1][J]=J;mt[1][K]=K;
    mt[I][1]=I;mt[I][I]=-1;mt[I][J]=K;mt[I][K]=-J;
    mt[J][1]=J;mt[J][I]=-K;mt[J][J]=-1;mt[J][K]=I;
    mt[K][1]=K;mt[K][I]=J;mt[K][J]=-I;mt[K][K]=-1;
    int T,n;
    scf("%d",&T);
    LL x;
    forp(tcnt,0,T)
    {
        scf("%d%lld%s",&n,&x,s);
        int t0,t1,mm=1;
        forp(i,0,n)
        {
            str[i]=s[i];
            mm=cc(mm,str[i]);
        }
        int cyc;
        p[0]=1;
        for(int i=1;;i++)
        {
            p[i]=cc(p[i-1],mm);
            if(p[i]==p[0])
            {
                cyc=i;
                break;
            }
        }
        ptf("Case #%d: ",tcnt+1);
        if(p[x%cyc]!=-1)
        {
            puts("NO");
            continue;
        }
        t0=t1=1;
        LL l=1e14,r=1e14;
        forp(i,0,5*n)
        {
            t0=cc(t0,str[i%n]);
            if(t0==I)
            {
                l=i;
                break;
            }
        }
        form(i,5*n-1,-1)
        {
            t1=cc(str[i%n],t1);
            if(t1==K)
            {
                r=5*n-i;
                break;
            }
        }
        puts(l+r>x*n?"NO":"YES");
    }
    return 0;
}

