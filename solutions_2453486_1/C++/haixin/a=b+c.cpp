#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
char map[6][6];
int ji[6][6];
int l;
int pan(char c){
    memset(ji,0,sizeof(ji));
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
            ji[i+1][j+1]=ji[i+1][j];
            if(map[i][j]==c||map[i][j]=='T')ji[i+1][j+1]++;
    }
    for(int i=1;i<=4;i++)
    if(ji[i][4]==4)return 1;
    memset(ji,0,sizeof(ji));
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
            ji[i+1][j+1]=ji[i][j+1];
            if(map[i][j]==c||map[i][j]=='T')ji[i+1][j+1]++;
    }
    for(int i=1;i<=4;i++)
    if(ji[4][i]==4)return 1;
    int d=0,t=0;
    for(int i=0;i<4;i++){
    if(map[i][i]==c||map[i][i]=='T')d++;
    if(map[i][3-i]==c||map[i][3-i]=='T')t++;
    }    
    if(d==4)return 1;
    if(t==4)return 1;
    return 0;
}
int outans(int t1,int t2){
    if(t1&&t2==1)return 1;  
    if(t1==1)return 2;  
    if(t2==1)return 3;   
    int d=0;
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    if(map[i][j]=='.')d++ ;           
    if(d==0)return 1;
    return 4;
    }
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int n;
    scanf("%d\n",&n);
    for(int t=1;t<=n;t++){
            for(int i=0;i<=3;i++)
            gets(map[i]);
            scanf("\n");
          //  for(int i=1;i<=4;i++)
          //  printf("%s\n",map[i-1]);
            
            int t1=pan('X'),t2=pan('O');
            int d=outans(t1,t2);
            printf("Case #%d: ",t);
            if(d==1)printf("Draw\n");
            if(d==2)printf("X won\n");
            if(d==3)printf("O won\n");
            if(d==4)printf("Game has not completed\n");
            }
    }
