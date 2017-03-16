#include <iostream>
#include <stdlib.h>
using namespace std;

//#define FOR(i,N) for(i=0; i<N; i++)
//#define FOR(i,N,s) for(i=s; i<N; i++)
typedef unsigned long long ULL;
typedef long long LL;

typedef struct{
	ULL t,s;
}pair_t;

//pair_t H[600000];
//ULL SIZE = 0;


int F[1000];
char all[3628800*2][10];
int count;

int N;
int set(int N, int start, int A[]){
	int i;
	if(start == N){	
		for(i=0; i<N; ++i){
			all[count][i] = A[i];
		}
		count++;	
		return 0;
	}
	
	for(i=start; i<N; ++i){
		int temp = A[start];
		A[start] = A[i];
		A[i] = temp;
		set(N, start+1, A);
		temp = A[start];
		A[start] = A[i];
		A[i] = temp;
	}
	return 0;
}

ULL solve(){
	int A[10];
	
	int i;
	for(i=0; i<N; ++i)
		A[i] = i;
	count = 0;
	set(N, 0, A);
	//cout << "yes2 " << count << endl;
	
	int ans = 0;
	for(i=0; i<count; ++i){
		int j;
		//for(j=0; j<N; ++j)
		//	cout << (int)all[i][j] << " ";
		//cout << endl;
		for(j=2; j<=N; ++j){
			if(j<=ans) continue;
			int k;
			for(k=1; k<j-1; ++k){
				if(all[i][k-1] != F[all[i][k]] && all[i][k+1] != F[all[i][k]])
					break;
			}
			if(k != j-1) continue;
			
			if(all[i][j-1] != F[all[i][0]] && all[i][1] != F[all[i][0]])
				continue;
			if(all[i][j-2] != F[all[i][j-1]] && all[i][0] != F[all[i][j-1]])
				continue;
			
			ans = j;
			break;
		}
	}
	return ans;
}

int main(){
	int i;
	
	int T;
	cin >> T;
	for(int caseNo = 1; caseNo<=T; ++caseNo){
		cin >> N;
		for(i=0; i<N; ++i){
			cin >> F[i];
			F[i]--;
		}
		//cout << "yes" << endl;
		ULL ans = solve();
		cout << "Case #" << caseNo << ": " << ans << endl;
	}
	
}


