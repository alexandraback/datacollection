#include <bits/stdc++.h>
using namespace std;

struct x {
	int j;
	int p;
	int k;
	int jp[11][11];
	int pk[11][11];
	int jk[11][11];
	};




int main() {
	int t;
	cin >> t;
	int xc = t;
	while(t--){
		int ds[11][11][11];
		for(int q=0;q<11;q++){
			for(int w=0;w<11;w++){
				for(int e=0;e<11;e++){
					ds[q][w][e]=0;
				}
			}
		}
		int count=0;

		int j,p,s,k;
		cin >> j >> p >> s >> k;

		struct x newx;
		for(int i=0;i<11;i++){
			for(int j=0;j<11;j++){
				newx.jp[i][j]=0;
				newx.pk[i][j]=0;
				newx.jk[i][j]=0;
			}
		}
		for(int q=1;q<=j;q++){
			for(int w=1;w<=p;w++){
				for(int e=1;e<=s;e++){
					if(newx.jp[q][w]<k && newx.pk[q][w]<k && newx.jk[q][w]<k){
					newx.jp[q][w]++;
					newx.pk[w][e]++;
					newx.jk[q][e]++;
					ds[q][w][e]=1;

					count++;

					}

				}
			}
		}
		cout <<"Case #"<<xc-t <<": " << count << endl;
		for(int q=1;q<11;q++){
			for(int w=1;w<11;w++){
				for(int e=1;e<11;e++){
					if(ds[q][w][e]==1)
					cout << q << " " << w << " " << e << endl;
				}
			}
		}

	}
	return 0;
}
