#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <utility>

#define MN 200
#define MS 2000000

using namespace std;

int numbers[MN];
int expectedSum[MS];


void printMask(int mask, int n)
{
	bool first=true;
	for(int i=n-1; i>=0; i--)
	{
		int bit=1<<i;
		if((mask&bit)==bit)
		{
			if(!first)
				printf(" ");
			printf("%d", numbers[n-i-1]);
			first=false;
		}
	}
	puts("");
}
int getSum(int mask, int n)
{
	int sum = 0;
	for(int i=n-1; i>=0; i--)
	{
		int bit=1<<i;
		if((mask&bit)==bit)
			sum+=numbers[n-i-1];
	}
	return sum;
}
int main()
{
	int t, n;
	scanf("%d", &t);
	for(int c=1; c<=t; c++)
	{
		//init
		memset(expectedSum, 0, sizeof(expectedSum));
		//
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", numbers+i);
		sort(numbers, numbers+n);

		int maxN = 1<<20;
		set<int> S;
		printf("Case #%d:\n", c);
		for(int i=maxN-1; i>=0; i--)
		{
			int sum = getSum(i, n);
			if(S.find(sum)!=S.end())
			{
				printMask(expectedSum[sum], n);
				printMask(i, n);
				break;
			}
			else
			{
				S.insert(sum);
				expectedSum[sum]=i;
			}
		}
	}
	return 0;
}
