#include <cstdio>
#include <algorithm>

using namespace std;

int solve()
{
	int N, A;
	int B[100];
	
	scanf("%d %d", &A, &N);
	
	for (int i = 0; i < N; i++)
		scanf("%d", B + i);
	
	
	if (A == 1) return (N);
	
	sort(B, B + N);
	
	int ans = 9999;
	for (int i = 0; i <= N; i++){
		int tmp = N - i;
		long long AA = A;
		for (int j = 0; j < i; j++){
			while (AA <= B[j]){
				AA += AA - 1;
				tmp++;
			}
			AA += B[j];
		}
		ans = min(ans, tmp);
	}
	return (ans);
}

int main()
{
	int T;
	
	scanf("%d", &T);
	
	for (int testnum = 1; testnum <= T; testnum++)
		printf("Case #%d: %d\n", testnum, solve());
	
	return (0);
}
