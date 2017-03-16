#include <stdio.h>
int n,pancake[1001],remain[1001];
bool check(int time){
	for(int sp=0; sp<time; sp++){
		int eat_time = time-sp, cnt=0;
		for(int i=0;i<n;i++){
			cnt += (pancake[i]+eat_time-1)/eat_time-1;
		}
		if(cnt<=sp)
			return true;
	}
	return false;
}
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int testt;
	scanf("%d",&testt);
	for(int test=1; test<=testt; test++){
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d",&pancake[i]);
		int low=0, high=1005, mid, print;
		while(low<=high){
			mid = (low+high)>>1;
			if(check(mid)){
				print=mid;
				high=mid-1;
			}
			else
				low=mid+1;
		}
		printf("Case #%d: %d\n",test,print);
	}
	return 0;
}
