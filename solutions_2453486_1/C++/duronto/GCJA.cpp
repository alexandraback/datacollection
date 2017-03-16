#include<stdio.h>

int main()
{
    int T,c=0,i,j,k,X,O,D;
    char inp[5][5],Xs[5][5],Os[5][5];

    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    scanf("%d",&T);
    getchar();

    while(c++<T)
    {
        for(i=0;i<4;i++)
            gets(inp[i]);
        D=0;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(inp[i][j]=='T'){ Xs[i][j]='X'; Os[i][j]='O'; }
                else Xs[i][j]=Os[i][j]=inp[i][j];
                if(inp[i][j]=='.') D=1;
            }
        }

        X=O=0;
        for(i=0;i<4;i++)
        {
            if(Xs[i][0]=='X' && Xs[i][1]=='X' && Xs[i][2]=='X' && Xs[i][3]=='X') X=1;
            else if( Xs[0][i]=='X' && Xs[1][i]=='X' && Xs[2][i]=='X' && Xs[3][i]=='X' ) X=1;

            if(Os[i][0]=='O' && Os[i][1]=='O' && Os[i][2]=='O' && Os[i][3]=='O') O=1;
            else if(Os[0][i]=='O' && Os[1][i]=='O' && Os[2][i]=='O' && Os[3][i]=='O') O=1;

            if(X || O) break;
        }
        if(!(X+O))
        {
            if( Xs[0][0]=='X' && Xs[1][1]=='X' && Xs[2][2]=='X' && Xs[3][3]=='X' ) X=1;
            else if( Xs[0][3]=='X' && Xs[1][2]=='X' && Xs[2][1]=='X' && Xs[3][0]=='X' ) X=1;

            if( Os[0][0]=='O' && Os[1][1]=='O' && Os[2][2]=='O' && Os[3][3]=='O' ) O=1;
            else if( Os[0][3]=='O' && Os[1][2]=='O' && Os[2][1]=='O' && Os[3][0]=='O' ) O=1;
        }
        if(X) printf("Case #%d: X won\n",c);
        else if(O) printf("Case #%d: O won\n",c);
        else if(D) printf("Case #%d: Game has not completed\n",c);
        else printf("Case #%d: Draw\n",c);

        getchar();
    }

    return 0;
}
