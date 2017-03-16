#include <stdio.h>
#include <stdlib.h>

#include <vector>

using namespace std;

vector < vector <int> > graf;
vector < vector <int> > graf2;

vector <bool> bol;

int dfs(int v) {

	bol[v] = true;
//	printf("Bol %d\n", v);

	int i;
	for ( i = 0; i < graf[v].size(); ++i ) {
		int vv = graf[v][i];
		if ( bol[vv] )
			return 1;
		if ( dfs(vv) )
			return 1;
	}

	return 0;

}

int main() {

	int i, t;
	scanf("%d", &t);

	for ( i = 0; i < t; ++i ) {

		int n;
		scanf("%d", &n);

		graf = vector < vector <int> >(n);
		graf2 = vector < vector <int> >(n);
		bol = vector <bool>(n, false);

		int j;
		for ( j = 0; j < n; ++j ) {

			int m;
			scanf("%d", &m);

			int k;
			for ( k = 0; k < m; ++k ) {
				int a;
				scanf("%d", &a);
				--a;
				graf[j].push_back(a);
				graf2[a].push_back(j);
			}

		}

		int aa = 0;

		for ( j = 0; j < n; ++j ) {
			if ( graf2[j].size() == 0 ) {
				bol = vector <bool>(n, false);
				if ( dfs(j) ) {
					aa = 1;
					break;
				}
			}
		}

		if ( aa )
			printf("Case #%d: Yes\n", i+1);
		else
			printf("Case #%d: No\n", i+1);

	}

	return 0;

}
