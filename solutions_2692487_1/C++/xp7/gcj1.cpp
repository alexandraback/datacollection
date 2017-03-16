/* Paras Narang */
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <deque>
#include <bitset>
#include <cmath>
#include <set>
#include <sstream>

using namespace std;

#define oo 0x7F7F7F7F
#define LET(x,a)     __typeof(a) x(a)
#define EACH(it,v)   for(LET(it,v.begin());it!=v.end();++it)
#define REP(i,n)     for(__typeof(n) i(0); i<n; i++)
#define ALL(x)       (x).begin(), (x).end()
#define gint(t)      scanf("%d", &t);
#define pint(t)      printf("%d\n", t);
#define pb           push_back
#define mp           make_pair

typedef long long int   ll;
typedef unsigned long long int ull;
typedef unsigned int    uint;
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<vi>      vii;
typedef vector<pii>     vpii;

int main(){
    int t; gint(t);
    REP(ti, t){
        ll A, N; scanf("%lld %lld",&A, &N);
        ll M[N]; REP(ni, N) scanf("%lld",&M[ni]);
        sort(M, M+N);
        ll op = 0, opquit = 0, res = oo, flag=0;
        REP(ni, N){
            if(M[ni] < A) A+=M[ni];
            else{
              if(A+A-1 > M[ni]){ A=A+A-1+M[ni]; op++;}
              else{
                  opquit = op+N-ni;
                  while(A<=M[ni]){
                      A = A+A-1;
                      op++;
                      if(op>=opquit){
                         flag=1; break;
                      }
                  }
                  if(opquit<res) res = opquit; 
                  if(flag==1){ 
                    break;
                  }
                  A+=M[ni];
              }
            }
        }
        if(flag == 0){
          if(op<res) res = op;
        }
        printf("Case #%d: %lld\n",ti+1, res);

    }
    return 0;
}
