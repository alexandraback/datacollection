#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <cmath>

#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
using namespace std;

typedef long long int LL;
typedef vector<int > VI;

int v[50];
int n,ans,E;
void solve(int e,int idx,int score,int r) {
   if(idx == n) {
      ans = max(ans,score);
      return ;
   }
   for(int i = 0; i <= e; i++) {
      solve(min(e-i+r,E),idx+1,score+v[idx]*i,r);
   }
}

int main() {
   int r;
   int T,c = 0;
   S(T);
   while(T--) {
      S(E);S(r);S(n);
      rep(i,0,n) S(v[i]);
      ans = 0;
      solve(E,0,0,r);
      c++;
      printf("Case #%d: %d\n",c,ans);
   }
   return 0;
}     
