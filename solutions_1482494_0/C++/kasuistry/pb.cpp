
#include <cstdio>

int main(){
	
	int t; scanf("%d", &t);
	int s[1000][3];

	for(int testcase=1; testcase<=t; ++testcase){
		int n; scanf("%d", &n);
		for(int i=0; i<n; ++i){
			scanf("%d %d", &s[i][0], &s[i][1]);
			s[i][2] = 2;
		}
		int swap;
		for(int i=0; i<n; ++i){
			for(int j=i+1; j<n; ++j){
				if(s[i][1] < s[j][1]){
					swap = s[i][1]; s[i][1] = s[j][1]; s[j][1] = swap;
					swap = s[i][0]; s[i][0] = s[j][0]; s[j][0] = swap;
				}
			}
		}
		int crnt = 0, goal = 2*n, times = 0;
		
		while(crnt < goal){
			
			if(s[n-1][1] <= crnt){
				crnt += s[n-1][2];
				-- n;
				++ times;
				continue;
			}

			int found = 0;

			for(int i=0; i<n; ++i){
				if(s[i][0] <= crnt && s[i][2] == 2){
					-- s[i][2];
					++ crnt;
					found = 1;
					++ times;
					break;
				}
			}
			if(found){
				continue;
			}else{
				break;
			}
		}

		printf("Case #%d: ", testcase);
		if(crnt == goal){
			printf("%d\n", times);
		}else{
			printf("Too Bad\n");
		}
	}
	return 0;
}
