//factory.cpp
//By λKT345

#include<cstdio>

const int MAX_N=102;

template<class T>
inline T FIM(T a, T b) { return(a<b?a:b); }

template<class T>
inline T FAM(T a, T b) { return(a>b?a:b); }

int main() {
	int T, N, M;
	long long A[MAX_N], B[MAX_N], a[MAX_N], b[MAX_N];
	long long dyn[MAX_N][MAX_N];
	scanf("%d", &T);
	for(int t=1; t<=T; t++) {
		scanf("%d%d", &N, &M);
		for(int i=1; i<=N; i++) {
			scanf("%lld%lld", &a[i], &A[i]);
		}
		for(int i=1; i<=N; i++) {
			scanf("%lld%lld", &b[i], &B[i]);
		}
		
		for(int i=0; i<MAX_N; i++) {
			for(int j=0; j<MAX_N; j++) {
				dyn[i][j]=0;
			}
		}

		for(int i=N; i>0; i--) {
			for(int j=M; j>0; j--) {
				if(A[i]==B[j]) {
					dyn[i][j]=FAM<long long>(dyn[i+1][j+1]+FIM<long long>(a[i], b[j]), FAM<long long>(dyn[i+1][j], dyn[i][j+1]));
				} else {
					dyn[i][j]=FAM<long long>(dyn[i+1][j], dyn[i][j+1]);
				}
			}
		
		}
		printf("Case #%d: %lld\n", t,  dyn[1][1]);
	}	
	return 0;
}

