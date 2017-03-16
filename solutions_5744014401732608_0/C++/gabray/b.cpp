#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

#define For(i, n) for(int (i) = 0; (i) < (n); (i)++)

int main(){
	int T;
	cin >> T;
	For(t, T){	
		int n;
		long long m;
		cin >> n >> m;
		bool v[n][n];
		For(i, n) For(j, n) v[i][j] = false;
		for(int i = 1; i < n; i++){
			for(int j = i +1; j< n; j++) v[i][j] = true;
		}

		m--;
		long long moc = 1;
		for(int i = n - 2; i > 0; i--){
	//		cout << "i: " << i << "   moc = " << moc << "  & = " << (m & moc ) << endl;
			if((m & moc) != 0){
				v[0][i] = true;
				m -= moc;
		//		cout << " dal som na: " << i << endl;
		//		cout << "m je teraz: " << m << endl;
			}
			moc *= 2;
		}

		m++;
		if(m == 1){ v[0][n-1] = true; m = 0;}

		if(m == 0){
			cout << "Case #" << t + 1 <<  ": POSSIBLE" << endl;
			For(i, n){
				For(j, n) cout << v[i][j];
				cout << endl;
			}
		} else cout << "Case #" << t + 1 <<  ": IMPOSSIBLE" << endl ;
	}

	return 0;
}