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

long long n,m,t,ans=0,to,from;
int c[10000007];
long long a,b;

bool pal(long long n){
vector<int>a;
 while(n)a.pub(n%10),n/=10;
  frdn(i,0,a.size()/2)if(a[i]!=a[a.size()-1-i])return false;
 return true; 
}


int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
     scanf("%I64d\n",&t);
   frup(i,1,10000000){
                      c[i]=c[i-1];
                       if(pal(i)&&pal(1ll*i*i))c[i]++;
                      }     
      frdn(cases,0,t){
                       scanf("%I64d %I64d",&a,&b); ans=0;
                          to=(long long)(sqrt(b))+1;
                           while(to*to>b)to--;
                          from=(long long)(sqrt(a))-1;
                           while(from*from<a)from++;  
                        printf("Case #%d: %d\n",cases+1,c[to]-c[from-1]);    
                      }
 return 0;
}       
