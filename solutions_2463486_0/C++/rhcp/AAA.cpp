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

int n,m,t,a,b,ans=0;

bool pal(int n){
vector<int>a;
 while(n)a.pub(n%10),n/=10;
  frdn(i,0,a.size()/2)if(a[i]!=a[a.size()-1-i])return false;
 return true; 
}

int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
     scanf("%d\n",&t);
      frdn(cases,0,t){
                       scanf("%d %d",&a,&b); ans=0;
                          frup(i,1,b)if(pal(i)&&pal(i*i)&&(i*i>=a&&i*i<=b))ans++;
                        printf("Case #%d: %d\n",cases+1,ans);    
                      }
 return 0;
}       
