/* Problem B */
#include<iostream>

using namespace std;

typedef unsigned long long ull;

unsigned long long testcase( int x, int y )
{
	int curX=0, curY=0;
	int step = 1;
	int stepAbs = 1;
			
	while( curY != y )
	{
		curY+=step;
		if( step > 0 ) cout << "N";
		else cout << "S";
		stepAbs++;
		if( step>0)
			step = -stepAbs;
		else
			step = stepAbs;
	}

	if( x < curX )
	{
		if( step < 0 )
			step = -step;
	}
	else
	{
		if( step > 0 )
			step = -step;
	}

	while( curX != x )
	{
		curX+=step;
		if( step > 0 ) cout << "E";
		else cout << "W";
		stepAbs++;
		if( step>0)
			step = -stepAbs;
		else
			step = stepAbs;
	}

	cout << endl;
	return 0;
}

int main()
{
	int T;
	scanf_s("%d",&T);

	for(int i=1; i<=T;i++)
	{
		int x,y;
		scanf_s("%d %d",&x,&y);

		printf("Case #%d: ",i);
		testcase(x,y);
	}

	return 0;
}