#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N_MAX = 1005;
int arr[N_MAX];

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("pB_small.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for(int cnt = 1; cnt <= t; cnt++){
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		int ans = N_MAX;
		for(int i = 1; i <= N_MAX; i++){
			int tmp = i;
			for(int j = 0; j < n; j++)
				tmp += (arr[j] - 1) / i;
			ans = min(ans, tmp);
		}
		printf("Case #%d: %d\n", cnt, ans);
	}
	return 0;
}
