#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define MAXN 20005
using namespace std;

int testcase,N,A[MAXN],B[MAXN],F[MAXN],S[MAXN],ans,cur,it,t1;
bool used[MAXN],flag;

bool cp1(int x,int y){
  if(A[x] != A[y]) return A[x] < A[y];
  return x < y;
}

bool cp2(int x,int y){
  if(B[x] != B[y]) return B[x] < B[y];
  return x < y;
}

struct cmp{
  bool operator()(int x,int y){
    if(B[x] != B[y]) return B[x] > B[y];
    return x < y;
  }
};
set <int,cmp> pq;

int main(){
  freopen("B-large.in","r",stdin);
  freopen("ans.out","w",stdout);
  scanf("%d",&testcase);
  for(int TC=1;TC<=testcase;++TC){
    scanf("%d",&N);
    if(TC == 41){
      printf("%d\n",N);
    }
    ans = cur = 0;
    it = 1;
    flag = 1;
    pq.clear();
    for(int i=1;i<=N;++i) scanf("%d%d",&A[i],&B[i]);
    //if(TC == 41) break;
    memset(used,0,sizeof(used));
    for(int i=1;i<=N;++i) F[i] = S[i] = i;
   // if(TC == 41) break;
    sort(F+1,F+N+1,cp1);
    sort(S+1,S+N+1,cp2);
   //if(TC == 41) break;
    for(int i=1;i<=N;++i){
      while(it <= N && A[F[it]] <= cur){
        if(!used[F[it]]) pq.insert(F[it]);
        ++it;
      }
      if(B[S[i]] <= cur){
        cur += (2-used[S[i]]);
        used[S[i]] = 1;
        ++ans;
      }
      else{
        while(!pq.empty()){
          t1 = *pq.begin();
          if(!used[t1]) break;
          pq.erase(t1);
        }
        if(pq.empty()){
          flag = 0;
          break;
        }
        t1 = *pq.begin();
        cur++;
        used[t1] = 1;
        ++ans;
        --i;
      }
    }
    if(!flag) printf("Case #%d: Too Bad\n",TC);
    else printf("Case #%d: %d\n",TC,ans);
   // if(TC == 41) break;
  }
}
