#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, x, y;
	bool ok;
	int max_x[100], max_y[100];
	int dat[100][100];

	cin >> n;
	for (int i=1; i<=n; i++){
		ok = true;
		cin >> x >> y;
		for (int k=0; k < x; k++){
			max_x[k]=-1;
			for (int j=0; j < y; j++){
				cin >> dat[k][j];
				if (dat[k][j]>max_x[k]) {
					max_x[k]=dat[k][j];
				}
			}
		}

		for (int j=0; j < y; j++){
			max_y[j]=-1;
			for (int k=0; k < x; k++){
				if (dat[k][j]>max_y[j]) {
					max_y[j]=dat[k][j];
				}
			}
		}

		for (int k=0; k < x; k++){
			for (int j=0; j < y; j++){
				if ((dat[k][j]<max_x[k]) && (dat[k][j]<max_y[j])){
					ok=false;
					break;
				}
			}
			if (!ok) break;
		}
		if (ok){
			cout << "Case #" << i << ": YES" << endl;
		}
		else {
			cout << "Case #" << i << ": NO" << endl;
		}
		
	}
	return 0;
}
