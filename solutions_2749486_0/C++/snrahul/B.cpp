#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>
#include <list>
#include <deque>
#include <map>
#include <bitset>
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;

int main()
{
	int n;
	ifstream in("B-small-attempt0.in");
	ofstream out("output.out");
	in >> n;
	for(int cases = 1; cases <= n; cases++)
	{
		long long x,y,ix=0,iy=0,pogo=1;
		in>>x>>y;
		out << "Case #" << cases << ": ";
		while(ix!=x)
		{
			if(x>0)
			{
				ix += pogo;
				if(ix>x)
				{
					ix -= 2*pogo;
					out << "W";
				}
				else
				{
					out << "E";
				}
			}
			else
			{
				ix -= pogo;
				if(ix<x)
				{
					ix += 2*pogo;
					out << "E";
				}
				else
				{
					out << "W";
				}
			}
			pogo++;
		}
		while(iy!=y)
		{
			if(y>0)
			{
				iy += pogo;
				if(iy>y)
				{
					iy -= 2*pogo;
					out << "S";
				}
				else
				{
					out << "N";
				}
			}
			else
			{
				iy -= pogo;
				if(iy<y)
				{
					iy += 2*pogo;
					out << "N";
				}
				else
				{
					out << "S";
				}
			}
			pogo++;
		}
		out << endl;
	}
	system("pause");
	return 0;
}