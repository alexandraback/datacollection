#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>

#define FI first
#define SE second
#define MP make_pair

using namespace std;

const int MAXN=104, DONE=(int)1e9, JUST=DONE-1;

int tnum, n, m, a[MAXN][MAXN];

int main(){
	scanf("%d", &tnum);
	for (int t=1; t<=tnum; t++){
		printf("Case #%d: ", t);
		scanf("%d%d", &n, &m);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				scanf("%d", &a[i][j]);
		
		bool ok=true;
		int vc;
		for (int v=99; v>=0; v--){
			for (int i=1; i<=n; i++){
				vc=0;
				for (int j=1; j<=m; j++)
					if (a[i][j]<=v)	vc++;
						
				if (vc==m)
					for (int j=1; j<=m; j++) 
						if (a[i][j]==v) a[i][j]=JUST; // done cut
			}
			
			for (int i=1; i<=m; i++){
				vc=0;
				for (int j=1; j<=n; j++)
					if (a[j][i]<=v || a[j][i]==JUST) vc++;
					
				if (vc==n)
					for (int j=1; j<=n; j++)
						if (a[j][i]==v) a[j][i]=JUST;
			}
			
			
			for (int i=1; i<=n; i++){
				for (int j=1; j<=m; j++)
					if (a[i][j]==JUST) a[i][j]=DONE;
					else 
						if (a[i][j]==v){
							ok=false;
							break;
						}
						
				if (!ok) break;			
			}
			
			if (!ok) break;
		}
		
		if (ok) printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
