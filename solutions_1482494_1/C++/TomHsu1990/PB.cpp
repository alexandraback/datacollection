#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define SIZE 1010
using namespace std;
bool level1[SIZE], level2[SIZE];
struct point{
	int a, b;
};
struct point p[SIZE];
int t, n;
bool cmp(struct point x, struct point y){
	if(x.b > y.b) return true;
	else if(x.b == y.b){
		if(x.a < y.a) return true;
		else		  return false;
	}
	else		  return false;
}
int greedy(){
	bool check = false;
	int total = 0, cnt = 0;
	while(true){
		int record = -1;
		for(int i=0;i<n;++i){
			if(!level2[i] && total >= p[i].b && !level1[i]){
				level1[i] = level2[i] = true;
				total += 2;
				record = i;
				break;
			}
		}
		for(int i=0;record == -1 && i<n;++i){
			if(!level2[i] && total >= p[i].b && level1[i]){
				level2[i] = true;
				total += 1;
				record = i;
				break;
			}
		}
		for(int i=0;record == -1 && i<n;++i){
			if(!level1[i] && total >= p[i].a){
				level1[i] = true;
				total += 1;
				record = i;
				break;
			}
		}
		
		if(record == -1) break;
		else{
			++cnt;
		
			int find_more = 0;
			for(int i=0;i<n;++i)
				if(level2[i])
					++find_more;
			if(find_more == n){
				check = true;
				break;
			}
		}
	}
	
	if(check) return cnt;
	else	  return -1;
}
int main(){
	scanf("%d", &t);
	for(int i=1;i<=t;++i){
		scanf("%d", &n);
		for(int j=0;j<n;++j){
			scanf("%d%d", &p[j].a, &p[j].b);
			level1[j] = false;
			level2[j] = false;
		}
		sort(p, p+n, cmp);
		int r = greedy();
		if(r == -1) printf("Case #%d: Too Bad\n", i);
		else		printf("Case #%d: %d\n", i, r);
	}
	return 0;
}
