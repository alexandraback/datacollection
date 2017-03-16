#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <utility>

using namespace std;

const int oo = 1000;

int n, m;
int a[101][101], b[101][101], c[101][101];

int mxi[101], mni[101], mxj[101], mnj[101];

int main () {
                                     
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	int ind = 0;
	cin >> t;
	while (t--) {
		cin >> n >> m;         
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		memset(c, 0, sizeof c);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
				c[i][j] = 100;
			}                              
		for (int i = 0; i < n; i++) {
			mxi[i] = -oo;
			mni[i] = oo;
			for (int j = 0; j < m; j++) {
				mxi[i] = max(mxi[i], a[i][j]);
				mni[i] = min(mni[i], a[i][j]);
			}
		}		

		for (int i = 0; i < m; i++) {
			mxj[i] = -oo;
			mnj[i] = oo;
			for (int j = 0; j < n; j++) {
				mxj[i] = max(mxj[i], a[j][i]);
				mnj[i] = min(mnj[i], a[j][i]);
			}
		}		
            
	    for (int i = 0; i < n; i++)
	    	for (int j = 0; j < m; j++) {
	    		c[i][j] = min(c[i][j], mxi[i]);
	    	}
			
	    for (int i = 0; i < m; i++)
	    	for (int j = 0; j < n; j++) {
	    		c[j][i] = min(c[j][i], mxj[i]);
	    	}

	    bool ok = true;
		for (int i = 0; i < n && ok; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != c[i][j]) {
					ok = false;
					break;
				}
//				cout << c[i][j] << " ";
			}						
//			puts("");
		}
		printf("Case #%d: ", ++ind);
		if (ok)
			puts("YES");
		else
			puts("NO");	
	}
	
	
	return 0;
}
