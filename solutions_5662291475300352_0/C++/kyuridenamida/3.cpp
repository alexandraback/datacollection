#include <bits/stdc++.h>
using namespace std;
#define int long long
int putCase(){
	static int t = 1;
	cout << "Case #"<< t++ << ": ";
}

int D[1010],H[1010],M[1010];


signed main(){
	int T;
	cin >> T;
	while(T--){
		putCase();
		int N;
		cin >> N;
		int sum = 0;
		for(int i = 0 ; i < N ; i++){
			cin >> D[i] >> H[i] >> M[i];
			sum += H[i];
		}
		if( sum == 1 ){
			cout << 0 << endl;
		}else if( sum == 2 ){
			int m1,m2;
			int d1,d2;
			if( N == 1 ){
				m1 = M[0];
				m2 = M[0]+1;
				d1 = D[0];
				d2 = D[0];
			}else if( N == 2 ){
				m1 = M[0];
				d1 = D[0];
				m2 = M[1];
				d2 = D[1];
			}
			if( m1 == m2 ){
				cout << 0 << endl;
			}else{
				if( m1 > m2 ){ //はやいほうが (1) になる
					swap(m1,m2);
					swap(d1,d2);
				}
				if( m1*(360-d1+360) > m2*(360-d2) ){
					cout << 0 << endl;
				}else{
					cout << 1 << endl;
				}
			}
		}else{
			cerr << "><" << endl;
		}
		
		
		
		
	}
}