//Javier Guzmán
//CODEJAM 2015 D
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
int t, x, r, c;

int main(){
   scanf("%d", &t);
   for(int q=1; q<=t; q++){
      scanf("%d%d%d", &x, &r, &c);
      if(x>=7){
         printf("Case #%d: RICHARD\n", q);
      }
      else if((r*c)%x){
         printf("Case #%d: RICHARD\n", q);
      }
      else if(((r<=(x/2))||(c<=(x/2)))&&(x>2)){
         printf("Case #%d: RICHARD\n", q);
      }
      else if((r<x)&&(c<x)){
         printf("Case #%d: RICHARD\n", q);
      }
      else{
         printf("Case #%d: GABRIEL\n", q);
      }
   }
   return 0;
}