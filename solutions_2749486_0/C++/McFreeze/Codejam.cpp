// Mike Terranova
// Google Code Jam 2013
// Using Visual Studio 2012
// May 12, 2013

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <functional>
#include <utility>

using namespace std;

int caseNumber;

void writeOutput(string output)
{
	cout << "Case #" << caseNumber << ": " << output << endl;
}

// return true if should go on X axis. else return false
bool chooseXY(int distX, int distY, int step)
{
	// can get it on this turn?
	if (distX == step) return true;
	if (distY == step) return false;

	// can get it on next turn?
	if (distX == step + 1) return false;
	if (distY == step + 1) return true;

	int nextX = distX - step;
	int nextY = distY - step;
	
	return nextX < nextY;
}

bool goPositiveAxis(int cur, int dest, int step)
{
	if (cur + step == dest) return true;
	if (cur - step == dest) return false;

	int plus = cur + step;
	int minus = cur - step;

	int plusDist = dest - plus;
	int minusDist = dest - minus;

	// by plussing you get to finish on the next step
	if (abs(plusDist) == step + 1)
	{
		return true;
	}

	// by minussing you get to finish on the next step
	else if (abs(minusDist) == step + 1)
	{
		return false;
	}

	else if (abs(plusDist) == 1)
	{
		return true;
	}

	else if (abs(minusDist) == 1)
	{
		return false;
	}

	// get as close as possible
	else if (abs(plusDist) >= step && abs(minusDist) >= step)
	{
		return abs(plusDist) < abs(minusDist);
	}

	// it's less than half of the step away? go farther away
	else if (abs(dest - cur) < step / 2)
	{
		// if we are past the step, keep going past it
		return cur > step;
	}

	else
	{
		// go towards it
		return step > cur;
	}
}

void testCase(int x, int y)
{
	string moveList = "";

	int currentX = 0;
	int currentY = 0;

	int distanceToX = x;
	int distanceToY = y;

	bool foundX = false;
	bool foundY = false;

	// this algorithm is good enough to get there in 500 moves

	for (int i = 1; !foundX || !foundY; i++)
	{
		// go towards the one we are closest to.
		if (!foundX && (foundY || chooseXY(abs(distanceToX), abs(distanceToY), i)))
		{
			if (goPositiveAxis(currentX, x, i))
			{
				if (distanceToX == i)
				{
					foundX = true;
				}

				moveList.append("E");
				currentX += i;
				distanceToX -= i;
				continue;
			}
			else
			{
				if (-distanceToX == i)
				{
					foundX = true;
				}

				moveList.append("W");
				currentX -= i;
				distanceToX += i;
				continue;
			}
		}
		else
		{
			if (goPositiveAxis(currentY, y, i))
			{
				if (distanceToY == i)
				{
					foundY = true;
				}

				moveList.append("N");
				currentY += i;
				distanceToY -= i;
				continue;
			}
			else
			{
				if (-distanceToY == i)
				{
					foundY = true;
				}

				moveList.append("S");
				currentY -= i;
				distanceToY += i;
				continue;
			}
		}
	}

	writeOutput(moveList);
}

int main()
{
	int numberOfCases;
	cin >> numberOfCases;

	for (caseNumber = 1; caseNumber <= numberOfCases; caseNumber++)
	{
		int x, y;
		cin >> x >> y;

		testCase(x, y);
	}

	return 0;
}
