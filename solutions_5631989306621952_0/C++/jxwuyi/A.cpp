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

string run() {
  string S;
  cin >> S;
  string T;
  for(int i=0;i<S.size();++i){
    char c=S[i];
    if(i==0){T.push_back(c); continue;}
    string A;
    A.push_back(c); A.append(T);
    string B = T;
    B.push_back(c);
    T = max(A, B);
  }
  return T;
}

int main() {
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  int test;scanf("%d",&test);
  for(int no=1;no<=test;++no)
    printf("Case #%d: %s\n", no, run().c_str());
}
