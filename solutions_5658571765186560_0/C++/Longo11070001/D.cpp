#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool fuck[5][5][5];

int main()
{
    freopen("D-small-attempt1.in","r",stdin);
    freopen("D-small-attempt1.out","w",stdout);
    int i,j,k;
    for(j=1; j<=4; j++)
    {
        for(k=1; k<=4; k++) fuck[1][j][k] = true;
    }
    for(j=1; j<=4; j++)
    {
        for(k=1; k<=4; k++) fuck[2][j][k] = ((j*k)&1)?false:true;
    }
    for(j=1; j<=4; j++)
    {
        for(k=1; k<=4; k++)
        {
            if(j<3 && k<3) fuck[3][j][k] = false;
            else if(j*k%3 != 0) fuck[3][j][k] = false;
            else if(j==1 || k==1) fuck[3][j][k] = false;
            else fuck[3][j][k] = true;
        }
    }
    for(j=1; j<=4; j++)
    {
        for(k=1; k<=4; k++)
        {
            if(j<4 && k<4) fuck[4][j][k] = false;
            else if(j*k%4 != 0) fuck[4][j][k] = false;
            else if(j<=2 || k <= 2) fuck[4][j][k] = false;
            else fuck[4][j][k] = true;
        }
    }
    int T,cas,x,r,c;
    scanf("%d",&T);
    for(cas=1; cas<=T; cas++)
    {
        scanf("%d%d%d",&x,&r,&c);
        printf("Case #%d: %s\n",cas,fuck[x][r][c]?"GABRIEL":"RICHARD");
    }
    return 0;
}
