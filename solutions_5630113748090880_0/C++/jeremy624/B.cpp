#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

int t,n,i,j,ans[105][105],a[105][105],temp[105],c[105][2];
bool used[105];

int main(){
	scanf("%d", &t);
	int testcase = 0;
	while(++testcase <= t){
		memset(ans, 0, sizeof(ans));
		memset(temp, 0, sizeof(temp));
		memset(used, 0, sizeof(used));
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		for(i = 0; i < 2 * n - 1; i++){
			for(j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
		}
		int tar;
		for(int ii = 0; ii < n; ii++){
			int minx = 5005;
			for(i = 0; i < 2 * n - 1; i++){
				if(used[i]) continue;
				minx = min(minx, a[i][ii]);
			}
			int cnt = 0;
			for(i = 0; i < 2 * n - 1; i++){
				if(used[i]) continue;
				if(a[i][ii] == minx)
				cnt++;
			}
			if(cnt == 1){
				for(i = 0; i < 2 * n - 1; i++){
					if(used[i]) continue;
					if(a[i][ii] == minx){
						for(j = 0; j < n; j++)
						temp[j] = a[i][j];
						used[i] = 1;
					}
				}
				tar = ii;
			}
			else{
				for(i = 0; i < 2 * n - 1; i++){
					if(used[i]) continue;
					if(a[i][ii] == minx){
						used[i] = 1;
					}
				}
			}
		}
		memset(used, 0, sizeof(used));
		for(int ii = 0; ii < n; ii++){
			int minx = 5005;
			for(i = 0; i < 2 * n - 1; i++){
				if(used[i]) continue;
				minx = min(minx, a[i][ii]);
			}
			int cnt = 0;
			for(i = 0; i < 2 * n - 1; i++){
				if(used[i]) continue;
				if(a[i][ii] == minx)
				cnt++;
			}
			if(cnt == 1){
				for(i = 0; i < 2 * n - 1; i++){
					if(used[i]) continue;
					if(a[i][ii] == minx){
						for(j = 0; j < n; j++)
						temp[j] = a[i][j];
						used[i] = 1;
					}
				}
			}
			else{
				int ind = 0;
				for(i = 0; i < 2 * n - 1; i++){
					if(used[i]) continue;
					if(a[i][ii] == minx){
						c[ii][ind++] = a[i][tar];
						used[i] = 1;
					}
				}
			}
		}
		printf("Case #%d: ", testcase);
		for(i = 0; i < n; i++){
			int val = 0;
			if(i == tar)
			val = temp[tar];
			else{
				if(c[i][0] == temp[i])
				val = c[i][1];
				else
				val = c[i][0];
			}
			if(i == 0)
			printf("%d", val);
			else
			printf(" %d", val);
		}
		printf("\n");
	}
}

