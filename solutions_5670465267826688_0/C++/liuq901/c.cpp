#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct factor
{
    bool nega;
    int value;
    factor():nega(false),value(1){}
    factor(char ch):nega(false),value(ch=='i'?2:ch=='j'?3:4){}
    factor(bool nega,int value):nega(nega),value(value){}
    factor negate() const
    {
        return(factor(!nega,value));
    }
};
inline factor operator *(const factor &a,const factor &b)
{
    if (a.nega)
        return((a.negate()*b).negate());
    if (b.nega)
        return((a*b.negate()).negate());
    if (a.value==1)
        return(b);
    if (b.value==1)
        return(a);
    if (a.value==b.value)
        return(factor(true,1));
    bool nega=a.value==2 && b.value==4 || a.value==3 && b.value==2 || a.value==4 && b.value==3;
    return(factor(nega,9-a.value-b.value));
}
bool solve(int L,ll X,char *a)
{
    factor all;
    for (int i=0;i<X%4;i++)
        for (int j=1;j<=L;j++)
            all=all*factor(a[j]);
    if (!all.nega || all.value!=1)
        return(false); 
    int pre=-1,suf=-1,m=min(5LL,X);
    all=factor();
    for (int i=1;i<=m;i++)
        for (int j=1;j<=L;j++)
        {
            all=all*factor(a[j]);
            if (!all.nega && all.value==2)
            {
                pre=(i-1)*L+j;
                goto out1;
            }
        }
out1:
    all=factor();
    for (int i=1;i<=m;i++)
        for (int j=L;j;j--)
        {
            all=factor(a[j])*all;
            if (!all.nega && all.value==4)
            {
                suf=(i-1)*L+L-j+1;
                goto out2;
            }
        }
out2:
    return(pre!=-1 && suf!=-1 && pre+suf<L*X);
}
char a[10010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int L;
        ll X;
        scanf("%d%lld%s",&L,&X,a+1);
        static int id=0;
        printf("Case #%d: %s\n",++id,solve(L,X,a)?"YES":"NO");
    }
    return(0);
}

