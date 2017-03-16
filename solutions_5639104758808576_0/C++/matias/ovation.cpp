#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main() {
  int T, len;
  string str;
  cin>>T;
  for (int t=1;t<=T;t++){
    cin>>len>>str;
    int total=0,best=0;
    for (int k=0;k<len;k++) {
      total += str[k]-'0';
      best = max(best,k+1-total);
    }
    printf("Case #%d: %d\n",t,best);
  }
}
