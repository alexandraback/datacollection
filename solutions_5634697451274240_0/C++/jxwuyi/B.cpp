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

int run() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int ret=0;
  for(int i=0;i<s.size();++i){
    if(s[i]=='+') continue;
    ret ++;
    for(int j=i;j<s.size();++j)
      if(s[j]=='+')s[j]='-';
      else s[j]='+';
  }
  return ret;
}

int main() {
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  
  int test;
  cin >> test;
  for(int no=1;no<=test;++no)
    printf("Case #%d: %d\n", no, run());
}
