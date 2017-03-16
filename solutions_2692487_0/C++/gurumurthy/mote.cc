#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

int getval(std::vector<int> &motes, long long motesize, int oval)
{
	long long sz = motesize;
	int index = -1;
	/*
	for(int j = 0; j < motes.size(); ++j)
		printf("%d ", motes[j]);
	printf("\n");
	*/
	for(int j = 0; j < motes.size(); ++j)
	{
		if(motes[j] >= sz)
		{
			index = j;
			break;
		}
		sz += motes[j];
	}
	if(index == -1)
	{
		return 0;
	}
	long long diff = motes[index]-sz;
	long long newsz = 2*sz-1;
	if(newsz == sz)
	{
		int val = motes.size()-index;
		if(val < oval)
			return val;
		return oval;
	}
	int oldindex = 1;
	while(1)
	{
		if(newsz > motes[index])
			break;
		oldindex++;
		//printf("%lld %d\n", newsz, oldindex);
		newsz = 2*newsz -1;
	}
	if(oldindex > motes.size()-index)
	{
		int val = motes.size()-index;
		if(val < oval)
			return val;
		return oval;
	}
	std::vector<int> temp;
	for(int j = index; j < motes.size(); ++j)
		temp.push_back(motes[j]);
	int val = oldindex+getval(temp, newsz, motes.size()-index);
	if(val < oval)
		return val;
	return oval;
}
int main()
{
	char str[128];
	fgets(str, 128, stdin);
	int ninputs = atoi(str);
	long long motesize;
	int nmotes;
	for(int i = 0; i < ninputs; ++i)
	{
		std::vector<int> motes;
		int t;
		fscanf(stdin, "%d %d", &t, &nmotes);
		motesize = t;
		for(int j = 0; j < nmotes; ++j)
		{
			int m;
			fscanf(stdin, "%d", &(m));
			motes.push_back(m);
		}
		std::sort(motes.begin(), motes.end());
		int val = getval(motes, motesize, motes.size());
		printf("Case #%d: %d\n", i+1, val);
	}
}
