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

int n,m,c[105],l=0,ans,t,g=0;
long long a,have;

int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
     scanf("%d",&t);
      frdn(cases,0,t){
                      cin>>a;
                       scanf("%d",&n);
                        frdn(i,0,n)scanf("%d",&c[i]);
                         sort(c,c+n);
                      if(a>1){     
                                   ans=INF;            
                          frup(add,0,n){
                                        have=a*1ll;
                                         g=add;
                                           frdn(i,0,n-add){
                                                           if(have>c[i]){
                                                                         have+=1ll*c[i];
                                                                         continue;
                                                                         }else {
                                                                               while(have<=c[i])have+=1ll*have-1,g++;
                                                                                have+=1ll*c[i];
                                                                               }
                                                           }
                                         ans=min(ans,g); 
                                        }
                        } else ans=n;
                       printf("Case #%d: %d\n",cases+1,ans);                                
                      }
 return 0;
}       
