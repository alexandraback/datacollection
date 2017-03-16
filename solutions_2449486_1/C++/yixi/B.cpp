#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int TTT,n,m,a[200][200],maxl[200],maxr[200];

int main(){
	freopen("B-large.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&TTT);
	for (int TT=1; TT<=TTT; TT++){
		printf("Case #%d: ",TT);
		scanf("%d %d",&n,&m);
		for (int i=0; i<n; i++){
			maxl[i]=-1;
		}
		for (int i=0; i<m; i++){
			maxr[i]=-1;
		}
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				scanf("%d",&a[i][j]);
				if (a[i][j]>maxl[i]) maxl[i]=a[i][j];
				if (a[i][j]>maxr[j]) maxr[j]=a[i][j];
			}
		}
		bool t = true;
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++)
				if (a[i][j]<maxl[i] && a[i][j]<maxr[j]) {
					t=false; break;
				}
			if (!t) break;
		}
		if (t) printf("YES\n");
		else printf("NO\n");
	}
	
	fclose(stdout);
	fclose(stdin);
}
