#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;
#define MAXN 1000000
int tcase;

int A,B;
double P[MAXN];
double CP[MAXN];
double SP[MAXN];
double XP[MAXN];

int main(){
   cin>>tcase;
   for(int tc=1; tc<=tcase; ++tc){
      cin>>A>>B;
      for(int i=0; i<A; ++i) cin>>P[i];
      for(int i=0; i<A; ++i) {
         CP[i] = P[i];  if(i) CP[i] *= CP[i-1];
         XP[i] = (1-P[i]); if(i) XP[i] *= CP[i-1];
      }
      SP[A] = CP[A-1];
      for(int i=A-1; i>=0; --i){
         SP[i] = XP[i];  SP[i] += SP[i+1];
      }
      double EX = 1+B+1;
      for(int i=1; i<=A; ++i){
        double TX = 0.0;
        TX += (SP[A-i])*(2*i+B-A+1); 
        TX += (1-SP[A-i])*(2*i+B-A+1+B+1);
        EX = min(TX,EX); 
      }
      EX = min(EX,CP[A-1]*(B-A+1)+(1-CP[A-1])*(B-A+1+B+1));
      cout<<"Case #"<<tc<<": ";
      printf("%.6lf\n",EX);
   }
   return 0;
}
