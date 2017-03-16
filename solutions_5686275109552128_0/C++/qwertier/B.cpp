#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;
#define N 1010

int a[N],n;
bool check(int t){
  REP(i,t+1){
    int flag=1,rem=t-i;
    //printf("%d %d\n",i,t);
    FOR(j,n){
      if(a[j]>i){
        if(!i || (a[j]-1)/i>rem){
          flag=0;
          break;
        }else{
          rem-=(a[j]-1)/i;
        }
      }
    }
    if(flag)return true;
  }
  return false;
}
int main(){
#ifdef QWERTIER
  freopen("b.in","r",stdin);
  freopen(".out","w",stdout);
#endif 
  int T;
  scanf("%d",&T);
  FOR(kase,T){
    printf("Case #%d: ",kase);
    scanf("%d",&n);
    FOR(i,n)scanf("%d",&a[i]);
    int lo=1,hi=1000;
    while(lo<hi){
      int mi=(lo+hi)/2;
      if(check(mi))hi=mi;
      else lo=mi+1;
    }
    printf("%d\n",lo);
  }
  return 0;
}
