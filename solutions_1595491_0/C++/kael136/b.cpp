#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bitset>
#include <sstream>
using namespace std;



int main()
{
	string a, b;
	fstream in_f, out_f;
	int t, s, p,n;
	in_f.open("B-small-attempt4.in", fstream::in);
	out_f.open("b.out", std::ios_base::binary | std::ios_base::out );

	in_f >> t;

	
	for(int i = 1; i <= t; i++)
	{
		int count = 0;
		in_f >> n;
		in_f >> s;
		in_f >> p;
		for (int j = 1; j <= n; j++)
		{
			int triplet;
			in_f >> triplet;
			
			if ((triplet / 3) >= p)
			{
				count++;
			}
			else if ((triplet/3) == p-1)
			{
				if (p-1 > 0)
				{
					if ((triplet%3) > 0)
					{
						count++;
					}
					else
					{
						if (s > 0)
						{
							count++;
							s--;
						}
					}
				}
				else // triplet < 3, p = 1
				{
					if(triplet != 0)
					{
						count++;
					}
				}
			}
			else if ((triplet/3) == p-2)
			{
				if (p-2 > 0)
				{
					if ((triplet%3) == 2)
					{
						if (s > 0)
						{
							count++;
							s--;
						}
					}
				}
				else // p = 2, triplet < 3
				{
					if (triplet == 2)
					{
						if ( s > 0)
						{
							count++;
							s--;
						}
					}
				}
			}
		}

		out_f << "Case #" << i << ": " << count << endl;
	}
	return 0;
}