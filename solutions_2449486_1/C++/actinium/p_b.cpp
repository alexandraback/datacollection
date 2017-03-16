#include <cstdio>

int main(){
  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;++t){
    bool possible = true;

    int x,y;
    scanf("%d %d",&x,&y);
    int board[x][y];
    int x_max[x];
    int y_max[y];
    for(int i=0;i<x;++i){
      x_max[i]=0;
    }
    for(int j=0;j<y;++j){
      y_max[j]=0;
    }

    for(int i=0;i<x;++i){
      for(int j=0;j<y;++j){
        int tmp;
        scanf("%d",&tmp);
        board[i][j] = tmp;
        if(x_max[i]<tmp) x_max[i]=tmp;
        if(y_max[j]<tmp) y_max[j]=tmp;
      } 
    }
    for(int i=0;i<x;++i){
      for(int j=0;j<y;++j){
        if(board[i][j]<x_max[i] && board[i][j]<y_max[j]) possible=false;
      }
    }
    printf("Case #%d: ",t);
    if(possible){
      printf("YES");
    }else{
      printf("NO");
    }
    printf("\n");
  }
}
