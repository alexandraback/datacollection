#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <set>
#include <cmath>
#include <sstream>

using namespace std;

int main()
{
char c[5][5];
int row[5];
int col[5];
int ld,rd,i,j,x,y;
bool xwon,owon;
int count;
int test;
cin>>test;
for(int t=1;t<=test;t++)
{
    for(i=0;i<4;i++)
    {
        row[i]=col[i]=0;
    }
    ld=rd=0;
    xwon=false;
    owon=false;
    count=16;
    x=y=-1;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cin>>c[i][j];
            if(c[i][j]=='.')count--;
            if(c[i][j]=='T'){x=i;y=j;}
            if(c[i][j]=='X')
            {
                row[i]++;
                col[j]++;
                if(i==j)ld++;
                if(i+j==3)rd++;
            }
            if(c[i][j]=='O')
            {
                row[i]--;
                col[j]--;
                if(i==j)ld--;
                if(i+j==3)rd--;
            }
        }
    }
    if(x!=-1)
    {
        row[x]++;
        col[y]++;
        if(x==y)ld++;
        if(x+y==3)rd++;
    }
        for(i=0;i<4;i++)
        {
            if(row[i]==4 || col[i]==4)
            {
                xwon=true;
            }
        }
        if(ld==4||rd==4)xwon=true;
        if(x!=-1)
        {
        row[x]-=2;
        col[y]-=2;
        if(x==y)ld-=2;
        if(x+y==3)rd-=2;
        }
        for(i=0;i<4;i++)
        {
            if(row[i]==-4 || col[i]==-4)
            {
                owon=true;
            }
        }
        if(ld==-4 || rd==-4)owon=true;
        printf("Case #%d: ",t);
        if(xwon)
        printf("X won\n");
        else if(owon)
        printf("O won\n");
        else
        {
            if(count==16)
            printf("Draw\n");
            else
            printf("Game has not completed\n");
        }
}
return 0;
}
