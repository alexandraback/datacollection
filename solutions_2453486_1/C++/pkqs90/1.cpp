#include <iostream>
#include <stdio.h>
using namespace std;
char c[5][5];
int t,flag,x,y;
int gogo(){
     c[x][y]='X';
     for(int i=1;i<=4;i++){
        if(c[i][1]=='X'&&c[i][2]=='X'&&c[i][3]=='X'&&c[i][4]=='X')return 1;
        if(c[1][i]=='X'&&c[2][i]=='X'&&c[3][i]=='X'&&c[4][i]=='X')return 1;
     }
     if(c[1][1]=='X'&&c[2][2]=='X'&&c[3][3]=='X'&&c[4][4]=='X')return 1;
     if(c[1][4]=='X'&&c[2][3]=='X'&&c[3][2]=='X'&&c[4][1]=='X')return 1;
     c[x][y]='O';
     for(int i=1;i<=4;i++){
        if(c[i][1]=='O'&&c[i][2]=='O'&&c[i][3]=='O'&&c[i][4]=='O')return 2;
        if(c[1][i]=='O'&&c[2][i]=='O'&&c[3][i]=='O'&&c[4][i]=='O')return 2;
     }
     if(c[1][1]=='O'&&c[2][2]=='O'&&c[3][3]=='O'&&c[4][4]=='O')return 2;
     if(c[1][4]=='O'&&c[2][3]=='O'&&c[3][2]=='O'&&c[4][1]=='O')return 2;
     if(!flag)return 3;
     return 4;
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin>>t;
    for(int CASE=1;CASE<=t;CASE++){
       flag=x=y=0;
       for(int i=1;i<=4;i++)
          for(int j=1;j<=4;j++){
             scanf(" %c",&c[i][j]);
             if(c[i][j]=='.')flag=true;
             if(c[i][j]=='T')x=i,y=j;
          }
       printf("Case #%d: ",CASE);
       int temp=gogo();
       if(temp==1)printf("X won\n");
       if(temp==2)printf("O won\n");
       if(temp==3)printf("Draw\n");
       if(temp==4)printf("Game has not completed\n");
    }
    //system("pause");
    return 0;
}
