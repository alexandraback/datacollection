//Lasha Bukhnikashvili
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string>
#define INF 1000001
#define Pi 3.14159265358
#define mod9 %1000000009
#define mod7 %1000000007
#define time clock()/(double)CLOCKS_PER_SEC
using namespace std;
 int T,i,j,y,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;
 int a[6][6];
 char ch;
 string ans;
int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
   cin>>T;
   y=1;
   while (y<=T){
         for (i=1;i<=4;i++)
             for (j=1;j<=4;j++){
                 cin>>ch;
                 if (ch=='O') a[i][j]=10;
                 if (ch=='X') a[i][j]=0;
                 if (ch=='T') a[i][j]=5;
                 if (ch=='.') a[i][j]=INF;
             };
         x1=a[1][1]+a[1][2]+a[1][3]+a[1][4];
         x2=a[2][1]+a[2][2]+a[2][3]+a[2][4];
         x3=a[3][1]+a[3][2]+a[3][3]+a[3][4];
         x4=a[4][1]+a[4][2]+a[4][3]+a[4][4];
         x5=a[1][1]+a[2][2]+a[3][3]+a[4][4];
         x6=a[1][4]+a[2][3]+a[3][2]+a[4][1];
         x7=a[1][1]+a[2][1]+a[3][1]+a[4][1];
         x8=a[1][2]+a[2][2]+a[3][2]+a[4][2];
         x9=a[1][3]+a[2][3]+a[3][3]+a[4][3];
         x10=a[1][4]+a[2][4]+a[3][4]+a[4][4];
         if (x1==40 || x1==35 || x2==40 || x2==35 || x3==40 || x3==35 || x4==40 || x4==35 || x5==40 || x5==35 || x6==40 || x6==35 || x7==40 || x7==35 || x8==40 || x8==35 || x9==40 || x9==35 || x10==40 || x10==35)
            ans="O won";
         else 
            if (x1<=5 || x2<=5 || x3<=5 || x4<=5 || x5<=5 || x6<=5 || x7<=5 || x8<=5 || x9<=5 || x10<=5)
               ans="X won";
            else
               if (x1+x2+x3+x4+x5+x6+x7+x8+x9+x10<INF)
                  ans="Draw";
               else 
                  ans="Game has not completed";
         cout<<"Case #"<<y<<": "<<ans<<endl;
         y++;
   };   
 return 0;
}
