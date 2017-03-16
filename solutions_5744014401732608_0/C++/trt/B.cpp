#include <bits/stdc++.h>
#define int long long
using namespace std;
main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int z;
	cin >> z;
	for (int i = 0; i < z; ++i){
		int n, len;
		cin >> n >> len;
		vector <vector <int > > A(n+5, vector <int> (n+5, 0) );
		for (int j = 0; j < n-1; ++j){
			for (int x = j+1; x < n-1; ++x){
				A[j][x] = 1;
			}
		}
		cout <<"Case #" << i+1 << ": "; 
		if (len > ( ( 1LL<<(n-2)) ) ){
			cout <<"IMPOSSIBLE\n";
		}
		else if (len == (( 1LL<<(n-2))  ) ){
			for (int j = 0; j < n-1; ++j){
				A[j][n-1] = 1;
			}
			 	
			cout <<"POSSIBLE\n";
			for (int j = 0; j < n; ++j){
				for (int x = 0; x < n; ++x){
					cout << A[j][x];
				}
				cout <<'\n';
			}
		}
		else {
			int k = 1;
			while (len){
				if (len&1){
					if(k != 1)A[k][n-1] = 1;
					else A[0][n-1]  = 1;
				}
				len >>= 1;
				++k;
			}
			
			cout <<"POSSIBLE\n";
			
			for (int j = 0; j < n; ++j){
				for (int x = 0; x < n; ++x){
					cout << A[j][x];
				}
				cout << '\n';
			}
		}
	}
}
