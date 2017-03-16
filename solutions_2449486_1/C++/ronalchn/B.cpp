#include<string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cstdlib>

using namespace std;

int G[150][150];

int main() {
  int T;
  cin >> T;
  for (int n=1;n<=T;n++) {
    int N, M;
    cin >> N >> M;
    int mxi[101]={0}, mxj[101]={0};
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) {
      cin >> G[i][j];
      mxi[i]=max(mxi[i],G[i][j]);
      mxj[j]=max(mxj[j],G[i][j]);
    }
    string ans="YES";
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) {
      if (G[i][j] < mxi[i] && G[i][j] < mxj[j]) ans="NO";
    }
    printf("Case #%d: %s\n", n, ans.c_str());
  }
  return 0;
}


