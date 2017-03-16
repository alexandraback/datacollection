#include <assert.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;



int main() {
	int cases;
	cin >> cases;
	for (int t = 1; t <= cases; t++)
	{
		int x, y, k;
		cin>>x>>y>>k;
		int sum = 0;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++){
				if ((i & j) < k) {
					sum ++;
				}
			}
		}
		printf("Case #%d: %d\n", t, sum);
	}
	return 0;
}