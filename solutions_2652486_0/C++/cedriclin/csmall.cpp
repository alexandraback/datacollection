#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>

using namespace std;

typedef long double ld;

int r, m, n, k;

int a[1<<7];
int b[1<<7];
int c[1<<7];

int prior[1<<7];
map<int,int> prod[1<<7];

int target[1<<4];

int main(){
	int tt; cin >> tt;
	cin >> r >> n >> m >> k;
	int cnt = 0;
	for (int i = 2; i <= m; i++){
		for (int j = i; j <= m; j++)
			for (int k = j; k <= m; k++){
				a[cnt] = i; b[cnt] = j; c[cnt] = k;
				if (i < j && j < k) prior[cnt] = 6;
				else if (i == j && j == k) prior[cnt] = 1;
				else prior[cnt] = 3;
				
				for (int ii = 0; ii <= 1; ii++)
					for (int jj = 0; jj <= 1; jj++)
						for (int kk = 0; kk <= 1; kk++){
							int p = 1;
							if (ii) p *= i;
							if (jj) p *= j;
							if (kk) p *= k;
							prod[cnt][p] += 1;
						}
				
				cnt++;
			}
	}
	cout << "Case #1:" << endl;
	for (int zz = 1; zz <= r; zz++){
		
		for (int i = 0; i < k; i++)
			cin >> target[i];
		
		int best = 0;
		int bestval = 0;
		
		for (int i = 0; i < cnt; i++){
			int sc = prior[i];
			for (int j = 0; j < k; j++){
				sc *= prod[i][target[j]];
			}
			if (sc > bestval){
				bestval = sc;
				best = i;
				//cout << "best = " << a[best] << b[best] << c[best] << ", score = " << sc << endl;
			}
		}
		cout << a[best] << b[best] << c[best] << endl;
	}
	
	return 0;
}
