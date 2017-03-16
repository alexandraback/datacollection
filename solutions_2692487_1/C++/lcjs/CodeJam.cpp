#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int min(int a, int b)
{
	if(a<b) return a;
	return b;
}

// Return minimum number of additions or removals needed from here
int sol(int A, deque<int> sizes)
{
	if(sizes.size()==0) return 0;
	// Absorb as many as possible
	while(sizes.size()>0 && A > sizes.front())
	{
		A+=sizes.front();
		sizes.pop_front();
	}
	if(sizes.size()==0) return 0;
	if(sizes.size()==1) return 1;

	// If we're not done, then either we add one just big enough to be absorbed,
	// or we delete the rest
	
	if(A==1) return sizes.size();

	return min(sizes.size(), sol((2*A)-1, sizes) + 1);

	
}



int main(int argc, char ** argv)
{
	int T;
	scanf("%d", &T);

	deque<int> sizes;
	for(int t = 1; t<=T;t++)
	{
		// Read sizes
		int A,N;
		scanf(" %d %d,", &A, &N);
		sizes.clear();
		for(int i = 0;i<N;i++)
		{
			int store;
			scanf(" %d", &store);
			sizes.push_back(store);
		}

		sort(sizes.begin(), sizes.end());

		printf("Case #%d: %d\n", t, sol(A, sizes));



	}
	return 0;
}