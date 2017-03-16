#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
using namespace std;

int T;
int a[100][100];
int n, m;

int main() {
	int t;
	int i, j, k;
	int ok, cntBad;

    cin>>T;
    for(t=0; t<T; t++) {
		cout<<"Case #"<<t+1<<": ";

		cin>>n>>m;
		for(i=0; i<n; i++) for(j=0; j<m; j++) cin>>a[i][j];

		ok=1;
		for(i=0; i<n && ok; i++) for(j=0; j<m && ok; j++) {
			cntBad=0;
			// horizontal
			for(k=0; k<m; k++) if(a[i][j]<a[i][k]) { cntBad++; break; }
			// vertical
			for(k=0; k<n; k++) if(a[i][j]<a[k][j]) { cntBad++; break; }

			if(cntBad==2) ok=0;
		}

		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}
