#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
 
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
#define lint long long int 

#define pb push_back
#define mp make_pair
#define st first
#define nd second

#define DEBUG 0
#define max_n 505
#define PLI pair<lint,lint>

int n;
map<lint,lint> mapa;
lint t[max_n];
PII results[max_n];

lint s[max_n];

int con1 = 1000000;

int main(){
    int z; scanf("%d",&z);
    FOR(Z,1,z+1){
        int res1,res2;
        scanf("%d",&n);
        FOR(i,0,n) scanf("%lld",&t[i]);

        FOR(blok,0,25){
          mapa.clear();
          FOR(i,0,1<<20){
            int k = i; lint sum =0;
            FOR(j,0,20){
                if(k%2==0) sum+=(t[j+blok*20]%con1); 
                k=k/2;
            }
            if(mapa.find(sum)!=mapa.end()){
                res1 = mapa[sum];
                res2 = i;
                break;
            }
            else mapa[sum]=i;
        }
        results[blok] = mp(res1,res2);
        lint sum=0;
        FOR(i,0,20){
            if(res1%2==0) sum +=(t[i+blok*20]/con1);
            if(res2%2==0) sum -=(t[i+blok*20]/con1);
            res1=res1/2; res2=res2/2;
        }
        s[blok]=sum;
      }
      mapa.clear();
      int r1,r2;
      FOR(i,0,1<<25){
          int k = i; lint sum = 0;
          FOR(j,0,25){
              if(k%2==0) sum+=s[j];
              k=k/2;
          }
          if(mapa.find(sum)!=mapa.end()){
              r1 = mapa[sum];
              r2 = i;
              break;
          }
          else mapa[sum]=i;
      }
      printf("Case #%d:\n",Z);
      VI lewo,prawo; lewo.clear(); prawo.clear();
      FOR(i,0,25){
          if(r1%2==0 && r2%2!=0) lewo.pb(i);
          if(r2%2==0 && r1%2!=0) prawo.pb(i);
          r1=r1/2; r2=r2/2;
      }
      VI xl,xr; xl.clear(); xr.clear();
      FOR(i,0,lewo.size()){
          res1 = results[lewo[i]].st; res2 = results[lewo[i]].nd;
          FOR(j,0,20){
              if(res1%2==0 && res2%2!=0) xl.pb(lewo[i]*20+j);
              if(res2%2==0 && res1%2!=0) xr.pb(lewo[i]*20+j);
              res1=res1/2; res2=res2/2;
          }
      }
      FOR(i,0,prawo.size()){
          res1 = results[prawo[i]].st; res2 = results[prawo[i]].nd;
          FOR(j,0,20){
              if(res1%2==0 && res2%2!=0) xr.pb(prawo[i]*20+j);
              if(res2%2==0 && res1%2!=0) xl.pb(prawo[i]*20+j);
              res1=res1/2; res2=res2/2;
          }
      }
      FOR(i,0,xr.size()) printf("%lld ",t[xr[i]]);
      printf("\n");
      FOR(i,0,xl.size()) printf("%lld ",t[xl[i]]);
      printf("\n");
      


        

    }
    return 0;
}
