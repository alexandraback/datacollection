#include <bits/stdc++.h>
using namespace std;

int A[1000001];

int main(){
	queue<long long> q;
	A[1] = 1; q.push(1);
	while(!q.empty()){
		long long tmp = q.front(),R = 0;
		if(tmp <= 1000000 && A[tmp + 1] == 0){
			A[tmp + 1] = A[tmp] + 1;
			q.push(tmp + 1);
		}
		while(tmp){
			R = R * 10LL + tmp%10;
			tmp /= 10;
		}
		if(R <= 1000000 && A[R] == 0){
			A[R] = A[q.front()] + 1;
			q.push(R);
		}
		q.pop();
	}
	int T; int N;
	scanf("%d",&T);
	for(int t = 1;t <= T;t++){
		scanf("%d",&N);
		printf("Case #%d: %d\n",t,A[N]);
	}
	return 0;
}