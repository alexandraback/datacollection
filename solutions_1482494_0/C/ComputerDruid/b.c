//Dan Johnson
//Google Code Jam
//Round 1A 2012
//Problem B
//Kingdom Rush
#include <stdio.h>

int main() {
	int T;
	scanf("%d\n", &T);
	int N;
	int one_req[10000];
	int two_req[10000];
	int seen[10000];
	int one_seen[10000];
	int i;
	for(i = 0; i < T; ++i) {
		scanf("%d", &N);
		//fprintf(stdout, "=============================\n");

		int x;
		for (x = 0; x < N; ++x) {
			scanf("%d %d", &one_req[x], &two_req[x]);
			//fprintf(stdout, "%d %d\n", one_req[x], two_req[x]);
		}
		int y;
		for (y = 0; y < N; ++y) {
			seen[y] = 0;
			one_seen[y]=0;
		}
		int z;
		int stars = 0;
		int found = 0;
		int one_count = 0;
		for (y = 0; y < N;) {
			found = 0;
			for (z = 0; z < N; ++z) {
				if(!seen[z] && two_req[z] <= stars) {
					if(one_seen[z])
						stars++;
					else
						stars += 2;
					seen[z]=1;
					one_seen[z]=1;
					found = 1;
					//fprintf(stdout, "Get 2 stars on level %d. Have %d stars.\n",z,stars);
					break;
				}
			}
			if(found) {
				++y;//this level is done
				continue;
			}
			found = 0;
			int largest_2 = 0;
			int largest_index;
			for (z = 0; z < N; ++z) {
				if(!one_seen[z] && one_req[z] <= stars) {
					found = 1;
					if (two_req[z] > largest_2) {
						largest_2 = two_req[z];
						largest_index = z;
					}
				}
			}
			if(found) {
				stars += 1;
				one_seen[largest_index] = 1;
				//fprintf(stdout, "Get 1 star on level %d. Have %d stars.\n",largest_index,stars);
			}
			else {
				break;
			}
			one_count++;
		}

		if(found || N == 0) {
			printf("Case #%d: %d\n", i + 1, one_count + N);
			//fprintf(stdout, "Number of stars: %d\n", stars);
		}
		else {
			printf("Case #%d: Too Bad\n", i+1);
			//fprintf(stdout, "Number of stars: %d\n", stars);
		}
	}
}
