#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <list>
#include <climits>

using namespace std;

int A, N;
long long mote[100];
int result;

void solve(int curSize, int idx, int sum)
{
	if(idx >= N){
		result = min(result, sum);
		return;
	}
	if(sum >= result){return;}
	
	if(curSize > mote[idx]) solve(curSize + mote[idx], idx+1, sum);
	else{
		if(curSize > 1){
			solve(curSize + curSize - 1, idx, sum+1);
		}
		solve(curSize, idx+1, sum+1);
	}
}

int main()
{	
	int C;
	scanf("%d", &C);

	while(C --> 0)
	{
		//input
		scanf("%d %d", &A, &N);

		for(int i = 0; i < N; i++){
			scanf("%lld", mote+i);
		}

		sort(mote, mote+N);

		result = 10000;
		
		solve(A, 0, 0);

		static int Case = 1;
		printf("Case #%d: %d\n", Case++, result);
	}

	return 0;
}
