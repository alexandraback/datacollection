#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <bitset>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <utility>
#include <ctime>
#include <limits.h>
using namespace std;

#define REP(i,n) for(int i=0; i<n;++i)
#define BIT(x) __builtin_popcount(x)
#define DEB(x) cout << #x << " = " << x << endl
#define pb push_back
#define oo (1LL)<<60
//constant
#define MAX 100005
#define MOD 1000000007
long long L[100005];
double M[33][33];
void Load(){
  for(long long i = 1 ; i < MAX ; i++)
    L[i] = L[i-1] + 2*i-1 + 2*i-2;
  M[0][0] = 1.0;
  for(int i = 0 ; i < 23 ; i++)
    for(int j = 0 ; j < 23 ; j++)
  {
     int l = (i+j+1);

     if(i) M[i][j] += M[i-1][j]/2;
     if(j) M[i][j] += M[i][j-1]/2;
  }
}
double Prob(double a , double t , double x , double y){
   if(a == 0) return 1;
   if(t == 0) return 0;
   double s = 0;
   if(x)
     s+=Prob(a-1,t-1,x-1,y);
   if(y)
     s+=Prob(a,t-1,x,y-1);
   if(x>0 && y>0)s/=2;
   return s;
}
double Solve(){
   int n , x , y;
   scanf("%d%d%d",&n,&x,&y);
   if(x < 0) x = -x;
   int l = (x+y)/2 + 1;
   if(L[l] <= n) return 1.0;
   if(L[l-1] >= n) return 0.0;
   int h = y + 1;
   if(h == 2*l-1) return 0.0;

   int m = n-L[l-1];
   double a = 0;

   //printf("%d %d %d ",h,m,2*l-1);
   for(int  i = h ; i <= m ; i++)
     a+=M[i][m-i];
   return Prob(h,m,2*l-2,2*l-2);
}
int main(){
  Load();
  freopen("codejam_out.txt","w",stdout);
  freopen("codejam_in.txt","r",stdin);
  int test;
  cin >> test;
  for(int t = 1 ; t <= test ; t++){
    printf("Case #%d: ",t);
    printf("%lf\n",Solve());
  }
}
