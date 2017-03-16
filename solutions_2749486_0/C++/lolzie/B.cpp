#include<iostream>
#include<fstream>
#include<algorithm>
#include<math.h>
using namespace std;
ofstream out("B.txt");



int main()
{
	int tcases;
	long long x, y;
	char path[100000];
	cin>>tcases;
	int cases=1;
	while ( tcases-- )
	{
		cin>>x>>y;
		int hop=1;
		long long x1=0, y1=0;
		while ( x1!=x )
		{
			if ( abs(long (x - x1))>=hop )
			{
				if ( x>x1 ) { x1+=hop; path[hop-1]='E'; }
				else { x1-=hop; path[hop-1]='W';}
			}
			else
			{
				if ( x>x1 ) { x1-=hop; path[hop-1]='W'; }
				else { x1+=hop; path[hop-1]='E'; }
			}
			hop++;
		}
		while ( y1!=y )
		{
			if ( abs(long(y-y1))>=hop )
			{
				if ( y>y1 ) { y1+=hop; path[hop-1]='N'; }
				else { y1-=hop; path[hop-1]='S';}
			}
			else
			{
				if ( y>y1 ) { y1-=hop; path[hop-1]='S'; }
				else { y1+=hop; path[hop-1]='N'; }
			}
			hop++;
		}
		path[hop-1]='\0';	
		out<<"Case #"<<cases<<": "<<path<<endl;
		cases++;
	}

	return 0;
}
