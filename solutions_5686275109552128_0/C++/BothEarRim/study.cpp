#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <locale>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <climits>
#include <cfloat>
#include <map>
#include <functional>
using namespace std;
const double PI=acos(-1);

int ans, diner_N, pancake[1005], max_pancake;

int main() // Problem B. Infinite House of Pancakes
{
	freopen("B-small-attempt0.in.txt", "r", stdin);
	freopen("output_B_small.txt", "w", stdout);

	int tc_N;
	scanf("%d", &tc_N);
	for(int tc=0; tc<tc_N; tc++)
	{
		scanf("%d", &diner_N);
		max_pancake = 0; // 초기화
		for(int i=0; i<diner_N; i++)
		{
			scanf("%d", &pancake[i]);
			max_pancake = max(max_pancake, pancake[i]);
		}
		ans = max_pancake; // 최대값

		for(int goal=1; goal<max_pancake; goal++)
		{
			int cnt = 0;

			for(int i=0; i<diner_N; i++)
			{
				cnt += pancake[i]%goal ? pancake[i]/goal : pancake[i]/goal-1;
			}

			ans = min(ans, cnt+goal);
		}

		printf("Case #%d: %d\n", tc+1, ans);
	}

	fclose(stdin);
	fclose(stdout);
    
    return 0;
}