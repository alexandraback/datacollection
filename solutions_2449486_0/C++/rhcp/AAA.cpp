#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <string>
#include <string.h>
#include <map>
#include <locale>
#include <math.h>
#include <time.h>
#include <list> 
 
#define frup(FRUP_I,FROM,TO) for(long FRUP_I=FROM;FRUP_I<=TO;FRUP_I++)
#define frdn(FRDN_I,FROM,TO) for(long FRDN_I=FROM;FRDN_I<TO;FRDN_I++)
#define foreach(it,arr) for(__typeof((arr).begin()) it = (arr).begin(); it!= (arr).end(); it++)
 
#define pub(VALUE) push_back(VALUE)
#define pob() pop_back()
#define mp(FST,SEC) make_pair(FST,SEC)
#define len(STR) STR.length()
 
#define refresh(ARRAY,TARGET,VALUE) frdn(int DEFINED_I,0,TARGET)ARRAY[DEFINED_I]=VALUE
#define watch(VALUE) {cout<<#VALUE;printf("=");cout<<VALUE;printf("\n");}
#define stop exit(0)

#define F first
#define S second

using namespace std;

typedef pair<int,int>ii;
typedef pair<long long,long long>lii;
typedef pair<char,int>ci;
typedef long long ll;

const int INF = int(1e9);
const double EPS  = 1e-8;
const long long INF64 = (long long)(1e18)+1,md = 1000000007ll;

int n,m,t,a[105][105],b[105][105];
bool fail;

bool allline(int n){
      frdn(i,0,m)if(a[n][i]!=1)return 0;
      return 1;
     }

bool allcolumn(int m){
      frdn(i,0,n)if(a[i][m]!=1)return 0;
       return 1;
     }     

int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
     scanf("%d",&t);
      frdn(cases,0,t){
                      scanf("%d %d",&n,&m);
                      fail=0;
                         frdn(i,0,n)
                           frdn(j,0,m)scanf("%d",&a[i][j]),b[i][j]=2;
                        frdn(i,0,n)if(allline(i))frdn(j,0,m)b[i][j]=1;
                        frdn(j,0,m)if(allcolumn(j))frdn(i,0,n)b[i][j]=1;
                       frdn(i,0,n)
                         frdn(j,0,m)if(a[i][j]!=b[i][j]){
                                                         fail=1;
                                                         break;
                                                         }
                       printf("Case #%d: ",cases+1); if(fail)printf("NO\n"); else printf("YES\n");                                 
                      }
 return 0;
}       
