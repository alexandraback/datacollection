#include <iostream>
#include <stdio.h>
using namespace std;
int g[5][5];
int ans[10];
int tag=0;
int getsum(int x)
{
    int i,j,k=0;
    if(x<4){
        for(i=0;i<4;i++){
            k+=g[x][i];
        }
    }else if(x<8){
        for(i=0;i<4;i++){
            k+=g[i][x%4];
        }
    }else if(x==8){
        j=0;
        for(i=0;i<4;i++){
            k+=g[i][j++];
        }
    }else{
         j=0;
        for(i=3;i>=0;i--){
            k+=g[i][j++];
        }
    }
    return k;
}
int main()
{
//    freopen("A-small-attempt0.in","r",stdin);
//    freopen("A-small-attempt0.out","w",stdout);
   int t,i,j,k,len;
   char ch[6];
   cin>>t;
   for(i=1;i<=t;i++){
    tag=0;
       for(k=0;k<4;k++){
            scanf("%s",ch);
//            cout<<ch<<endl;
            for(j=0;j<4;j++){
                if(ch[j]=='X'){
                    g[k][j]=0;
                }else if(ch[j]=='O')
                {
                    g[k][j]=2;
                }else if(ch[j]=='T'){
                    g[k][j]=1;
                }else {
                    g[k][j]=10;
                    tag=1;
                }
            }
       }
            bool x=false,o=false;
            for(j=0;j<10;j++){
             ans[j]=getsum(j);
//             cout<<ans[j]<<endl;
             if(ans[j]==0||ans[j]==1){
              //x win
              x=true;
             }else if(ans[j]==7||ans[j]==8){
              //o win
              o=true;
             }
            }
            printf("Case #%d: ",i);
            if(x){
                printf("X won\n");
            }else if(o){
                printf("O won\n");
            }else if(tag==1){
                printf("Game has not completed\n");
            }else{
                printf("Draw\n");
            }




   }
    return 0;
}
