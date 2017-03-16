#include <cstdio>
#include <set>
#include <utility>
#include <queue>
#include <string>

using namespace std;

#define MAX_LEN 30

void getSolution(int curX, int curY, int X, int Y, string & solution);

int main(void)
{
	int T, caseId, X, Y;
	string solution, cur;

	scanf("%d", &T);
	caseId = 1;

	while(caseId <= T)
	{
		scanf("%d %d", &X, &Y);

		solution = "";
		getSolution(0, 0, X, Y, solution);

		printf("Case #%d: %s\n", caseId, solution.c_str());
		caseId++;
	}
	return 0;
}

void getSolution(int curX, int curY, int X, int Y, string & solution)
{
	int numMove = 1;

	bool west = false;
	if(curX > X)
	{
		if(curX - numMove < X)
			west = false;
		else
			west = true;
		
	}
	else
	{
		if(curX + numMove > X)
			west = true;
		else
			west = false;
	}	

	while(curX != X)
	{
		if(west)
		{
			west = false;
			curX -= numMove;
			solution += 'W';
		}
		else
		{
			west = true;
			curX += numMove;
			solution += 'E';
		}

		numMove++;
	}

	bool down = false;
	if(curY > Y)
	{
		if(curY - numMove < Y)
			down = false;
		else
			down = true;
		
	}
	else
	{
		if(curY + numMove > Y)
			down = true;
		else
			down = false;
	}	
	while(curY != Y)
	{
		if(down)
		{		
			curY -= numMove;
			solution += 'S';
			down = false;
		}
		else
		{
			down = true;
			curY += numMove;
			solution += 'N';
		}

		numMove++;
	}


}
