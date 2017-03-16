# include <cstring>
# include <cstdio>
# include <cstdlib>
# include <iostream>
using namespace std;
char s [10] [10];

int pd (char x)
{
    int t1 ,t2;
    for (int i=0;i<4;i++)
    {
        t1 = 0 ,t2 = 0;
        for (int j=0;j<4;j++)
            if (s[i][j]==x)
               t1++;
            else if (s[i][j]=='T') t2++;
        if (t1==4 || (t1==3 && t2==1))  return 1;
    }
    for (int j=0;j<4;j++)
    {
        t1 = 0 ,t2 = 0;
        for (int i=0;i<4;i++)
            if (s[i][j]==x)
               t1++;
            else if (s[i][j]=='T') t2++;
        if (t1==4 || (t1==3 && t2==1))  return 1;
    }
    t1 = t2 = 0;
    if (s[0][0]==x) t1++; else if (s[0][0]=='T') t2++;
    if (s[1][1]==x) t1++; else if (s[1][1]=='T') t2++;
    if (s[2][2]==x) t1++; else if (s[2][2]=='T') t2++;
    if (s[3][3]==x) t1++; else if (s[3][3]=='T') t2++;
    if (t1==4 || (t1==3 && t2==1))  return 1;

    t1 = t2 = 0;
    if (s[0][3]==x) t1++; else if (s[0][3]=='T') t2++;
    if (s[1][2]==x) t1++; else if (s[1][2]=='T') t2++;
    if (s[2][1]==x) t1++; else if (s[2][1]=='T') t2++;
    if (s[3][0]==x) t1++; else if (s[3][0]=='T') t2++;
    if (t1==4 || (t1==3 && t2==1))  return 1;
    return 0;
}
int main (void)
{
    int t,ys = 0;
    freopen("a.txt","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&t);
    while (t--){
         int tot = 0;
         for (int i = 0; i<4 ;i ++){
             scanf("%s",s[i]);
             for (int j=0;j<4;j++)
                 if (s[i][j]=='X' || s[i][j]=='O' || s[i][j]=='T')
                    tot++;
         }
         printf("Case #%d: ",++ys);
         if (pd('X')==1)
         {
            printf("X won\n");
            continue;               
         }
         if (pd('O')==1)
         {
            printf("O won\n");
            continue;               
         }
         if (tot==16) printf("Draw\n");
         else printf("Game has not completed\n");
    }
    return 0;   
}
