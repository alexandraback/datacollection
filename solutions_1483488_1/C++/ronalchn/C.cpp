#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

void solve(int t) {
  int A, B;

  cin >> A >> B;
  int a=A;
  int len=0, pow=1;
  while (a>0) {
    a/=10;
    len++;
    pow*=10;
  }
  pow/=10;
  map<int,int> num;
  for (int i=A;i<=B;i++) {
    int min=i, alt=i;
    for (int j=1;j<len;j++) {
      alt = alt/10+(alt%10)*pow;
      if (alt<min) min=alt;
    }
    map<int,int>::iterator it = num.find(min);
    if (it == num.end()) num.insert(pair<int,int>(min,1));
    else it->second++;
  }
  int ans=0;
  for (map<int,int>::iterator it=num.begin();it!=num.end();it++) {
    int n=it->second;
    ans+=n*(n-1)/2;
  }

  printf("Case #%d: %d\n",t,ans);
}

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    solve(t);
  }
  return 0;
}
