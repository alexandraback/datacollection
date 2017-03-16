#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int a[5][5][5];
int main(void)
{
    int tcase,tt;
    tt=0;
    
    for (int i=1;i<=4;i++)
        for (int j=1;j<=4;j++)
            for (int k=1;k<=4;k++)
                a[i][j][k]=false;
    
    a[1][1][1]=true;
    
    a[2][1][1]=true;
    a[2][1][2]=true;
    
    a[3][1][1]=true;
    
    a[4][1][1]=true;
    a[4][1][2]=true;
    
    a[2][2][1]=true;
    a[2][2][2]=true;
    
    a[3][2][1]=true;
    a[3][2][2]=true;
    a[3][2][3]=true;
    
    a[3][3][1]=true;
    a[3][3][3]=true;
    
    a[4][2][1]=true;
    a[4][2][2]=true;
    
    a[4][3][1]=true;
    a[4][3][2]=true;
    a[4][3][3]=true;
    a[4][3][4]=true;
    
    a[4][4][1]=true;
    a[4][4][2]=true;
    a[4][4][4]=true;
    
    freopen("D-small-attempt1.in","r",stdin);
    freopen("D-small-attempt1.out","w",stdout);
    cin>>tcase;
    while (tcase--)
    {
        tt++;
        int x,r,c;
        cin>>x>>r>>c;
        
        if (c>r)
        {
            int tmp=c;
            c=r;
            r=tmp;
        }
        
        
        if (a[r][c][x])
            printf("Case #%d: GABRIEL\n",tt);
        else
            printf("Case #%d: RICHARD\n",tt);
    }
    return 0;
}