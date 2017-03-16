#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <deque>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

void run(int cas){
	int n;
	scanf("%d", &n);
	int a[1000];
	for (int i = 0; i < n; ++i){
		int y;
		scanf("%d", &y);
		a[i] = y;
	}
//	for (int i = 0; i < n; ++i){
//		printf("%d ", a[i]);
//	}

	printf("Case #%d:\n", cas);
	for (ll i = 1; i < (1 << 20); ++i){
		int s = 0;
		for(int j = 0; j < 20; ++j){
			if (i & (1 << j)){
				s += a[j];
			}
		}
		for (int j = i + 1; j < (1 << 20); ++j){
			int curr_sum = 0;
			for (int k = 0; k < 20; ++k){
				if (j & (1 << k)){
					curr_sum += a[k];
				}
			}
			if (curr_sum == s){

				for(int f = 0; f < 20; ++f){
					if (i & (1 << f)){
						printf("%d ", a[f]);
					}
				}
				printf("\n");
				for(int f = 0; f < 20; ++f){
					if (j & (1 << f)){
						printf("%d ", a[f]);
					}
				}
				printf("\n");
				return;
			}
		}
	}
	printf("Impossible\n");
}

int main(){
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		run(i + 1);
	}
}
