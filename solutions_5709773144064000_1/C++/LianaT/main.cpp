#include<stdio.h>
double x, f, c, tac, r, rez, ast;
int t, ii;

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%ld",&t);
    for (ii=1;ii<=t;ii++)
    {
        scanf("%lf %lf %lf",&c,&f,&x);
        r=2;
        rez=-1; tac=0;
        while ((tac+x/r<rez)||(rez==-1)) //?????
        {
            //if ((rez>tac+x/r)||(rez==-1))
                rez=tac+x/r;
            ast=c/r;
            tac+=ast;   r+=f;
        }
        printf("Case #%ld: %.7lf\n",ii,rez);
    }
    return 0;
}
