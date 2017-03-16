#include<cmath>
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<fstream>
#include<set>
#include<map>
using namespace std;

int main()
{
	ifstream in ("B-small-attempt0.in");
	int t, x, y, cnt = 0;
	in >> t;
	for (int z = 1; z <= t; ++ z)
	{
		cnt = 0;
		cout << "Case #" << z << ": ";
		int locx = 0, locy = 0;
		in >> x >> y;
		int i;
		for (i = 1; i <= 500; ++ i)
		{
			if(x == locx && locy == y)
				break;
			if (abs(y) == i){
				if (y > 0)
					cout << 'N';
				else
					cout << 'S';
				locy = y;
				continue;
			}
			if (abs(locx - x) == i){
				if (x - locx > 0){
					cout << 'E';
					locx += i;
				}
				else{
					locx -= i;
					cout << 'W';
				}
				continue;
			}
			else if (abs(locx - x) < i){
				if(locx < x){
					cout << 'W';
					locx -= i;
				}
				else
				{
					cout << 'E';
					locx += i;
				}
			}
			else
			{
				if(locx > x){
					cout << 'W';
					locx -= i;
				}
				else
				{
					cout << 'E';
					locx += i;
				}	
			}
		}
		cout << endl;
	}
	return 0;
}
