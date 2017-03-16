#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
 
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define PI 3.14159265359
#define eps 0.0000001
#define mINF -2000000000

#define LL long long


LL a,b,w,x,c;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

double check(double c, double f, double x, int n){
   double tempTime=0.0;
   double divider=2.0;
   for(int i=0;i<n;i++){
      tempTime+=c/divider;
      divider+=f;
   }
   tempTime+=x/divider;
   return tempTime;
}

int main(){
   int TC;
   scanf("%d",&TC);
   for(int T=1;T<=TC;T++){
      double C,F,X;
      scanf("%lf %lf %lf",&C,&F,&X);
      int awal = 0, akhir = 100000, tengah;
      double kiri,kanan,mid;
      while(awal<=akhir){
         tengah=ceil((awal+akhir)/2.0);
         mid=check(C,F,X,tengah);
         kiri=check(C,F,X,tengah-1);
         kanan=check(C,F,X,tengah+1);
         if(kiri>mid && kanan>mid)
            break;
         else if(kanan<mid)
            awal=tengah+1;
         else
            akhir=tengah-1;  
      }
      printf("Case #%d: %.7lf\n",T,check(C,F,X,tengah));
   }
   return 0;
}