// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
//#include <iostream>
//#include <complex>
//#include <numeric>
//#include <vector>
//#include <string>
//#include <cstdio>
//#include <queue>
//#include <cmath>
//#include <map>
//#include <set>
//#include <vector>
//#include <sstream>
//#include <iostream>
//#include <iterator>
//#include <unordered_map>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define clr(x) memset((x), 0, sizeof(x))

#define MAX 10000000
unsigned long long currentSize[MAX];
int currentIndex[MAX];
int currentChanges[MAX];
int motes[MAX];
int numPaths = 0;


void work()
{
	clr(currentIndex);
	clr(currentSize);
	clr(currentChanges);
	numPaths = 0;

	int numberOfMotes;
	scanf("%ld%d", &currentSize[numPaths], &numberOfMotes);

	REP(i, numberOfMotes)
		scanf("%d", &motes[i]);

	sort (motes, motes+numberOfMotes);

	int currentPath = 0;
	int maxPath = 0;
	do
	{
		for (auto i=currentIndex[currentPath]; i<numberOfMotes; i++)
		{
			auto m = motes[i];
			if (m < currentSize[currentPath])
			{
				//all good: keep going
				currentIndex[currentPath] = i;
				currentSize[currentPath] += m;
			}
			else
			{
				currentIndex[currentPath] = -1;
				

				//not good
				//2 options: add N motes until size >= this one
				//first option: add N motes until size >= this one
				if (currentSize[currentPath] > 1)
				{
					unsigned long long next = currentSize[currentPath] + currentSize[currentPath] - 1;
					int steps = 1;
					while(next < m)
					{
						steps++;
						next += next-1;
					}
					currentIndex[++maxPath] = i;
					currentSize[maxPath] = next;
					currentChanges[maxPath] = currentChanges[currentPath] + steps;
				}
				//2nd option: remove i
				currentIndex[++maxPath] = i+1;
				currentSize[maxPath] = currentSize[currentPath];
				currentChanges[maxPath] = currentChanges[currentPath] + 1;

				break;
			}

		}
	} while(currentPath++<maxPath);

	int min = MAX;
	REP(i, maxPath+1){
		if (currentIndex[i] >= numberOfMotes-1 &&
			currentChanges[i] < min)
			min = currentChanges[i];
	}
	printf("%d\n", min);
}


int _tmain(int argc, _TCHAR* argv[])
{
	//freopen("SampleData.in", "r", stdin);
	freopen("A-large (1).in", "r", stdin);
	freopen("A-large (1).out", "w", stdout);

	int tt;
	scanf("%d", &tt);
	REP(it, tt)
	{
		printf("Case #%d: ", it+1);

		work();
	}


	return 0;
}

