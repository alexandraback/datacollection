#include <iostream>
#include <memory>
#include <stdio.h>
#include <vector>


using namespace std;

int T;
int N,M;

int arr[100][100];

bool cuttable() {
	while(true) {
		int sn,sm;
		sn = sm = 0;
		int minVal = 101;
		for( int n = 0; n < N; n++) {
			for( int m = 0; m < M; m++) {
				minVal = min(minVal, arr[n][m]);
				if( arr[n][m] == minVal ) {
					sn = n;
					sm = m;
				}
			}
		}
		if( minVal == 101 )
			return true;
		// check row
		bool rowOk = true;
		bool colOk = true;
		for( int m = 0; m < M; m++) {
			if( arr[sn][m] > minVal && arr[sn][m] != 101 ){
				rowOk = false;
				break;
			}
		}
		if( rowOk ) {
			for( int m = 0; m < M; m++) {
				arr[sn][m] = 101;
			}
		}else {
			for( int n = 0; n < N; n++) {
				if( arr[n][sm] > minVal && arr[n][sm] != 101) {
					colOk = false;
					break;
				}
			}
			if( colOk ) {
				for( int n = 0; n < N; n++) {
					arr[n][sm] = 101;
				}
			}
		}
		if( !rowOk && !colOk ) {
			return false;
		}
	}
}

int main() {
	scanf("%d", &T);
	for( int t = 0; t < T; t++) {
		scanf("%d %d", &N, &M);
		for( int n = 0; n < N; n++) {
			for( int m = 0; m < M; m++) {
				scanf("%d", &arr[n][m]);
			}
		}
		if( cuttable() ) {
			cout<<"Case #"<<t+1<<": YES\n";
		}else {
			cout<<"Case #"<<t+1<<": NO\n";
		}
	}
	return 0;
}
