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
int t, smax, s[1002], counter, minf, aux;
char c;
int main(){
   cin>>t;
   for(int q = 1; q<=t; q++){
      minf=0;
      counter=0;
      memset(s, 0, sizeof(s));
      scanf("%d", &smax);
      scanf("%c", &c);
      for(int i=0; i<=smax; i++){
         scanf("%c", &c);
         s[i]=c-'0';
         aux=i-counter;
         if(aux>minf){
            minf=aux;
         }
         counter+=s[i];
      }
      printf("Case #%d: %d\n", q, minf);
   }
   return 0;
}