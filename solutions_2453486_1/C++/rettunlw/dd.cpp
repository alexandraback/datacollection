#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int t;
char a[10][10];

void rund(){
  int i,j,k,l;
  for (i=0;i<4;i++){
      k=l=0;
      for (j=0;j<4;j++){
          if (a[i][j]=='X'||a[i][j]=='T') k++;
          if (a[i][j]=='O'||a[i][j]=='T') l++; 
          if (k==4){
             printf("X won\n"); 
             return;         
          }
          if (l==4){
             printf("O won\n");
             return;       
          }   
      }
      k=l=0;
      for (j=0;j<4;j++){
          if (a[j][i]=='X'||a[j][i]=='T') k++;
          if (a[j][i]=='O'||a[j][i]=='T') l++; 
          if (k==4){
             printf("X won\n");      
             return;    
          }
          if (l==4){
             printf("O won\n");      
             return; 
          }   
      }        
  } 
  k=l=0;
  for (i=0;i<4;i++){
      if (a[i][i]=='X'||a[i][i]=='T') k++;
      if (a[i][i]=='O'||a[i][i]=='T') l++; 
          if (k==4){
             printf("X won\n");      
             return;    
          }
          if (l==4){
             printf("O won\n");      
             return; 
          }   
      }        
  
  k=l=0;
  for (i=0;i<4;i++){
      if (a[3-i][i]=='X'||a[3-i][i]=='T') k++;
      if (a[3-i][i]=='O'||a[3-i][i]=='T') l++; 
          if (k==4){
             printf("X won\n");      
             return;    
          }
          if (l==4){
             printf("O won\n");      
             return; 
          }   
      }        
  
  for (i=0;i<4;i++)
      for (j=0;j<4;j++)
          if (a[i][j]=='.'){
             printf("Game has not completed\n");
             return;                            
          }
  printf("Draw\n");   
}


int main(){
    freopen("Al.in","r",stdin);
    freopen("Al.out","w",stdout);
    scanf("%d",&t);
    for (int r=1;r<=t;r++){
        for (int i=0;i<4;i++)
            scanf("%s",a[i]);
        printf("Case #%d: ",r);
        rund();
    }
    return 0;   
}
