//Javier Guzmán
//CODEJAM 2015 C
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <string.h>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
int t, x, l, ans;
string s;
int mult(int a, int b){
   if(b==2){//i
      switch(a){
      case 1://1
         return 2;
         break;
      case 2://i
         return 5;
         break;
      case 3://j
         return 8;
         break;
      case 4://k
         return 3;
         break;
      case 5://-1
         return 6;
         break;
      case 6://-i
         return 1;
         break;
      case 7://-j
         return 4;
         break;
      case 8://-k
         return 7;
         break;
      }
   }
   if(b==3){//j
      switch(a){
      case 1://1
         return 3;
         break;
      case 2://i
         return 4;
         break;
      case 3://j
         return 5;
         break;
      case 4://k
         return 6;
         break;
      case 5://-1
         return 7;
         break;
      case 6://-i
         return 8;
         break;
      case 7://-j
         return 1;
         break;
      case 8://-k
         return 2;
         break;
      }
   }
   if(b==4){//k
      switch(a){
      case 1://1
         return 4;
         break;
      case 2://i
         return 7;
         break;
      case 3://j
         return 2;
         break;
      case 4://k
         return 5;
         break;
      case 5://-1
         return 8;
         break;
      case 6://-i
         return 3;
         break;
      case 7://-j
         return 6;
         break;
      case 8://-k
         return 1;
         break;
      }
   }
}

int main(){
   int tmpi, tmpj, aux, curr;
   scanf("%d", &t);
   for(int q=1; q<=t; q++){
      ans=0;
      scanf("%d%d", &l, &x);
      cin>>s;
      curr=1;
      for(int i=0; i<x; i++){
         for(int j=0; j<l; j++){
            if(s[((i*l)+j)%l]== 'i'){
               aux=2;
            }
            if(s[((i*l)+j)%l]== 'j'){
               aux=3;
            }
            if(s[((i*l)+j)%l]== 'k'){
               aux=4;
            }
            curr=mult(curr, aux);
            if(curr==2){
               tmpi=i;
               tmpj=j+1;
               i=x;
               break;
            }
         }
         if(i==(x-1)){
            tmpi=x;
         }
      }
      curr=1;
      for(int i=tmpi; i<x; i++){
         for(int j=(i==tmpi)?tmpj:0; j<l; j++){
            if(s[((i*l)+j)%l]== 'i'){
               aux=2;
            }
            if(s[((i*l)+j)%l]== 'j'){
               aux=3;
            }
            if(s[((i*l)+j)%l]== 'k'){
               aux=4;
            }
            curr=mult(curr, aux);
            if(curr==3){
               tmpi=i;
               tmpj=j+1;
               i=x;
               break;
            }
         }
         if(i==(x-1)){
            tmpi=x;
         }
      }
      curr=1;
      for(int i=tmpi; i<x; i++){
         for(int j=(i==tmpi)?tmpj:0; j<l; j++){
            if(s[((i*l)+j)%l]== 'i'){
               aux=2;
            }
            if(s[((i*l)+j)%l]== 'j'){
               aux=3;
            }
            if(s[((i*l)+j)%l]== 'k'){
               aux=4;
            }
            curr=mult(curr, aux);
         }
      }
      if(curr!=4)
         printf("Case #%d: NO\n", q);
      else
         printf("Case #%d: YES\n", q);
   }
   return 0;
}