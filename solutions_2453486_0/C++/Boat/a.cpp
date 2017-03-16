#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<list>
#include<set>

using namespace std;
char t[5][5];

int ss(){
     int stat;
     for(int i=0;i<4;i++){
          stat=1; //X
          for(int j=0;j<4;j++)
               if(t[i][j]=='.' || t[i][j]=='O') stat=0;
          if(stat==1) return 1;

          stat=1; //X
          for(int j=0;j<4;j++)
               if(t[j][i]=='.' || t[j][i]=='O') stat=0;
          if(stat==1) return 1;

          stat=2; //O
          for(int j=0;j<4;j++)
               if(t[i][j]=='.' || t[i][j]=='X') stat=0;
          if(stat==2) return 2;

          stat=2; //O
          for(int j=0;j<4;j++)
               if(t[j][i]=='.' || t[j][i]=='X') stat=0;
          if(stat==2) return 2;
     }

     stat=1; //X
     for(int i=0;i<4;i++)
          if(t[i][i]=='.' || t[i][i]=='O') stat=0;
     if(stat==1) return 1;

     stat=1; //X
     for(int i=0;i<4;i++)
          if(t[i][3-i]=='.' || t[i][3-i]=='O') stat=0;
     if(stat==1) return 1;

     stat=2; //O
     for(int i=0;i<4;i++)
          if(t[i][i]=='.' || t[i][i]=='X') stat=0;
     if(stat==2) return 2;

     stat=2; //O
     for(int i=0;i<4;i++)
          if(t[i][3-i]=='.' || t[i][3-i]=='X') stat=0;
     if(stat==2) return 2;

     for(int i=0;i<4;i++){
          for(int j=0;j<4;j++)
               if(t[i][j]=='.') return 4;
     }
     return 3;
}

int main(){
     freopen("a.txt","w",stdout);
     freopen("A-small-attempt0.in","r",stdin);
     int n;


     scanf("%d",&n);
     for(int ii=1;ii<=n;ii++){
          for(int i=0;i<4;i++){
               scanf("%s",t[i]);
          }
          int tmp=ss();
          if(tmp==1) printf("Case #%d: X won\n",ii);
          else if(tmp==2) printf("Case #%d: O won\n",ii);
          else if(tmp==3) printf("Case #%d: Draw\n",ii);
          else printf("Case #%d: Game has not completed\n",ii);
     }
     return 0;
}
