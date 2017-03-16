#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
using namespace std;
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt","w",stdout);
	int T, N, a[1001], b[1001], state[1001], i, j, k, pos, max_star2, star_add, re;
	int finish_count;
	scanf("%d", &T);
	int cur_star;
	for (i = 1; i <=T; i++) {
		scanf("%d", &N);
		if (i == 6 )
			finish_count = 0;
		for (j = 0; j < N; j++)
			scanf("%d%d", &a[j], &b[j]);
		finish_count = 0;
		cur_star = 0;
		for (j = 0; j < N; j++)
			state[j] = 0;
		re = 0;
		while (finish_count < N) {
			max_star2 = -1;
			pos = -1;
			
			for (j = 0; j < N; j++) {
				if (state[j] == 2) continue;
				else if (state[j] == 1) {
					if (b[j] <= cur_star) {
						pos = j;
						break;
					}
				} else {
					if (b[j] <= cur_star) {
						pos = j;
						break;
					}else if (a[j] <= cur_star && b[j] > max_star2) {
						pos = j;
						max_star2 = b[j];
					}
				}
			}
			if (pos != -1) {
				if (b[pos] <= cur_star) {
					if (state[pos] == 1) {
						state[pos] =2;
						cur_star += 1;
					} else {
						state[pos] = 2;
						cur_star += 2;
					}
					finish_count++;
				} else {
					state[pos] = 1;
					cur_star += 1;
				}
				re++;
			} else {
				break;
			}
		}
		if (finish_count == N) printf("Case #%d: %d\n", i, re);
		else printf("Case #%d: Too Bad\n", i);
	}
	return 0;
}