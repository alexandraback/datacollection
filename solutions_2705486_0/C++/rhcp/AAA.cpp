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

const int to =521196;

const int INF = int(1e9);
const double EPS  = 1e-8;
const long long INF64 = (long long)(1e18)+1,md = 1000000007ll;

int n,m,l=0,ans,t,g=0,changed,ln,lm,dp[100],lst=-1;
bool good;
FILE *fle;
char c[555000][53],a[53],gg;
bool f[300];
string h;

int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
     fle=fopen ("dictinary.txt","r");
     int mx=-1;
        frdn(i,0,521196)fscanf(fle,"%s\n",c[i]);;
    scanf("%d\n",&t);
     frdn(cases,0,t){
                 gets(a);
                  ln=strlen(a);
                  frdn(i,0,ln)dp[i]=INF; 
                   frdn(i,0,ln){
                                
                               frdn(j,0,to){ 
                                             
                                    for(gg='a';gg<='z';gg++)f[gg]=0;         
                                             
                                   changed=0; good=1;
                                   lm=strlen(c[j]);
                                   if(lm+i>ln)continue;
                                    frdn(z,0,lm)if(a[i+z]!=c[j][z])f[a[i+z]]=1,changed++;
                                    
                                    lst=-1;
                                     for(gg='a';gg<='z';gg++)if(f[gg]){
                                                                       if(lst==-1)lst=gg;
                                                                        else {
                                                                             if(gg-lst<5){
                                                                                          good=0;
                                                                                          break;
                                                                                          }
                                                                             }
                                                                         lst=gg;    
                                                                       }
                                    if(!good)continue;
                                    
                                   if(!i)dp[lm-1]=min(dp[lm-1],changed);
                                    else dp[i+lm-1]=min(dp[i+lm-1],dp[i-1]+changed); 
                                  }
                                }
                  // frdn(i,0,ln)cout<<dp[i]<<" ";cout<<endl;             
                    printf("Case #%d: %d\n",cases+1,dp[ln-1]);            
                 } 
 return 0;
}       
