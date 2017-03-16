#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

int T;
int r, c, m;

int main()
{
	ifstream fin("C-small-attempt1.in");
	ofstream fout("c.out");
	fin >> T; 
	for(int t=1; t<=T; ++t)
	{
		fout << "Case #" << t << ":" << endl;
		fin >> r >> c >> m;
		m = r*c-m;
		
		if (r == 1 || c == 1)
		{
			for(int i=0; i<r; ++i)
			{
				for(int j=0; j<c; ++j)
					if (i+j ==0)
						fout << 'c';
					else if (i+j < m)
						fout << '.';
					else 
						fout << '*';
				fout << endl;
			}
			continue;	
		}
		if (m==1)
		{
			for(int i=0; i<r; ++i)
			{
				for(int j=0; j<c; ++j)
					if (i+j ==0)
						fout << 'c';
					else
						fout << '*';
				fout << endl;
			}
			continue;	
		}
		
		
		
		bool revise = false;
		
		int current = c;
		int x =m/current;
		while (x<2 && current > 1)
		{
			--current;
			x = m/current;	
		}

		int y = m % current;
		if (y==1)
		{
			if (x == 2)
			{
				--current;
				y+=2;
			}
			else 
			{
				++y;
				revise = true;	
			}
		}
		if (x==1 || current == 1 || y>current|| (y==current && revise))
		{
			fout << "Impossible" << endl;
			continue;	
		}		
		
		
		
		if ((y==0?0:1)+x > r || y > c)
		{
			fout << "Impossible" << endl;
			continue;	
		}
		
		for(int i=0; i<r; ++i)
		{
			for(int j=0; j<c; ++j)
			{
				if (i==0 && j==0)
				{
					fout << 'c';
					continue;	
				}
				if ((i<x && j<current) || (i==x && j < y))
				{
					if (revise && (i == x-1) && (j == current-1))
						fout << '*';
					else
						fout << '.';
				}
				else 
					fout << '*';
			}
			fout << endl;
		}
		
	}
	fin.close();
	fout.close();
}
