#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<set>
#include<iomanip>
#include<complex>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<bitset>
#include<memory.h>
#include<cassert>
#include<ctime>
 
 
#pragma comment(linker, "/stack:30000000")
 
using namespace std;
 
#define For(i,l,r) for (int i = l ;i < (int)(r + 1) ; ++ i )
#define ForI(it , s , T) for (T :: iterator it = s.begin(); it != s.end() ; ++ it )
#define LL long long
#define iinf 2000000000
#define linf 4000000000000000000LL
#define MOD  1000000007
#define Pi 3.1415926535897932384
#define bit(mask,i) ((mask>>i)&1)
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define sqr(x) ((x)*(x))
#define pause cin.get();cin.get();
#define fir first
#define sec second
#define ln(x) log(x)
 
const int Direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
const int Nmax = 200100;

int n,m,k;
int main()
{ 
   freopen("C-large.in","r",stdin);
   freopen("output1.txt","w",stdout);
   int test;
   cin >> test;
   for (int tt = 1 ; tt <= test ; tt ++ ){
   scanf("%d%d%d",&n,&m,&k);
   int answer = k;
   for (answer = 1 ;  answer <= k ; answer ++){
       int inside = k - answer;
       int minPossible = iinf;
       if (inside == 0) minPossible = 0;
       for (int side = 1 ; side <= min(inside,n-2) ; side ++){
           int q = inside/side;
           int rest = inside - q*side;
           if (q + ((rest>0)?1:0) > m - 2) continue;
           int new_ans = 2*side + 2*q + ((rest>0)?1:0);
           minPossible = min(minPossible , new_ans);
       }
       if (minPossible <= answer) break;
   }
   printf("Case #%d: %d\n",tt,answer);
   }
   return 0;
} 
