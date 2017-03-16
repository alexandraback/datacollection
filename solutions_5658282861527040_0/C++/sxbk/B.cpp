
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <algorithm>

#define			OK			std::cout << "------------" << std::endl;
#define			DEBUG(x)		std::cout << #x << " = " << x << std::endl;

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	for (int _ = 1;_ <= T;_ ++) {
		printf("Case #%d: ", _);
		int A, B, K;
		scanf("%d%d%d", &A, &B, &K);
		int ans = 0;
		for (int i = 0;i < A;i++) {
			for (int j = 0;j < B;j++) {
				if ( (i & j) < K ) {
					ans ++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

