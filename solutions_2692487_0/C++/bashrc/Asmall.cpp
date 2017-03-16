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
int N;
int fun(vector<int> cum_sum,int start){
  if(start>=N)  return 0;
  if(cum_sum[start]>cum_sum[start+1]){
    cum_sum[start+1]+=cum_sum[start];
    return fun(cum_sum,start+1);
  }
  else {
    int ans1=1<<29,ans2=1<<29;
      int tmp1=cum_sum[start+1],tmp2=cum_sum[start];
      int cntr=0;
      while(cum_sum[start]!=1&&cum_sum[start]<=cum_sum[start+1]){
       cum_sum[start]=2*cum_sum[start]-1;
       cntr++;
       }
       if(cum_sum[start+1]<cum_sum[start]){
         cum_sum[start+1]+=cum_sum[start];
         ans1=fun(cum_sum,start+1)+cntr;
      }
      cum_sum[start+1]=tmp1;cum_sum[start]=tmp2;
      
    cum_sum[start+1]=cum_sum[start];
    ans2=fun(cum_sum,start+1)+1;
    
    return min(ans1,ans2);
   }
}
int main(){
int t;
scanf("%d",&t);
for(int cases=1;cases<=t;cases++){
  printf("Case #%d: ",cases);
  int A;
  scanf("%d %d",&A,&N);
  int arr[N];
  rd(arr,i,N);
  sort(arr,arr+N);
  vector<int> cum_sum(N+1);
  cum_sum[0]=A;
  for(int i=1;i<=N;i++) cum_sum[i]=arr[i-1];
  cout<<fun(cum_sum,0)<<endl;
  }  
}
