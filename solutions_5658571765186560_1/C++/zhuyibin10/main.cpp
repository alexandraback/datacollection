#include <cstdio>

using namespace std;

int main()
{
    int T,t;
    freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        int ans=1;
        int x,r,c,ma,mi;
        scanf("%d%d%d",&x,&r,&c);
        if(r>c)
        {
            ma=r;
            mi=c;
        }
        else
        {
            ma=c;
            mi=r;
        }
        if(x>=7) ans=0;
        else if(x>ma) ans=0;
        else if((x+1)/2>mi) ans=0;
        else if(r*c%x!=0) ans=0;
        else if(x==4&&mi==2) ans=0;
        else if(x==5&&r*c==15) ans=0;
        else if(x==6&&mi==3) ans=0;
        if(ans==0) printf("Case #%d: RICHARD\n",t);
        else printf("Case #%d: GABRIEL\n",t);
    }
    return 0;
}
