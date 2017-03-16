/*
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;

char tb[8][8];

int solve(int cc){
    for(int i=0;i<4;i++)
        scanf("%s",tb[i]);

    int t_x=-1,t_y=-1;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(tb[i][j]=='T')
            {
                t_y=i;
                t_x=j;
            }

    bool isXWon=false;
    bool isOWon=false;
    bool isEnd=true;

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(tb[i][j]=='.')
                isEnd=false;

    if(t_y!=-1&&t_x!=-1)
        tb[t_y][t_x]='X';
    for(int i=0;i<4;i++)
    {
        bool ch=true;
        for(int j=0;j<4;j++)
            if(tb[i][j]!=tb[i][0])
                ch=false;
        if(ch&&tb[i][0]=='X')
            isXWon=true;
    }
    for(int j=0;j<4;j++)
    {
        bool ch=true;
        for(int i=0;i<4;i++)
            if(tb[i][j]!=tb[0][j])
                ch=false;
        if(ch&&tb[0][j]=='X')
            isXWon=true;
    }
    {
        bool ch=true;
        for(int i=0;i<4;i++)
            if(tb[i][i]!=tb[0][0])
                ch=false;
        if(ch&&tb[0][0]=='X')
            isXWon=true;
    }
    {
        bool ch=true;
        for(int i=0,j=3;i<4;i++,j--)
            if(tb[i][j]!=tb[0][3])
                ch=false;
        if(ch&&tb[0][3]=='X')
            isXWon=true;
    }

    if(t_y!=-1&&t_x!=-1)
        tb[t_y][t_x]='O';
    for(int i=0;i<4;i++)
    {
        bool ch=true;
        for(int j=0;j<4;j++)
            if(tb[i][j]!=tb[i][0])
                ch=false;
        if(ch&&tb[i][0]=='O')
            isOWon=true;
    }
    for(int j=0;j<4;j++)
    {
        bool ch=true;
        for(int i=0;i<4;i++)
            if(tb[i][j]!=tb[0][j])
                ch=false;
        if(ch&&tb[0][j]=='O')
            isOWon=true;
    }
    {
        bool ch=true;
        for(int i=0;i<4;i++)
            if(tb[i][i]!=tb[0][0])
                ch=false;
        if(ch&&tb[0][0]=='O')
            isOWon=true;
    }
    {
        bool ch=true;
        for(int i=0,j=3;i<4;i++,j--)
            if(tb[i][j]!=tb[0][3])
                ch=false;
        if(ch&&tb[0][3]=='O')
            isOWon=true;
    }

    printf("Case #%d: ",cc);
    if(isXWon) printf("X won\n");
    else if(isOWon) printf("O won\n");
    else if(!isEnd) printf("Game has not completed\n");
    else printf("Draw\n");

    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int cc;
    scanf("%d",&cc);
    for(int i=1;i<=cc;i++)
        solve(i);

	return 0;
}
