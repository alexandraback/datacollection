#include <algorithm>
#include <cstdio>
using namespace std;
int i,j,T,R,C,W;
int main()
{
    freopen("ProblemA.in","r",stdin);

    freopen("ProblemA.out","w",stdout);

    scanf("%d",&T);

    for(i=1;i<=T;i++)
    {
        scanf("%d %d %d",&R,&C,&W);

        int H=0;

        int Z=C;

        while(Z>W*2-1)
        {
            H+=1;

            Z-=W;
        }

        H+=min(W+1,Z);

        printf("Case #%d: %d\n",i,H+(R-1)*(C/W));
    }

    return 0;
}
