#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
    int N,X,R,C;
    scanf("%d",&N);
    for(int T=1;T<=N;T++){
        scanf("%d %d %d",&X,&R,&C);
        bool result = true;
        if(X>R && X>C)
            result = false;
        if(X>=7)
            result = false;
        if(R*C%X!=0)
            result = false;
        if((X+1)/2 > min(R,C))
            result = false;
        if(X==4 && min(R,C)<=2)
            result = false;
        if(X==5 && ((R==5 && C==3) || (R==3 && C==5)))
            result = false;
        if(X==6 && min(R,C)<=3)
            result = false;
        if(result)
            printf("Case #%d: GABRIEL\n",T);
        else
            printf("Case #%d: RICHARD\n",T);
    }
    return 0;
}
