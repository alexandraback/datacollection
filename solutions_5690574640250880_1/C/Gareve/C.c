//gcc --std=c99 C.c
#include <stdio.h>
#include <string.h>

char M[209][209];

int found;

void print_answer(int Y,int X,int ay,int ax,int flip){
   if(flip){
      for(int i=1;i<=ay;i++){
         for(int i=1;i<=Y + ax;i++)printf("*");
         printf("\n");
      }
      for(int j=0;j<X;j++){
         for(int i=0;i<Y+ax;i++){
            if(i < ax){
               printf("*");
            }else{
               printf("%c",M[i-ax][j]);
            }
         }
         printf("\n");
      }
   }else{
      for(int i=0;i<Y+ay;i++){
         for(int j=0;j<X+ax;j++){
            if(i < ay || j < ax){
               printf("*");
            }else{
               printf("%c",M[i-ay][j-ax]);
            }
         }
         printf("\n");
      }
   }
}

void fill(int mines, int flip, int Y,int X,int ay,int ax){
   memset(M,'.',sizeof(M));

   if(Y*X - mines <= 1){
      memset(M,'*',sizeof(M));

      if(Y*X - mines == 1)M[0][0] = 'c';
      print_answer(Y,X,ay,ax,flip);
      found = 1;
      return;
   }

   int i = 0,delta_mines;
   while(mines > 0){
      if(i == Y - 1){
         return;
      }else if(i == Y - 2){
         int lft = (2 * X) - mines;
         if(mines % 2 == 1 || lft == 2)return;

         delta_mines = mines / 2;
         for(int j=0;j<X;j++){
            if(j < delta_mines){
               M[i+0][j] = '*';
               M[i+1][j] = '*';
            }else{
               M[i+0][j] = '.';
               M[i+1][j] = '.';
            }
         }
         break;
      }else{
         if(mines >= X){
            delta_mines = X;
         }else{
            delta_mines = mines;
            if(mines + 1 == X)delta_mines --;
         }
      }

      for(int j=0;j<X;j++){
         if(j < delta_mines){
            M[i][j] = '*';
         }else{
            M[i][j] = '.';
         }
      }
      mines -= delta_mines;
      i++;
   }

   M[Y-1][X-1] = 'c';
   print_answer(Y,X,ay,ax,flip);
   found = 1;
}

void solve(){
   int Y,X,MINES; scanf("%d %d %d",&Y,&X,&MINES);
   found = 0;

   int lim_y = Y - 2 < 0 ? 0:Y-2;
   int lim_x = X - 2 < 0 ? 0:X-2;

   for(int y=0;y<=lim_y;y++){
      if(found == 1)return;
      for(int x=0;x<=lim_x;x++){
         int dx = X-x, dy = Y - y;
         int delta_mines = Y * X - dx * dy;

         if(MINES - delta_mines < 0)break;

         fill(MINES-delta_mines,0,dy,dx,y,x);
         if(found == 1)return;

         fill(MINES-delta_mines,1,dx,dy,y,x);
         if(found == 1)return;
      }
   }

   if(found == 0){
      printf("Impossible\n");
   }
}

int main(){
   int NC;scanf("%d",&NC);

   for(int i=1;i<=NC;i++){
      printf("Case #%d:\n",i);
      solve();
   }
}