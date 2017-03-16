#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <utility>
#define MAX 1005

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		int N;
		scanf("%d", &N);
		int used[MAX];
		int c1[MAX], c2[MAX];
		for (int i = 0; i < MAX; i++)
			used[i] = 0;
		for (int i = 0; i < N; i++)
			scanf("%d%d", &c1[i], &c2[i]);
		int req = 0;
		int stars = 0;
		while(true){
			int sel = -1;
			for (int i = 0; i < N; i++)
				if(used[i] < 2){
					if(sel == -1)
						sel = -2;
					if(c2[i] <= stars){
						sel = i;
						break;
					}
					if(used[i] == 0 && c1[i] <= stars && (sel < 0 || c2[i] > c2[sel]))
						sel = i;
				}
			if(sel == -1)
				break;
			if(sel == -2){
				req = -1;
				break;
			}
			if(c2[sel] <= stars){
				stars += 2 - used[sel];
				req++;
				used[sel] = 2;
			}
			else{
				stars++;
				req++;
				used[sel] = 1;
			}
		}
		printf("Case #%d: ", t);
		if (req == -1)
			printf("Too Bad\n");
		else
			printf("%d\n", req);
	}
	return 0;
}
