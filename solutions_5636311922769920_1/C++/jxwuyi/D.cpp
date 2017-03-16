#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<numeric>
#include<deque>
using namespace std;
#define LL long long

void run() {
  LL K, C, S;
  cin >> K >> C >> S;
  if(S * C < K) {
    puts(" IMPOSSIBLE");
    return ;
  }
  set<LL> pos;
  for(int i=0;i<K;i+=C) {
    LL p = 0;
    for(int j=0;j<C&&i+j<K;++j)
      p = p * K + (i + j);
    pos.insert(p);
    S --;
  }
  if(S < 0){
    puts(" IMPOSSIBLE");
    return ;
  }
  for(auto&p : pos)
    cout << " " << p + 1;
  cout << endl;
}

int main() {
  freopen("D.in","r",stdin);
  freopen("D.out","w",stdout);
  
  int test;
  cin >> test;
  for(int no=1;no<=test;++no){
    printf("Case #%d:", no);
    run();
  }
}
