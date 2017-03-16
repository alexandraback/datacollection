#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <queue>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

void solver(int numCase)
{
	int x, y, idxData = 0, posX = 0, posY = 0, move, gap, k;
	char data[1000];

	scanf("%i %i", &x, &y);
	move = 1;
	while(!(posX == x && posY == y))
	{
		if(posX < x && posX + move <= x)
		{
			posX += move;
			data[idxData++] = 'E';
			move++;
		}
		else if(posX < x && posX + move > x)
		{
			gap = abs(x - posX);
			for(k = 0; k < gap; k++)
			{
				data[idxData++] = 'W';
				data[idxData++] = 'E';
				move += 2;
			}					
			posX = x;
		}
		else if(posX > x && posX - move >= x)
		{
			posX -= move;
			data[idxData++] = 'W';
			move++;
		}
		else if(posX > x && posX - move < x)
		{
			gap = abs(posX - x);
			for(k = 0; k < gap; k++)
			{
				data[idxData++] = 'E';
				data[idxData++] = 'W';
				move += 2;
			}
			posX = x;
		}
		else if(posY < y && posY + move <= y)
		{
			posY += move;
			data[idxData++] = 'N';
			move++;
		}
		else if(posY < y && posY + move > y)
		{
			gap = abs(y - posY);
			for(k = 0; k < gap; k++)
			{
				data[idxData++] = 'S';
				data[idxData++] = 'N';
				move += 2;
			}	
			posY = y;
		} 		
		else if(posY > y && posY - move >= y)
		{
			posY -= move;
			data[idxData++] = 'S';
			move++;
		}
		else if(posY > y && posY - move < y)
		{
			gap = abs(posY - y);
			for(k = 0; k < gap; k++)
			{
				data[idxData++] = 'N';
				data[idxData++] = 'S';
				move += 2;
			}	
			posY = y;
		}
		
	}
	data[idxData] = 0;

	printf("Case #%i: %s\n", numCase, data);
}

int main()
{
	int numCase, cases;
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%i", &cases);
	for(numCase = 1; numCase <= cases; numCase++)
		solver(numCase);

	return 0;
}