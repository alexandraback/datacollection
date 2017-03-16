#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>

#define file_name ""

typedef long long ll;

const int N = 1e5+5;

using namespace std;

char s[11][11];
int win(char x)
{
    int k=0;
    for(int i=0;i<4;++i)
    {
        k=0;
        for(int j=0;j<4;++j)
            if(s[i][j]==x) k++;
        if (k==4) return 1;
    }
    for(int i=0;i<4;++i)
    {
        k=0;
        for(int j=0;j<4;++j)
            if(s[j][i]==x) k++;
        if (k==4) return 1;
    }
    k=0;
    for(int i=0;i<4;++i)
        if (s[i][i]==x) k++;
    if (k==4) return 1;
    k=0;
    for(int i=0;i<4;++i)
        if (s[i][3-i]==x) k++;
    if (k==4) return 1;

    return 0;
}

inline void print(int t, int x)
{
    printf("Case #%d: ",t);
    if (x==0) printf("X won\n");
    if (x==1) printf("O won\n");
    if (x==2) printf("Draw\n");
    if (x==3) printf("Game has not completed\n");
}
int main()
{
    // freopen(file_name".in","r",stdin);
    // freopen(file_name".out","w",stdout);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    int x,y,fl;
    for(int test=1;test<=n;++test)
    {
        x=y=-1;
        fl=0;
        for(int i=0;i<4;++i)
        {
            scanf("%s",&s[i]);
            for(int j=0;j<4;++j)
                if (s[i][j]=='T') {x=i; y=j;}
                else if(s[i][j]=='.') fl=1;
        }

        if (x!=-1) s[x][y]='X';
        if (win('X')) {print(test,0); continue;}
        if (x!=-1) s[x][y]='O';
        if (win('O')) {print(test,1); continue;}
        if (fl) {print(test,3); continue;}
        print(test,2);
    }
    return 0;
}
