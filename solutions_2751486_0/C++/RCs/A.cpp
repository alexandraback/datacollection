#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

void solver(int numCase)
{
	char strings[1000];
	int consec, result = 0, now, i, j, length, k, answer = 0, ctr;

	scanf("%s %i", strings, &consec);
	length = strlen(strings);
	for(i = consec; i <= length; i++)
	{
		for(j = 0; j <= length - i; j++)
		{
			result = 0;
			for(ctr = 0, k = j; ctr < i; k++, ctr++)
			{
				if(strings[k] == 'a' || strings[k] == 'e' || strings[k] == 'u' || strings[k] == 'i' ||
					strings[k] == 'o')
					result = 0;
				else
					result++;

				if(result >= consec)
				{
					answer++;
					break;
				}
			}

			
		}
	}

	printf("Case #%i: %i\n", numCase, answer);
}

int main()
{
	int numCase, cases;
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%i", &cases);
	for(numCase = 1; numCase <= cases; numCase++)
		solver(numCase);

	return 0;
}