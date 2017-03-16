#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std; 

int T;

char a[10][10];


bool zmagal(char c){
     for (int i=0;i<4;i++){
         bool b=true;
         for (int j=0;j<4;j++){
             if (a[i][j]==c||a[i][j]=='T') continue;
             b=false;
             break;
             }
         if (b) return true;
         }
     for (int j=0;j<4;j++){
         bool b=true;
         for (int i=0;i<4;i++){
             if (a[i][j]==c||a[i][j]=='T') continue;
             b=false;
             break;
             }
         if (b) return true;
         }    
     bool b=true;    
     for (int i=0;i<4;i++){
         if (a[i][i]==c||a[i][i]=='T') continue;
             b=false;
             break;
         }
     if (b) return true;
     b=true;    
     for (int i=0;i<4;i++){
         if (a[i][3-i]==c||a[i][3-i]=='T') continue;
             b=false;
             break;
         }
     if (b) return true;        
     return false;
     }

string solve(){
       bool empty=false;
       for (int i=0;i<4;i++) scanf("%s",a[i]);
       for (int i=0;i<4;i++)
       for (int j=0;j<4;j++) if (a[i][j]=='.') empty=true;
       if (zmagal('X')) return "X won";
       if (zmagal('O')) return "O won";
       if (empty) return "Game has not completed"; else return "Draw";
       }

int main(){
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        printf("Case #%d: %s\n",i+1,solve().c_str());
        }
    return 0;
    }
