#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

bool arr[3000000];
int from[3000000];

int nums[20];

int max(int a, int b) {
	return a < b ? b : a;
}

int main() {

	int T;
	scanf("%d", &T);
	for(int t=0; t<T; ++t) {
		
		int S;
		scanf("%d", &S);
		for(int i=0; i<S; ++i) {
			scanf("%d", &nums[i]);
		}
		sort(nums, nums+S);
		printf("Case #%d:\n", t+1);
		
		memset(arr, 0, sizeof(arr));
		arr[0]=true;
		int mx = 0;
		bool found = false;
		for(int i=0; i<S && !found; ++i) {
			//printf("-----%d\n", i);
			for(int j=0; j<=mx && !found; j++) {
				//printf("- %d\n", j);
				if(arr[j]) {
					if(from[j]==nums[i]) { }
					//printf("- geht\n", j);
					else if(arr[j+nums[i]]) {
						//printf("FOUND!\n");
						// found!
						found = true;
						// erstes set
						int a = j;
						printf("%d", nums[i]);
						while(a>0) {
							printf(" %d", from[a]);
							a = a-from[a];
						}
						printf("\n");
						// zweites set
						a = j+nums[i];
						bool first=true;
						while(a>0) {
							if(!first) printf(" ");
							first=false;
							printf("%d", from[a]);
							a = a-from[a];
						}
						printf("\n");
					} else {
						mx = max(mx, j+nums[i]);
						arr[j+nums[i]] = true;
						from[j+nums[i]] = nums[i];
					}
				}
			}
		}
		if(!found) {
			printf("Impossible\n");
		}
		
	}
	return 0;
}
