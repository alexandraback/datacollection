#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

int t;
int a, b, k;

int main() {
	//assert(freopen("input.txt","r",stdin));
	//assert(freopen("output.txt","w",stdout));     

	scanf("%d", &t);

	for (int tn = 1; tn <= t; tn++) {
		scanf("%d %d %d", &a, &b, &k);

		int ans = 0;

		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++) 
				if ((i & j) < k)
					ans++;

		printf("Case #%d: %d\n", tn, ans);

	}

	return 0;
}