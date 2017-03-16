#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#define MAXN 20000000
using namespace std;

int pal(long long x){
  string s = "";
  while(x > 0){
    s += x%10ll + '0';
    x /= 10ll;
  }
  string y = s;
  reverse(y.begin(),y.end());
  return s == y;
}

vector <long long> V;



int main(){
  for(long long i=1;i<=MAXN;++i){
    if(i > 10 && i%10 != 1 && i%10 != 2) continue;
    if(pal(i) && pal(i*i)) V.push_back(i*i);
  }
  freopen("C-large-1.in","r",stdin);
  freopen("C.out","w",stdout);
  int testcase;
  scanf("%d",&testcase);
  for(int TC=1;TC<=testcase;++TC){
    long long A,B;
    int cnt = 0;
    scanf("%lld%lld",&A,&B);
    int t2 = lower_bound(V.begin(),V.end(),B) - V.begin();
    int t1 = lower_bound(V.begin(),V.end(),A) - V.begin();
    while(V[t1] < A) ++t1;
    while(t2 >= V.size() || V[t2] > B) --t2;
    cnt = t2 - t1 + 1;
   /* for(int i=1;i<=B;++i)
      if(checkPalin(i) && checkPalin(i*i) && i*i >= A && i*i <= B) ++cnt;*/
    printf("Case #%d: %d\n",TC,cnt);
  }
}
