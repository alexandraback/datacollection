#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <list>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <list>

typedef long long ll;
typedef double dub;

using namespace std;

void runTest()
{
	int myMote;
	cin >> myMote;
	int otherNum;
	cin >> otherNum;
	int sizes[100];
	int numAdded[100];
	int totalAdded = 0;
	for(int i = 0;i < otherNum;i++)
	{
		cin >> sizes[i];
		numAdded[i] = 0;
	}
	sort(sizes, sizes + otherNum);
	
	
	for(int i = 0;i < otherNum;i++)
	{
		while(myMote <= sizes[i])
		{
			if(myMote <= 1)
			{
				cout << otherNum << endl;
				return;
			}
			numAdded[i]++;
			totalAdded++;
			myMote += myMote - 1;
		}
		myMote += sizes[i];
	}
	int best = totalAdded;
	int value = totalAdded;
	for(int i = otherNum - 1;i >= 0;i--)
	{
		value -= numAdded[i];
		value++;
		if(value < best)
		{
			best = value;
		}
	}
	cout << best << endl;
}


int main(int argc, const char * argv[])
{
	(void) argc;
	(void) argv;
	int numTests;
	cin >> numTests;
	srand(time(NULL));
	
	for(int i =0;i < numTests;i++)
	{
		cout << "Case #" << i + 1 << ": ";
		runTest();
	}
}
