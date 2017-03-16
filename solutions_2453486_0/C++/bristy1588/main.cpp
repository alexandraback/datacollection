#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char cc;
char s[5][5];
inline bool check_()
{
    int i,j,now;
    bool flag;

   now = 0; flag = false;
   //row
    for(i = 0; i<4; i++)
    {
        now = 0;
        for(j = 0; j < 4; j++)
        {
            if(s[i][j]=='T' || s[i][j]==cc)
                now++;
        }
        if(now==4) flag = true;
    }
    for(i = 0; i<4; i++)
    {
        now = 0;
        for(j = 0; j < 4; j++)
        {
            if(s[j][i]=='T' || s[j][i]==cc)
                now++;
        }
        if(now==4) flag = true;
    }

    now = 0;
    for(i = 0; i < 4; i++){
        if(s[i][i]=='T' || s[i][i]==cc)
                now++;
    }
    if(now==4) flag = true;

    now = 0;
    for(i = 0; i < 4; i++){
         if(s[i][3-i]=='T' || s[i][3-i]==cc)
                now++;
    }
    if(now==4) flag = true;

    return flag;
}

inline bool all()
{
    int i,j;
    bool flag = true;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(s[i][j]=='.')
                flag = false;
        }
    }
    return flag;
}
int main()
{
    int i,t,tc;
    bool a1,a2,a3;

    freopen("A-small-attempt0.in","r",stdin);
    freopen("b.out","w",stdout);

    scanf("%d",&t);
    tc=  0;
    while(tc<t){
        tc++;
        for(i = 0; i < 4; i++)
            scanf("%s",s[i]);


        printf("Case #%d: ",tc);
        cc ='X';
        a1 = check_();
        if(a1)
        {
            printf("X won\n");
            continue;
        }
        cc ='O';
         a2 = check_();
         if(a2)
         {
             printf("O won\n");
             continue;
         }
         a3 = all();

         if(a3)
            printf("Draw\n");
         else
            printf("Game has not completed\n");
    }
    return 0;
}
