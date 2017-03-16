#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i=1;i<=T;i++) {
    int E, R, N;
    scanf("%d %d %d\n",&E,&R,&N);
    vector<int> w;
    for (int j=0;j<N;j++) {
      int v;
      cin >> v;
      w.push_back(v);
    }
    int V[12][7]={};
    for (int y=0;y<=E;y++) V[0][y]=0;
    for (int x=1;x<=N;x++) {
      for (int y=0;y<=E;y++) {
	int val=0;
	for (int z=max(y-R,0);z<=E;z++) {
	  int nv=V[x-1][z] + w[x-1]*(min(z+R,E)-y);
	  if (val<nv) val=nv;
	}
	V[x][y] = val;
      }
    }
    printf("Case #%d: %d\n", i, V[N][0]);
  }
  return 0;
}


