#include <iostream>
#include <cstdio>
#include <string>
#define MAXN 1000
using namespace std;

int checkPalin(int x){
  string s = "";
  while(x > 0){
    s += x%10 + '0';
    x /= 10;
  }
  string y = s;
  reverse(y.begin(),y.end());
  return s == y;
}

int main(){
  freopen("C-small-attempt0.in","r",stdin);
  freopen("C.out","w",stdout);
  int testcase;
  scanf("%d",&testcase);
  for(int TC=1;TC<=testcase;++TC){
    int A,B,cnt = 0;
    scanf("%d%d",&A,&B);
    for(int i=1;i<=B;++i)
      if(checkPalin(i) && checkPalin(i*i) && i*i >= A && i*i <= B) ++cnt;
    printf("Case #%d: %d\n",TC,cnt);
  }
}
