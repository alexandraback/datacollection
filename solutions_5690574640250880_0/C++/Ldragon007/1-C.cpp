#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define outIm printf("Impossible\n")

using namespace std;

int t;
bool vis[55][55];

void fill(int n, int m, int cnt) {
	 for (int i = 4; i <= n + m - 2; i ++ )
	 	 for (int x = min(i, n - 1); x >= 2; x -- ) {
		 	 int y = i - x;
		 	 if (y >= 2 && y < m) {
			 	   vis[x][y] = true;
			 	   cnt -- ;
			 	   if (!cnt) return ;
   		     }
 	  	 }
}

int main() {
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("C-small-attempt2.out", "w", stdout);
	scanf("%d", &t);
	for (int ca = 1; ca <= t; ca ++ ) {
		printf("Case #%d:\n", ca);
		int n, m, cnt;
		scanf("%d%d%d", &n, &m, &cnt);
		if (n == 1 || m == 1 || n * m - 1 == cnt) {
  		   if (cnt == n * m) outIm;
  		   else {
	 	   		for (int i = 0; i < n; i ++ ) {
	 	   			for (int j = 0; j < m; j ++ ) {
						if (i == n - 1 && j == m - 1) printf("c");
	 	   				else if (cnt) printf("*"), cnt -- ;
		                else printf("."); 
	                }
   					 printf("\n");
		       }
		   }
		   continue;
   		}
   		if (n * m - cnt == 2 || n * m - cnt == 3 || n * m - cnt == 5 || n * m - cnt == 7) {
	   	   outIm;
	   	   continue;
        }
        if ((n == 2 || m == 2) && cnt % 2 == 1) {
 	   	   outIm;
 	   	   continue;
		}
		memset(vis, 0, sizeof(vis));
		if (n * m - 1 == cnt) {
		   	  cnt = 0;
		   	  vis[0][0] = true;
  		}
  		else{
			 vis[0][0] = vis[0][1] = vis[1][0] = vis[1][1] = true;
			 cnt = n * m - cnt - 4;
			 int nl = 2, ml = 2;
			 while (cnt > 1) {
   		 	   	  if (nl < n && (nl <= ml || ml == m)) cnt -= 2, vis[nl][0] = vis[nl][1] = true, nl ++ ;
   		 	   	  else if (ml < m) cnt -= 2, vis[0][ml] = vis[1][ml] = true, ml ++ ;
   		 	   	  else break;
			 }
			 if (cnt > 0) fill(n, m, cnt);
		}
		for (int i = 0; i < n; i ++ ) {
			for (int j = 0; j < m; j ++ )
				if (i == 0 && j == 0) printf("c");
				else vis[i][j] ? printf("."): printf("*");
			printf("\n");
		}
	}		
	//system("pause");
	return 0;	
}
