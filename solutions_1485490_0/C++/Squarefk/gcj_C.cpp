#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MaxN= 111;
long long T, N, M, a[MaxN], b[MaxN], A[MaxN], B[MaxN], ans, CaseCount;
int main(){
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	scanf("%lld", &T);
	while(T --){
		scanf("%lld%lld", &N, &M);
		ans= 0;
		for(int i= 1;i<= N;++ i)
			scanf("%lld%lld", a+i, A+i);
		for(int i= 1;i<= M;++ i)
			scanf("%lld%lld", b+i, B+i);
		if(N == 1){
			for(int i= 1;i<= M;++ i)
				if(A[1] == B[i])
					ans= max(ans, min(a[1], b[i]));
		}
		if(N == 2){
			for(int i= 1;i<= M;++ i){
				if(A[1] == B[i])
					ans= max(ans, min(a[1], b[i]));
				if(A[2] == B[i])
					ans= max(ans, min(a[2], b[i]));
			}
			for(int i= 1;i<= M;++ i)
				for(int j= i+1;j<= M;++ j){
					long long x= A[1] == B[i] ? min(a[1], b[i]) : 0,
						y= A[2] == B[j] ? min(a[2], b[j]) : 0;
					ans= max(ans, x+y);
				}
		}
		if(N == 3){
			for(int i= 1;i<= M;++ i){
				if(A[1] == B[i])
					ans= max(ans, min(a[1], b[i]));
				if(A[2] == B[i])
					ans= max(ans, min(a[2], b[i]));
				if(A[3] == B[i])
					ans= max(ans, min(a[3], b[i]));
			}
			for(int i= 1;i<= M;++ i)
				for(int j= 1;j<= M;++ j){
					long long x= 0, y= 0;
					if(A[1] == B[i])
						x= max(x, min(a[1], b[i]));
					if(A[2] == B[j])
						y= max(y, min(a[2], b[j]));
					ans= max(ans, x+y);

					x= y= 0;
					if(A[1] == B[i])
						x= max(x, min(a[1], b[i]));
					if(A[3] == B[j])
						y= max(y, min(a[3], b[j]));
					ans= max(ans, x+y);

					x= y= 0;
					if(A[2] == B[i])
						x= max(x, min(a[2], b[i]));
					if(A[3] == B[j])
						y= max(y, min(a[3], b[j]));
				}
			for(int i= 1;i<= M;++ i)
				for(int j= i+1;j<= M;++ j)
					for(int k= j+1;k<= M;++ k){
						long long x= A[1] == B[i] ? min(a[1], b[i]) : 0,
							y= A[2] == B[j] ? min(a[2], b[j]) : 0,
							z= A[3] == B[k] ? min(a[3], b[k]) : 0;
						ans= max(ans, x+y+z);
					}
		}
		printf("Case #%lld: %lld\n",++ CaseCount, ans);
	}
}
