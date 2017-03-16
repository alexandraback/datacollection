#include<stdio.h>
#include<algorithm>
#include<deque>
#include<limits.h>

using namespace std;

int Solve(int a, int b[], int N){
	int res = 0;
	int i=0;
	while(i<N){
		if(a > b[i]){
			a+=b[i];
			++i;
		}
		else if(a>1){
			a+=(a-1);
			++res;
		}
		else return N;
	}
	return res;
}


int main() {
	int T, caseNum;
	scanf("%d",&T);
	for(caseNum=1; caseNum<=T; ++caseNum) {
		int a, N, B[100];
		scanf("%d%d",&a,&N);
		for(int i=0; i<N; ++i)
			scanf("%d",B+i);
		sort(B, B+N);
		int res = N;
		for(int i=0; i<N; ++i){
			int x = i+Solve(a, B, N-i);
			// printf("remove %d: res:%d\n", i,x);
			res = min(res, x);
		}

		printf("Case #%d: %d\n", caseNum,res);
	}
	return 0;
}
