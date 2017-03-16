#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std ;


vector<pair<long long, long long > > A,B;



int main(){

	int R;
	cin >> R;
	for( int r = 1; r <= R;r++){
		long long t, T;
		int m,n;
		cin >> n >> m;
		A.clear();B.clear();
		cout << "Case #"<<r<<": ";
		for(int i = 0; i < n; i++){
			cin >> t >> T;
			A.push_back( make_pair( t, T ));

		}
		for( int i = 0; i < m; i++){
			cin >> t >> T;
			B.push_back( make_pair( t, T ));
		}
		long long res = 0;
		for( int j = 0; j < ( 1 << n ); j++){
			int k = 0;
			long long tmp = 0;
			long long queda[ m ] ;
			for( int x = 0; x < m; x++) queda[x] = B[x].first;
			for( int i = 0;  i < n; i++){
				if ( ( j & ( 1 << i )) == 0 ) continue;
				int fin = i;
				long long quedai = A[i].first;
				for( ; k < m; k++){
					if ( A[i].second == B[k].second ){
						if ( quedai == 0 || queda[k] == 0) continue;
						long long T = min(quedai, queda[k]);
						tmp +=T;
						quedai -=T;
						queda[k] -= T;
						fin = k;
					}	
				}
				k = fin ;
				if ( k == m -1) {
					res = max( res, tmp );
					tmp = 0;
					k = 0;
				}
			}
			res = max( res,tmp);
		}
		cout << res<< endl;


	}

	return 0;
}
