#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

void main2(){
  int i;
  int N,S,p,t[110];

  scanf("%d %d %d",&N,&S,&p);
  rep(i,N) scanf("%d",&t[i]);

  sort(t,t+N);

  int res = 0;
  rep(i,N){
    if(3*p - 4 > t[i]) continue;
    if(S > 0 && p <= t[i] && abs(3*p - t[i]) <= 4){ // cout << t[i] << endl;
      S--;
      res++;
    } else if(3*p - 2 <= t[i]){
      res++;
    }
  }

  cout << res << endl;
}

int main(){
  int T,t;
  scanf("%d",&T);
  rep(t,T){
    printf("Case #%d: ",t+1);
    main2();
  }
  return 0;
}
