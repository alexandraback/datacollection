#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX_D 1000
#define MAX_P 1000

int pancakes[MAX_D];
int D;

int dinnerTime()
{
	int minTime(MAX_P);
	for (int p=1; p<=MAX_P; ++p)
	{
		int nSplits(0);
		for (int d=0; d<D; ++d)
			nSplits += (pancakes[d]-1) / p;
		minTime = min(minTime, nSplits + p);
	}
	return minTime;
}

void readCase()
{
	cin>>D;
	for (int i=0; i<D; ++i)
		cin>>pancakes[i];
}

int main()
{
	int T;
	cin>>T;
	for (int i=0; i < T; ++i)
	{
		readCase();
		cout<<"Case #"<<i+1<<": "<<dinnerTime()<<endl;
	}
	return 0;
}