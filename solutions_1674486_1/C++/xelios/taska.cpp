#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int A[1000][1000];
int R[1000];
int N, M;
int S[1000];

int walk(int a){
	int i;
	if (S[a]) return 1;
	S[a]++;
	for(i=0; i < N; i++){
		if (A[i][a]==1) {
			if (walk(i)) return 1;
		}
	}
	return 0;
	
}

int solve(){
	int a,i,j;
	cin >> N;
	
	memset(A, 0, sizeof(A));
	memset(R, 0, sizeof(R));
	
	for (i = 0; i < N; i++){
		cin >> M;
		if (M==0) R[i] = 1;
		for(j=0; j<M; j++) {
			cin >> a;
			A[i][a-1] = 1;
		}
	}
	
	for (i =0; i < N; i++){
		if(R[i]){
			memset(S,0,sizeof(S));
			if (walk(i)) return true;
		}
	}
	
	
	/*for (i=0; i<N; i++){
		for(j=0; j<N; j++){
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;*/
	
	return false;
}

int main(){
	int T;
	cin >> T;
	
	for(int i=0 ;i<T; i++){
		if(solve())
		cout << "Case #" << (i+1) << ": Yes" << endl;
		else
		cout << "Case #" << (i+1) << ": No" << endl;
		
	}
	
	
	
}
