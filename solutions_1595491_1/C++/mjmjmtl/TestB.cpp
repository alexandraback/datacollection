// TestB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <algorithm>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("B-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int idx = 1; idx <= n; idx ++) {
		int t, s, p, arr[110];
		scanf("%d%d%d", &t, &s, &p);
		int ok = 0, not = 0, uncertain = 0;
		for(int i = 0; i < t; i ++) {
			scanf("%d", arr+i);
			if(arr[i] >= 3*p-2) {
				ok ++;
			} else if(arr[i] <=3*p-5) {
				not ++;
			} else {
				uncertain ++;
			}
		}
		int ans;
		if(p == 0) {
			ans = t;
		} else if(p == 1) {
			ans = 0;
			for(int i = 0; i < t; i ++) {
				if(arr[i]) {
					ans ++;
				}
			}
		} else {
			ans = ok + min(uncertain, s);
		}
		printf("Case #%d: %d\n", idx, ans);


	}

	return 0;
}

