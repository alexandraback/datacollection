#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int t,x,y,test=1,i,j,flag1,flag2,nc;
    char str[5][5],c;
    scanf("%d",&t);
    while(t--)
    {
        flag1=0;
        flag2=0;
        nc=0;
        for(i=0;i<4;i++)
        {
            x=0;y=0;
            for(j=0;j<4;j++)
            {
                cin>>str[i][j];
                if(str[i][j]=='.')
                nc=1;
                else if(str[i][j]=='X')
                x++;
                else if(str[i][j]=='O')
                y++;
                else 
                {
                    x++;
                    y++;
                }
            }
            if(x==4)
            flag1++;
            else if(y==4)
            flag2++;
            
        }
        if(flag1==1)
        { printf("Case #%d: X won\n",test++); continue; }
        else if(flag2==1)
        { printf("Case #%d: O won\n",test++); continue; }
        
        for(i=0;i<4;i++)
        {
            x=0;y=0;
            for(j=0;j<4;j++)
            {
                if(str[j][i]=='.')
                nc=1;
                else if(str[j][i]=='X')
                x++;
                else if(str[j][i]=='O')
                y++;
                else 
                {
                    x++;
                    y++;
                }
            }
            if(x==4)
            flag1++;
            else if(y==4)
            flag2++;
            
        }
           if(flag1==1)
        { printf("Case #%d: X won\n",test++); continue; }
        else if(flag2==1)
        { printf("Case #%d: O won\n",test++); continue; }
        
        x=0;y=0;
        for(i=0;i<4;i++)
        {
            if(str[i][i]=='.')
                nc=1;
                else if(str[i][i]=='X')
                x++;
                else if(str[i][i]=='O')
                y++;
                else 
                {
                    x++;
                    y++;
                } 
        }
         if(x==4)
         { printf("Case #%d: X won\n",test++); continue; }
         if(y==4)
          { printf("Case #%d: O won\n",test++); continue; }
          
          x=0;y=0;
          for(i=0;i<4;i++)
          {
              if(str[i][3-i]=='.')
                nc=1;
                else if(str[i][3-i]=='X')
                x++;
                else if(str[i][3-i]=='O')
                y++;
                else if(str[i][3-i]=='T')
                {
                    x++;
                    y++;
                } 
          }
          if(x==4)
         { printf("Case #%d: X won\n",test++); continue; }
         if(y==4)
          { printf("Case #%d: O won\n",test++); continue; }
          if(nc==0)
          printf("Case #%d: Draw\n",test++);
          else printf("Case #%d: Game has not completed\n",test++);
           
            
        
    }
    return 0;
}
