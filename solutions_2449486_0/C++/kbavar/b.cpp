#include <iostream>
using namespace std;


int main()
{
	int t, i, j, k, n, m, b[110][110], x, l, y, z;
	
	cin >> t;
	for (k=0; k<t; k++) {
		cin >> n >> m;
		for (i=0; i<n; i++)
			for (j=0; j<m; j++) 
				cin >> b[i][j];
		x=0;
		for (i=0; i<n; i++)
			for (j=0; j<m; j++) 
				if (b[i][j]==1) {
					z=0;
					for (l=0; l<m; l++)
						if (b[i][l]==2) z++;
					y=0;
					for (l=0; l<n; l++)
						if (b[l][j]==2) y++;
					if (z*y) {
						x++;
					//	cerr << i << j << b[i][j] << endl;
					}
				}
		
		if (x) cout << "Case #" << k+1 << ": NO" <<  endl;
		else cout << "Case #" << k+1 << ": YES" <<  endl;
	}	
	return 0;
}
