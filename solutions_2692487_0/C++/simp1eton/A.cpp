#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 1000005
using namespace std;

typedef long long int ll;
int testcase,N,ans,cnt[MAXN],tmp;
ll A,S[MAXN];

int main(){
  freopen("A-small-attempt1.in","r",stdin);
  freopen("A.out","w",stdout);
  scanf("%d",&testcase);
  for(int TC=1;TC<=testcase;++TC){
    scanf("%lld%d",&A,&N);
    for(int i=0;i<N;++i) scanf("%lld",&S[i]);
    sort(S,S+N);
    ans = 0;
    if(A == 1){
      ans = N;
      goto end;
    }
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<N;++i){
      while(A <= S[i]){
         ++cnt[i];
         ++ans;
         A += A - 1ll;
      }
     // printf("S[%d] = %d\n",i,S[i]);
      A += S[i];
    }
    tmp = ans;
  // printf("ans = %d\n",ans);
    for(int i=N-1;i>=0;--i){
      tmp -= (cnt[i] - 1);
    //  printf("tmp = %d\n",tmp);
      ans = min(ans,tmp);
    }
    end:;
    printf("Case #%d: %d\n",TC,ans);
  }
}
