#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <string.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
  if(a.first<b.first) return true;
  if(a.first==b.first && a.second>b.second) return true;
  return false;
}

int main(){
  int T, t, i, N, a, b, CNT;
  pair<int, int> need[1000];
  int start, S[1000];
  scanf("%d", &T);
  for(t=1; t<=T; t++){
    scanf("%d", &N);
    for(i=0; i<N; i++){
      scanf("%d%d", &a, &b);
      need[i].first=a;
      need[i].second=b;
    }
    sort(need, need+N, cmp);
    memset(S, 0, sizeof(S));
    start = 0;
    CNT=0;
    bool ent=true;
    int M=N;
    while(ent && M){
      ent=false;
      for(i=0; i<N; i++){
	if(start>=need[i].second && S[i]!=2){
	  start+=2;
	  S[i]=2;
	  M--;
	  CNT++;
	  ent=true;
	  break;
	}
      }
      if(ent) continue;
      for(i=0; i<N; i++){
	if(S[i]==0){
	  if(start>=need[i].first){
	    start++;
	    S[i]=1;
	    ent=true;
	    CNT++;
	    break;
	  }
	}
      }
    }
    if(M==0)
      printf("Case #%d: %d\n", t, CNT);
    else
      printf("Case #%d: Too Bad\n", t);
  }
  return 0;
}
