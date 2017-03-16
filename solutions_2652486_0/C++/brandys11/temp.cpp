#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cstring>

using namespace std;

vector<int> V(100000);
long long solve(){
	srand(time(NULL));
	int R,N,M,K,a;
	cin >> R >> N >> M >> K;
	for(int r=0;r<R;r++){
		vector<vector<int> > P(K,vector<int>(M+1,0));
		vector<int> A(K),R(M+1,0);
		for(int i=0;i<K;i++){
			cin >> A[i]; 
			for(int j=2;j<=M;j++){
				if(j==4 || j == 8)continue;
				a = A[i]; while(a%j==0){ a/=j; P[i][j]++; }
				R[j] = max(R[j],P[i][j]);
			}
		}
		int celk=0;
		while(rand()%2 && R[2]>1){ R[2]-=2; R[4]++; } 
		for(int i=0;i<M+1;i++)celk+=R[i];
		for(;celk<N;celk++)R[rand()%(M-2)+2]++;
		while(celk>N){ R[2]-=2; R[4]++;celk--; } 
		for(int i=0;i<M+1;i++){
			for(int j=0;j<R[i];j++)cout << i;
		}
		cout << endl;
	}
}
int main(void){
	int T;
	cin >> T;
	for(int t=1;t<=T;t++){
		cout << "Case #" << t <<": "<<endl;
		solve();
	}
}