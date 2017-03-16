#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

typedef long long lint;

using namespace std;

int main(int argc, char ** argv)
{
	int ntest;

	scanf("%d", &ntest);
	
	for (int test = 0; test < ntest; test++) {
		int n, s, p;
		
		scanf("%d %d %d", &n, &s, &p);
		
		int n1 = 0, n2 = 0;

		for (int i = 0; i < n; i++) {
			int tot;
			scanf("%d", &tot);

			int ok1 = 0;
			for (int a = 0; a <= tot; a++)
				for (int b = max(0, a-1); b <= a+1; b++) {
					int c = tot-a-b;
					if (c >= 0 && abs(b-c) <= 1 && abs(a-c) <= 1 && max(a, max(b, c)) >= p) ok1 = 1;
				}
			
			if (ok1) {
				n1 ++;
			} else {
				int ok2 = 0;
				for (int a = 0; a <= tot; a++)
					for (int b = max(a-2, 0); b <= a+2; b++) {
						int c = tot-a-b;
						if (c >= 0 && abs(b-c) <= 2 && abs(a-c) <= 2 && max(a, max(b, c)) >= p) ok2 = 1;
					}				
				if (ok2) {n2++;}
				
			}
		}

		printf("Case #%d: %d\n", test+1, n1 + min(n2, s));
	}

	return 0;
}
