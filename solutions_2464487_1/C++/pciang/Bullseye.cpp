#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
#include <set>
#define DEBUG printf("TEST\n")

using namespace std;

const double PI = acos(-1);
double R, T;
int TC, itc;

double formula(long long n){
   return (double) n * (2 * n + 2 * R - 1);
}

long long ub_bins(long long l, long long r){
   if(l < r){
      int mid = (l + r) / 2 + 1;
      if(formula(mid) <= T) return ub_bins(mid, r);
      else return ub_bins(l, mid - 1);
   }
   return l;
}

int main(){
   
   //Formula : pi * n * (2 * n + 2 * R - 1) / pi
   scanf("%d", &TC);
   for(itc = 1; itc <= TC; ++itc){
      scanf("%lf %lf", &R, &T);
      printf("Case #%d: %lld\n", itc, ub_bins(0, 1000000000000LL));
   }
   
   return 0;
}
