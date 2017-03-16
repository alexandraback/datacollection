#include <stdlib.h>
#include <iostream>
using namespace std;

int X, L, W;

bool hasSolution(int X, int L, int W)
{
	static int unsolved(0);
	
	if (X>L)			// high aspect-ratio piece
		return false;
		
	if ((X+1)/2 > W)	// low aspect-ratio piece
		return false;
		
	if (X>6)			// X-omino with X>6 can have holes
		return false;
			
	if (X<4)			// X-ominos with X<4 cannot split the field
		return ((L*W) % X) == 0;
	
	if ((X+1)/2 == W)	// field can be split in two by low aspect-ratio piece
	{
		switch (X)
		{
			case 4:				// T-piece creates odd number of boxes
				return false; 
			case 5:				// all splits can be made symmetrical
				return ((L*W) % X) == 0;
			case 6:				// h-piece forces a 1-difference between boxes of the two parts
				return false;
		}
	}
	
	return ((L*W) % X) == 0;
}

void readCase()
{
	cin>>X>>L>>W;
	if (W>L)
		swap(L,W);
}

int main()
{
	int T;
	cin>>T;
	for (int i=0; i < T; ++i)
	{
		readCase();
		if (hasSolution(X, L, W))
			cout<<"Case #"<<i+1<<": GABRIEL"<<endl;
		else
			cout<<"Case #"<<i+1<<": RICHARD"<<endl;
	}
#if 0
	for (int X=1; X<=20; ++X)
		for (int L=1; L<=20; ++L)
			for (int W=1; W<=L; ++W)
				hasSolution(X, L, W);
#endif
	return 0;
}