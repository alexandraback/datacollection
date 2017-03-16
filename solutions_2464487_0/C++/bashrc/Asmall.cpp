#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<utility>

#define PR(x) cout<<#x<<"="<<x<<endl
#define READ2(x,y) scanf("%d %d",&x,&y)
#define REP(i,a) for(int i=0;i<a;i++)
#define READ(x) cin>>x
#define PRARR(x,n) for(int i=0;i<n;i++)printf(#x"[%d]=\t%d\n",i,x[i])
#define rd(arr,i,n) for(int i=0;i<n;i++) cin>>arr[i]
#define PB push_back
#define SUM(arr,n,sum) {sum=0;for(int i=0;i<n;i++) sum+=arr[i]; }
#define VC vector
#define CLR(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
using namespace std;
int main(){
  double pie=acos(-1);
  int t;
  scanf("%d",&t);
  int T=0;
  while(t--){
    T++;
    printf("Case #%d: ",T);
    int r,t;
    cin>>r>>t;
    int cntr=0;
    long long paint_used=0;
    int new_radius=r;
    for(;;){
     
      paint_used+=(((new_radius+1)*(new_radius+1)-((new_radius)*(new_radius))));
      //PR(paint_used);
      if(paint_used>t) break;
      cntr++;
      new_radius+=2;
    }
   cout<<cntr<<endl;
   
  }
}
