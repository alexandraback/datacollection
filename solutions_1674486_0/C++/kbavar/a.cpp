#include <iostream>
using namespace std;

int c[1001], ans, z;
int g[1001][1001];

int dfs(int k){
	int i, j;
	if (c[k]) { 
		ans=1;
		//cout << z << " --> " << k << endl;
	}
	else {
		c[k]=1;
		for (i=1; i<=g[k][0]; i++) 
			dfs(g[k][i]);
	}
}

int main()
{
	int t, n, i, j, m, k;
	
	cin >> t;
	for (i=0; i<t; i++) {
		cin >> n;

		for (j=0; j<=n; j++) 
			for (k=0; k<=n; k++) 
				g[j][k]=0;
				
		for (j=1; j<=n; j++) {
			cin >> g[j][0];
			for (k=1; k<=g[j][0]; k++) {
				cin >> g[j][k];
			}
		}
		ans=0;
		for (j=1; j<=n; j++) {
			for (m=0; m<=n; m++) c[m]=0;
			z=j;
			dfs(j);
		}
		if (ans) cout << "Case #" << i+1 << ": Yes" << endl;
		else cout << "Case #" << i+1 << ": No" << endl;
	}	
	return 0;
}
