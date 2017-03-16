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
#define MAX 1000006
#define MOD 1000000007
int N[MAX],n,k;
void Solve(){
   cin >> k >> n;
   for(int i = 0 ; i < n ; i++)
     cin >> N[i];

   sort(N,N+n);
   int b = n;
   int a = 0;
   long long s = k;
   for(int i = 0 ; i < n ; i++){
     //cout << i ;
     if(s == 1) break;
     while(s <= N[i])
        {
            s = s+s-1;
            a++;
        }
     s+=N[i];
     b = min(b,n-i-1 + a);
   }
   printf("%d\n",b);
}
int main(){
  freopen("codejam_out.txt","w",stdout);
  freopen("codejam_in.txt","r",stdin);
  int test;
  cin >> test;
  for(int t = 1 ; t <= test ; t++){
    printf("Case #%d: ",t);
    Solve();
  }
}
