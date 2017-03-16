#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;



void solve(int t) {
  //string str;
  //getline (cin,str);
  int N, M;
  cin >> N >> M;
  vector<long long> a, A, b, B;
  long long x,y;
  for (int i=0;i<N;i++) {
	cin >> x >> y;
	a.push_back(x);
	A.push_back(y);
  }
  for (int i=0;i<M;i++) {
	cin >> x >> y;
	b.push_back(x);
	B.push_back(y);
  }
  long long grid[110][110];
  for (int i=0;i<=N;i++) {
	for (int j=0;j<=M;j++) {
	  grid[i][j]=0;
	}
  }
  for (int i=0;i<=N;i++) {
	for (int j=0;j<=M;j++) {
	  /*x=i;
	  y=j;
	  int res=0;
	  if (A[x]!=B[y]) continue;
	  int leftover=a[x]-b[y];
	  res=min(a[x],b[y]);
	  grid[x+1][y+1]
	  while (leftover!=0) {
		if (leftover>0) {
		  y++;

		}
	  }*/
	  for (int k=0;k<i;k++) {
		for (int z=0;z<j;z++) {
		  int ta=0, tb=0;
		  for (int x=k;x<i;x++) {
			if (A[x]==A[k]) ta+=a[x];
		  }
		  for (int x=z;x<j;x++) if (B[x]==A[k]) tb+=b[x];
		  grid[i][j]=max(grid[i][j],grid[k][z]+min(ta,tb));
		  //cout << "grid " << i << "," << j << " gets answer of " << grid[i][j] << endl;
		}
	  }
	}
  }
  printf("Case #%d: ",t);
  cout << grid[N][M] << endl;
}

int main() {
  int T;
  cin >> T;

  for (int t=1;t<=T;t++) {
    solve(t);
  }
  return 0;
}
