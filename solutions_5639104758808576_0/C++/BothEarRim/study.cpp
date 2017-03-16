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

int maxShy, need_tot, tot;
char ipt[1005];

int main() // Problem A. Standing Ovation
{
	freopen("A-small-attempt0.in.txt", "r", stdin);
	freopen("output_A_small.txt", "w", stdout);

	int tc_N;
	scanf("%d", &tc_N);
	for(int tc=0; tc<tc_N; tc++)
	{
		scanf("%d %s", &maxShy, ipt);
		tot = ipt[0]-'0';
		need_tot = 0; // 초기화

		for(int i=1; i<=maxShy; i++)
		{
			if(tot < i)
			{
				need_tot += i-tot;
				tot += i-tot;
			}

			tot += ipt[i]-'0';
		}

		printf("Case #%d: %d\n", tc+1, need_tot);
	}

	fclose(stdin);
	fclose(stdout);
    
    return 0;
}