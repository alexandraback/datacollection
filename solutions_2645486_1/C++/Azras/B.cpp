#include <cstdio>
#include <vector>
#include <algorithm>
#define LL long long
#define MP make_pair
#define F first
#define S second
using namespace std;
LL ans;
int maxE, plusE, n;
int arr[10000];
int energy[10000];
int must[10000];
pair<LL, int> all[10000];
int main(){
	int t;
	scanf("%d", &t);
	for(int test = 1; test <= t; test++){
		ans = 0;
		scanf("%d %d %d", &maxE, &plusE, &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
			all[i].F = 1000000LL * arr[i] + (n - i);
			all[i].S = i;
			energy[i] = maxE;
			must[i] = 0;
		}
		sort(all, all + n);
		reverse(all, all + n);
		for(int j = 0; j < n; j++){
			int i = all[j].S;
			int give = energy[i] - must[i];
			ans += (LL)arr[i] * give;
			for(int k = i + 1; k < n; k++){
				int can = must[i] + (LL)plusE * (k - i);
				if(can > maxE) break;
				energy[k] = min(energy[k], can);
			}
			for(int k = i - 1; k >=0; k--){
				int now = energy[i] - (LL)plusE * (i - k);
				if(now <= 0) break;
				must[k] = max(must[k], now);
			}
		}
		printf("Case #%d: %lld\n", test, ans);
	}
	return 0;
}

