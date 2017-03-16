#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int r[100], c[100];
int nm[100][100];

int main(){
	int t, i, j, k, n, m;
	bool p;
	cin >> t;
	for (i=0; i<t; ++i) {
		p = true;
		cin >> n >> m;
		memset(r, 0xff, sizeof(int)*100);
		memset(c, 0xff, sizeof(int)*100);
		for (j=0; j<n; ++j) {
			for (k=0; k<m; ++k) {
				cin >> nm[j][k];
				if (nm[j][k]>r[j]) r[j]=nm[j][k];
				if (nm[j][k]>c[k]) c[k]=nm[j][k];
			}
		}
		
		for (j=0; j<n; ++j) {
			for (k=0; k<m; ++k) {
				if (nm[j][k]!=r[j]&&nm[j][k]!=c[k])
					p = false;
			}
		}
		
		if(p) cout << "Case #" << (i+1) <<": "<<"YES"<<endl;
		else cout << "Case #" << (i+1) <<": "<<"NO"<<endl;
	}
	
	return 0;
}