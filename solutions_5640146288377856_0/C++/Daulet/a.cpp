#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// bool hit[11];

// int go(int C, int W, int remaining, int place, int last_hit, int steps, int player) 
// {
// 	if (remaining == 0) {
// 		return steps;
// 	}

// 	if (player == 1) {
// 		if (remaining < W) {

// 		} else {
// 			// not hit yet
// 			for (int i = W; i <= C; i += W) {
// 				if (!hit[i]) {
// 					hit[i] = true;
// 					go(C, W, remaining - 1, place, i, steps + 1, 0);
// 				}
// 			}
// 		}
// 	} else 
// 	if (player == 0) {
// 		if (last_hit)
// 	}
// }

// int search(int C, int W) 
// {
// 	return go(C, W, W, 0, 0, 1);
// }

int main()
{
	int T;
	scanf("%d\n", &T);

	for (int t = 1; t <= T; t++) {

		int R, C, W;
		scanf("%d %d %d\n", &R, &C, &W);

		int ans;

		if (W == 1) {
			ans = R*C;
		} else
		if (W == C) {
			ans = (R-1) + C;
		} else 
		if (C/W == 1) {
			ans = (R-1) + 1 + W;
		} else 
		if (C/W >= 2) {
			//ans = search(C, W);
			if (C%W == 0) { 
				ans = (R)*(C/W) - 1 + W;
			} else {
				ans = (R)*(C/W) + W;
			}
		}
	
		printf("Case #%d: %d\n", t, ans);
	}


	return 0;
}