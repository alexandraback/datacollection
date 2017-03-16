#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D_output_small.txt","w",stdout);
    int T,X,R,C;
    bool b[5][5][5];
    memset(b,0,sizeof(b));
    b[2][1][1]=b[2][1][3]=b[2][3][3]=true;
    b[3][1][1]=b[3][1][2]=b[3][1][3]=b[3][1][4]=b[3][2][2]=b[3][2][4]=b[3][4][4]=true;
    b[4][1][1]=b[4][1][2]=b[4][1][3]=b[4][1][4]=true;
    b[4][2][2]=b[4][2][3]=b[4][2][4]=b[4][3][3]=true;
    scanf("%d",&T);
    for (int index=1;index<=T;index++)
    {
        scanf("%d%d%d",&X,&R,&C);
        if (R>C) swap(R,C);
        if (b[X][R][C]) printf("Case #%d: RICHARD\n",index);
        else printf("Case #%d: GABRIEL\n",index);
    }
    return 0;
}
