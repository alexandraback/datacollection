
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <unordered_map>


using namespace std;


char str[2000000];
int f [2000000];
int main()
{
	freopen("input.txt","rt", stdin);
	freopen("output.txt","wt", stdout);			
	int tests;
	scanf("%d\n", &tests);
	for (int test = 1; test <= tests; test++)
	{
		int x, y;
		scanf("%d%d", &x, &y);		
		printf("Case #%d: ",test);		
		while (x != 0)
		{
			if (x < 0)
			{
				printf("EW");
				x++;
			}
			else
			{
				printf("WE");
				x--;
			}
		}

		while (y != 0)
		{
			if (y < 0)
			{
				printf("NS");
				y++;
			}
			else
			{
				printf("SN");
				y--;
			}
		}
		printf("\n");

	}
		
	return 0;			
}     
