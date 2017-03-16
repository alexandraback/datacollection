#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;
long long t,n,l,sign=1,ksign;
char x,el;
std::vector< std::pair<long long,long long> > a;
bool ei,ej,ek,gasit;
void inmultire(char &A,char B)
{
    if(A=='i'&&B=='j')A = 'k';
    else if(A=='i'&&B=='k')A = 'j',sign = sign*(-1);
    else if(A=='j'&&B=='i')A = 'k',sign = sign*(-1);
    else if(A=='j'&&B=='k')A = 'i';
    else if(A=='k'&&B=='i')A = 'j';
    else if(A=='k'&&B=='j')A = 'i',sign = sign*(-1);
}
int main()
{
    freopen("text.in","r",stdin);
    freopen("text.out","w",stdout);
    scanf("%d",&t);
    for(long long k=1;k<=t;++k)
    {
        printf("Case #%lld: ",k);
        scanf("%lld %lld ",&n,&l);
        a.clear();
        el = 0;sign = 1;
        ei = false;ej = false;ek = false;
        for(long long i=1;i<=n;++i)
        {
            scanf("%c",&x);
            if(el==x)
            {
                el = 0;
                sign = sign*(-1);
            }
            else if(el==0)el = x;
            else inmultire(el,x);
            a.push_back( std::make_pair(el,sign) );
            if(el=='i'&&sign==1)ei = true;
            else if(el=='k'&&sign==1&&ei)ej = true;
        }
        if(l==1&&el==0&&sign==-1)ek = true;
        if(ei&&ej&&ek){printf("YES\n");continue;}
        else if(l==1){printf("NO\n");continue;}

        if(el==0&&sign==1){printf("NO\n");continue;}
        else if(el==0&&sign==-1&&l%2==0){printf("NO\n");continue;}
        else if(el!=0&&l%4!=2){printf("NO\n");continue;}
        else ek = true;

        ksign = sign;
        for(long long i=2;i<=l&&i<=50;++i)
        {
            for(long long j=0;j<a.size();++j)
            {
                x = a[j].first;
                sign = a[j].second;
                if(x==el)
                {
                    x = 0;
                    sign = sign*(-1);
                }
                else if(x==0)x = el;
                else inmultire(x,el);
                a[j].first = x;
                a[j].second = sign;
                if(x=='i'&&sign==1)ei = true;
                else if(x=='k'&&sign==1&&ei)ej = true;
            }
        }

        if(ei&&ej&&ek)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
