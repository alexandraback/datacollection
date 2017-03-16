#include <cstdio>
#include <algorithm>

const int MAX = 111;


int N;
int my;
int mote0[MAX];

int main(){
	for(int T, t = (scanf("%d", &T), 1); t <= T; t++){
		scanf("%d %d", &my, &N);
		for(int i = 0; i < N; i++){
			scanf("%d", mote0 + i);
		}
		std::sort(mote0, mote0 + N);
		if(my <= 1){
			int ans = 0;
			for(int i = 0; i < N; i++){
				if(my <= mote0[i]){
					ans++;
				}else{
					my += mote0[i];
				}
			}
			printf("Case #%d: %d\n", t, ans);
		}else{
			int ans = 2147483647;
			int add = 0;
			for(int i = 0; i < N; i++){
				if(add + (N  - i) < ans){
					ans = add + (N - i);
				}
				if(my <= mote0[i]){
					//printf("i = %d my = %d, %d\n", i, my, mote0[i]);
					while(my <= mote0[i]){
						my += (my - 1);
						add++;
					}
				}
				my += mote0[i];
			}	
			if(add < ans){
				ans = add;
			}
			printf("Case #%d: %d\n", t, ans);
		}
	}
	return 0;
}
