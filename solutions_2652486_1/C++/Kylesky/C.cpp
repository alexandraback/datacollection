#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	int cases;
	scanf("%d", &cases);
	
	long long r, n, m, k;
	scanf("%lld %lld %lld %lld", &r, &n, &m, &k);
	printf("Case #1:\n");
	for(int i=0; i<r; i++){
		long long nums[k];
		for(int i=0; i<k; i++){
			scanf("%lld", &nums[i]);
		}
		int div[10];
		int maxn[10];
		int tot = 0;
		memset(div, 0, 10*sizeof(int));
		memset(maxn, 0, 10*sizeof(int));
		for(int i=0; i<k; i++){
			long long num = nums[i];
			int temp[10];
			memset(temp, 0, 10*sizeof(int));
			for(int j=2; j<=m && num != 1; j++){
				while(num%j == 0){
					num /= j;
					div[j]++;
					temp[j]++;
				}
			}
			for(int j=2; j<=m; j++){
				maxn[j] = max(maxn[j], temp[j]);
			}
		}
		for(int i=2; i<=m; i++){
			// printf("%d ", maxn[i]);
			tot += maxn[i];
		}
		// printf("\n");
		while(tot != n){
			// printf("  %d %d ", tot, n);
			// for(int i=2; i<=m; i++){
				// printf("%d ", maxn[i]);
			// }
			// printf("\n");
			bool change = false;
			bool changea = false;
			while(maxn[2] > 2 && tot > n){
				maxn[8]++;
				maxn[2]-=3;
				tot-=2;
				change = true;
			}
			while( (maxn[8] > 0 && tot < n-1 && !change) || (maxn[2] == 0 && tot > n && !change) ){
				maxn[8]--;
				maxn[2]+=3;
				tot+=2;
				changea = true;
			}
			while(maxn[2] > 0 && maxn[3] > 0 && tot > n){
				maxn[6]++;
				maxn[2]--;
				maxn[3]--;
				tot--;
				change = true;
			}
			while( (maxn[6] > 0 && tot < n && !change) || (maxn[2] == 0 && tot > n && !change) ){
				maxn[6]--;
				maxn[3]++;
				maxn[2]++;
				tot++;
				changea = true;
			}
			while( (maxn[4] > 0 && tot < n && !change) || (maxn[2] == 0 && tot > n && !change) ){
				maxn[4]--;
				maxn[2]+=2;
				tot++;
				changea = true;
			}
			while(maxn[2] > 0 && maxn[4] > 0 && tot > n){
				maxn[8]++;
				maxn[2]--;
				maxn[4]--;
				tot--;
				change = true;
			}
			while(maxn[2] > 1 && tot > n){
				maxn[4]++;
				maxn[2]-=2;
				tot--;
				change = true;
			}
			if(!change && !changea) break;
		}
		while(tot < n){
			maxn[rand()%(m-1)+2]++;
			tot++;
		}
		for(int i=2; i<=m; i++){
			for(int j=0; j<maxn[i]; j++){
				printf("%d", i);
			}
		}
		printf("\n");
		
	}

	return 0;
}