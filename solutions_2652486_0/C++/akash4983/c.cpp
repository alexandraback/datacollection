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

int main() {
   int t,r,n,m,K;
   S(t);S(r);S(n);S(m);S(K);
   printf("Case #1:\n");
   while(r--) {
      int A[10],flag = 0;
      rep(i,0,K) S(A[i]);
      rep(i,2,6) {
         rep(j,2,6) {
            rep(k,2,6) {
               vector<int > p;
               p.clear();
               p.push_back(1);
               p.push_back(i*j*k);
               p.push_back(i*j);
               p.push_back(j*k);
               p.push_back(i*k);
               p.push_back(i);
               p.push_back(j);
               p.push_back(k);
               int cnt = 0;
               rep(l,0,K) {
                  int f1 = 0;
                  rep(m,0,8) if(p[m] == A[l]) f1 = 1;
                  cnt += f1;
               }
               if(cnt == K && !flag) {
                  printf("%d%d%d\n",i,j,k);
                  flag = 1;
               }
            }
         }
      }
      if(!flag) printf("222\n");
   }
   return 0;
}
