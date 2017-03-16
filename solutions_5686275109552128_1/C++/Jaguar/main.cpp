//Javier Guzmán
//CODEJAM 2015 A
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
int t, d, pi[1000], ans, aux, maxp;

int reduceTo(int s){
   int counter=0;
   for(int i=0; i<d; i++){
      if(pi[i]>s){
         counter += (pi[i]-1)/s;
      }
   }
   return counter;
}

int main(){
   scanf("%d", &t);
   for(int q=1; q<=t; q++){
      memset(pi, 0, sizeof(pi));
      ans=1000;
      maxp=0;
      scanf("%d", &d);
      for(int i=0; i<d; i++){
         scanf("%d", &pi[i]);
         if(pi[i]>maxp) maxp=pi[i];
      }
      for(int i=1; i<=maxp; i++){
         aux = reduceTo(i);
         aux+=i;
         if(aux<ans){
            ans=aux;
         }
      }
      printf("Case #%d: %d\n", q, ans);
   }
   return 0;
}