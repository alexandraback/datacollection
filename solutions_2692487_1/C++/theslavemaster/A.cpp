#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <list>
#include <queue>
using namespace std;
static const int SIZE = 1e7;

char sieve[SIZE];

int main(int argc, char const *argv[])
{
	int t=0;
	scanf("%d\n", &t);
	for(int iter= 0; iter<t; iter++)
	{
		int n=0, a=0;
		scanf("%d%d\n", &a, &n);
		vector<int> arr;
		for (int i = 0; i < n; ++i)
		{
			int temp;
			scanf("%d\n", &temp);
			arr.push_back(temp);
		}
		sort(arr.begin(), arr.end());
		int minCount = 999999999;
		int count = 0;
		int curSize =a;
		bool flag = false;
		int i;
		for( i=0; i<arr.size(); i++)
		{
			if(arr[i] < curSize)
				curSize += arr[i];
			else
			{
				flag = true;
				minCount = min((int)minCount, count + (int)arr.size() - i);
				if(curSize == 1)
				{
					count = minCount;
					break;
				}
				while(curSize <= arr[i])
				{
					// printf("here\n");
					curSize += curSize-1;
					count++;
				}
				curSize += arr[i];
			}
		}
		minCount = min(minCount, count);
		printf("Case #%d: %d\n", iter+1, minCount);
		
			
	}
	
	return 0;
}