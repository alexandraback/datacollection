#include<stdio.h>
#include<algorithm>
using namespace std;

int T,X,R,C;
int sol;

int main()
{
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);

    scanf("%d",&T);
    for(int it=1;it<=T;it++)
    {
        scanf("%d %d %d",&X,&R,&C);
        sol=0;
        if(R>C) swap(R,C);

        if(X==1) sol=1;
        if(X==2 && (R%2==0 || C%2==0) ) sol=1;
        if(X==3 && ( (R==2 && C==3) || (R==3 && C==4) || (R==3 && C==3) ) ) sol=1;
        if(X==4 && ( (R==3 && C==4) || (R==4 && C==4) ) ) sol=1;

        if(sol) printf("Case #%d: GABRIEL\n",it);
        else printf("Case #%d: RICHARD\n",it);
    }

    return 0;
}
