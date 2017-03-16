#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int casT;
    int X,R,C;
    scanf("%d",&casT);
    for(int cas=1;cas<=casT;cas++)
    {
        bool fstWin = true;
        scanf("%d%d%d",&X,&R,&C);
        if(X<=2)
        {
            if(R*C%X==0) fstWin=false;
        }
        else if(X==3)
        {
            if(min(R,C)>=2 && max(R,C)>=3 && R*C%X==0) fstWin=false;
        }
        else if(X==4)
        {
            if(min(R,C)>=3 && max(R,C)>=4 && R*C%X==0) fstWin=false;
        }
        else if(X==5)
        {
            if(min(R,C)>=4 && R*C%X==0) fstWin=false;
            if(min(R,C)==3 && R*C%X==0 && max(R,C)>=10) fstWin=false;
        }
        else if(X==6)
        {
            if(min(R,C)>=4 && R*C%X==0) fstWin=false;
        }
        printf("Case #%d: %s\n",cas,fstWin?"RICHARD":"GABRIEL");
    }

    return 0;
}
