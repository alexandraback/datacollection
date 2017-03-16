#include<iostream>
#include<math.h>
using namespace std;
int R, E;
int func(int e, int N, int arr[], int pre)
{
	if(N == 0) return pre;
	int ans = 0;
	for(int i = 0; i <= e; i++) {
		int temp = func(min(E, e - i + R), N - 1, arr + 1, pre + i * arr[0]);
		if(temp > ans) ans = temp;
	}
	return ans;
}

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("outB.txt", "w", stdout);
	int T;
	int  N;
	int arr[1000];
	scanf("%d", &T);
	for(int i = 1; i <= T; i++) {
		scanf("%d%d%d", &E, &R, &N);
		for(int j = 0; j < N; j++) {
			scanf("%d", &arr[j]);
		}
		printf("Case #%d: %d\n", i, func(E, N, arr, 0));
	}
	return 0;
}

