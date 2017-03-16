#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<climits>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<clocale>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
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

#define PR(x) cout<<#x<<"="<<x<<energydl
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
 
 
int e,r,n,mx;
int v[100];
void solve(int idx,int energy,int gain){

                    if(idx==n){
                               mx=max(mx,gain);
                               return ;
                              }
                   
                   
                   for(int i=0;i<=energy;i++){
                                         if((energy-i+r)<=e)
                                          solve(idx+1,(energy-i)+r,gain+v[idx]*i);        
                                         else
                                         solve(idx+1,e,gain+v[idx]*i);
                                        }
                   
return ;
}
int main()
{
int t;
scanf("%d",&t);
for(int cases=1;cases<=t;cases++){
  printf("Case #%d: ",cases);
  mx=-1;
  cin>>e>>r>>n;
  rd(v,i,n);
  solve(0,e,0);
  cout<<mx<<endl;
  }                 
}
