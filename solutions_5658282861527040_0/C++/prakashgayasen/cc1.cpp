#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long int int64;
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int64 i,j,k,n,m,t,ans,cnt=1,a,b;
  cin>>t;
  while(t--){
    scanf("%lld %lld %lld",&a,&b,&k);
    ans=0;
    for(i=0;i<a;i++)for(j=0;j<b;j++){
      m = i&j;
      if(m<k)ans++;
    }
    printf("Case #%lld: %lld\n",cnt,ans);
    cnt++;
  }
  return 0;
}

