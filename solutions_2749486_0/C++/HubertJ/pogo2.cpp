#include <cstdio>
#include <math.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <cassert>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;



int main(int argc, char *argv[])
{
	int c, cases;
	cin >> cases;
	
	for(c = 1; c <= cases; c++)
	{
		int x, y;
		cin >> x;
		cin >> y;

		string s;
		int curX = 0;
		int curY = 0;

		for (int i = 1; i <= 500; i++)
		{
			if (curX == x && curY == y)
				break;

			string nextDir = "0";
			if (i == abs(curX-x))
			{
				if (x > curX)
				{
					nextDir = "E";
					curX+=i;
				}
				else
				{
					nextDir = "W";
					curX-=i;
				}
			}
			else if (i == abs(curY-y))
			{
				if (y > curY)
				{
					nextDir = "N";
					curY+=i;
				}
				else
				{
					nextDir = "S";	
					curY-=i;
				}
			}

			if (nextDir != "0")
			{
				s.append(nextDir);
				continue;
			}

			if (i < abs(curX-x))
			{
				if (x > curX)
				{
					nextDir = "E";
					curX+=i;
				}
				else
				{
					nextDir = "W";
					curX-=i;
				}
			}
			else if (i == abs(curY-y))
			{
				if (y > curY)
				{
					nextDir = "N";
					curY+=i;
				}
				else
				{
					nextDir = "S";	
					curY-=i;
				}
			}

			if (nextDir != "0")
			{
				s.append(nextDir);
				continue;
			}

			if (curX != x)
			{
				int diff = abs(curX - x);
				if (x > curX)
				{
					for (int j = 0; j < diff; j++)
					{
						s.append("WE");
						curX+=1;
						i+=2;
					}
					i--;
				}
				else
				{
					for (int j = 0; j < diff; j++)
					{
						s.append("EW");
						curX-=1;
						i+=2;
					}
					i--;
				}
			}
			else
			{
				int diff = abs(curY - y);
				if (y > curY)
				{
					for (int j = 0; j < diff; j++)
					{
						s.append("SN");
						curY+=1;
						i+=2;
					}
					i--;
				}
				else
				{
					for (int j = 0; j < diff; j++)
					{
						s.append("NS");
						curY-=1;
						i+=2;
					}
					i--;
				}
			}

			//s.append(nextDir);
		}
		
		cout << "Case #" << c << ": " << s << endl;
	}
}

