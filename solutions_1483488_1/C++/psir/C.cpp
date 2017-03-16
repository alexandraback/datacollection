#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

char buff[10000];

int A, B;



int main()
	{

	int T;
	gets(buff);
	sscanf(buff,"%d",&T);

	for( int t = 0 ; t< T; ++t )
		{
		int sol = 0;
		gets(buff);
		sscanf(buff,"%d %d",&A,&B);

		int ndig = 0;
		int b = B;
		while( b )
			{b/=10; ++ndig;}
		int pow10 = 1;
		for( int i = 0; i < ndig; ++i )
			pow10 *=10;

		for( int i = A; i <= B; ++i )
			{
			int x = i;
			for( int t = 10; t <= x; t*= 10)
				{
				int y = x / t + (x%t)*(pow10/t);
				if( y > x && y >= A && y <= B)
					{
					++sol;
					//cout << x << " " << y << endl;
					}
				}
			}
		printf("Case #%d: %d\n",t+1,sol);
		}

	return 0;
	}
