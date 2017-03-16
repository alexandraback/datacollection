#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  int tc; scanf("%d", &tc);
  int i,j,a,b,dobreak;
  string s;
  for(int tci = 0; tci < tc; tci++) {
    int n,m; scanf("%d%d", &n, &m);
	int t[n][m];
	int p[n][m];
	int r[n][m];
	  for(i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
		scanf("%d",&t[i][j]);
		}
	  }
	  
	  for(i = 0; i < n; i++) {
		  a=-1;
		for(int j = 0; j < m; j++) {
		if (t[i][j]>a) a=t[i][j];
		}
		for(int j = 0; j < m; j++) p[i][j]=a;
	  }
	  
	  for(j = 0; j < m; j++) {
		  a=-1;
		for(int i = 0; i < n; i++) {
		if (t[i][j]>a) a=t[i][j];
		}
		for(int i = 0; i < n; i++) r[i][j]=a;
	  }
/*
for(i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			printf("%d ",p[i][j]);
		}
		printf("\n");
}
for(i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			printf("%d ",r[i][j]);
		}
		printf("\n");
}
*/
s="YES";
dobreak=0;
for(i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if (t[i][j]<p[i][j] && t[i][j]<r[i][j]) {
				s="NO";
				dobreak=1;
				break;
			} 
		}
	if (dobreak) break;
}



printf("Case #%d: %s\n", tci+1, s.c_str());
  }
  return 0;
}

