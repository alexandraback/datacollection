#include <cstdio>
#include <algorithm>

using namespace std;


int arr[200];

int main() {

	int T, N, S, p;
	scanf("%d", &T);
	for(int t=0; t<T; ++t) {
		scanf("%d %d %d", &N, &S, &p);
		printf("Case #%d: ", t+1);
		for(int n=0; n<N; ++n) {
			scanf("%d", &arr[n]);	
		}
		sort(arr, arr+N);
		int sum = 0;
		for(int n=N-1; n>=0; --n) {
			if(arr[n]>=3*p-2) {
				sum++;
			} else if(arr[n]>=p && arr[n]>=3*p-4 && S>0) {
				sum++;
				S--;
			}
		}
		printf("%d\n", sum);
	}

	return 0;
};
