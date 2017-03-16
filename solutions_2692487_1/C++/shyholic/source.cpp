#include<cstdio>
#include<algorithm>

using namespace std;

int A, N;
int motes[100];

int process(){
	int i;
	sort(motes, motes+N);

	if(A == 1) return N;

	int sum = A;
	int mincnt = N;
	int cnt = 0;
	int idx = 0;
	while(idx < N){
		if(motes[idx] < sum){
			sum = sum + motes[idx];
			idx = idx + 1;
		}
		else{
			mincnt = mincnt > cnt + (N-idx) ? cnt + (N-idx) : mincnt;

			sum = sum * 2 - 1;
			cnt = cnt + 1;
		}

		if(cnt > mincnt) break;
	}
	mincnt = mincnt > cnt ? cnt : mincnt;
	return mincnt;
}

int main(void){
	int T;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d %d",&A, &N);
		for(int j=0;j<N;j++){
			scanf("%d",&motes[j]);
		}
		
		int ans = process();
		printf("Case #%d: %d\n", i+1, ans);
	}
}