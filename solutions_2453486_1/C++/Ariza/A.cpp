#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
char tab[5][5];
bool isO(){
     bool ok;
     for (int i=0;i<4;++i){
         ok=1;
         for (int j=0;j<4;++j){
             if (tab[i][j]=='X' || tab[i][j]=='.') ok=0;
         }
         if (ok) return 1;
     }
     for (int j=0;j<4;++j){
         ok=1;
         for (int i=0;i<4;++i){
             if (tab[i][j]=='X' || tab[i][j]=='.') ok=0;
         }
         if (ok) return 1;
     }
     ok=1;
     for (int i=0;i<4;++i){
         if (tab[i][i]=='X' || tab[i][i]=='.') ok=0;
     }
     if (ok) return 1;
     ok=1;
     for (int i=3;i>=0;--i){
         if (tab[i][4-(i+1)]=='X' || tab[i][4-(i+1)]=='.') ok=0;
     }
     if (ok) return 1;
     return 0;
}
bool isX(){
     bool ok;
     for (int i=0;i<4;++i){
         ok=1;
         for (int j=0;j<4;++j){
             if (tab[i][j]=='O' || tab[i][j]=='.') ok=0;
         }
         if (ok) return 1;
     }
     for (int j=0;j<4;++j){
         ok=1;
         for (int i=0;i<4;++i){
             if (tab[i][j]=='O' || tab[i][j]=='.') ok=0;
         }
         if (ok) return 1;
     }
     ok=1;
     for (int i=0;i<4;++i){
         if (tab[i][i]=='O' || tab[i][i]=='.') ok=0;
     }
     if (ok) return 1;
     ok=1;
     for (int i=3;i>=0;--i){
         if (tab[i][4-(i+1)]=='O' || tab[i][4-(i+1)]=='.') ok=0;
     }
     if (ok) return 1;
     return 0;
}
int main(){
    int ntest;
    scanf("%d",&ntest);
    bool o,x,bo;
    for (int test=1;test<=ntest;++test){
        for (int i=0;i<4;++i) scanf("%s",tab[i]);
        o=isO();
        x=isX();
        printf("Case #%d: ",test);
        if (o&&x){
           printf("Draw\n");
        } else
        if (o){
           printf("O won\n");
        } else
        if (x){
           printf("X won\n");
        } else{
          bo=1;
          for (int i=0;i<4;++i){
              for (int j=0;j<4;++j){
                  if (tab[i][j]=='.') bo=0;
              }
          }
          if (bo){
             printf("Draw\n");
          }
          else{
               printf("Game has not completed\n");
          }
        }
    }
    return 0;
}
