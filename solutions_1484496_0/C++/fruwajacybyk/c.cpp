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
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

#define DEBUG 0
#define max_n 25

int n;
map<int,int> mapa;
int t[max_n];

int main(){
    int z; scanf("%d",&z);
    FOR(Z,1,z+1){
        int res1,res2;
        mapa.clear();
        scanf("%d",&n);
        FOR(i,0,n) scanf("%d",&t[i]);
        FOR(i,0,1<<20){
            int k = i; int sum =0;
            FOR(j,0,20){
                if(k%2==0) sum+=t[j]; 
                k=k/2;
            }
            if(mapa.find(sum)!=mapa.end()){
                res1 = mapa[sum];
                res2 = i;
                break;
            }
            else mapa[sum]=i;
        }
        printf("Case #%d:\n",Z);
        FOR(j,0,20){
              if(res1%2==0) printf("%d ",t[j]);
              res1=res1/2;
        }
        printf("\n");
        FOR(j,0,20){
              if(res2%2==0) printf("%d ",t[j]);
              res2=res2/2;
        }
        printf("\n"); 
    }
    return 0;
}
