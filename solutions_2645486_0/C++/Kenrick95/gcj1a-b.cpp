#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: GCJ2013 Round 1A Problem B. Manage your Energy
 * URL: https://code.google.com/codejam/contest/2418487/dashboard#s=p1
 */

int T,s, E,R,N, x,y,z, ans,e;
int n,m, i,j,k, act[11000];

int tes(int idx, int energy, int Eleft) {
   if (idx>N) return 0;
   int gain = (act[idx]*energy);
   int temp = 0;
   int Ethen = min(E, Eleft+R);
   for (int i=0; i<=Ethen; i++) {
      temp = max(temp, tes(idx+1, i, Ethen-i));
   }
   return gain+temp;
}

int main() {
   cin>>T;
   for (s=1; s<=T; s++){
      cin>>E;
      cin>>R;
      cin>>N;
      for (n=1; n<=N; n++) {
         cin>>act[n];
      }
      ans = 0;
      for (e=0; e<=E; e++) {
         ans = max(ans, tes(1, e, E-e));
      }
      cout<<"Case #"<<s<<": "<<ans<<endl;
   }
   return 0;
}
