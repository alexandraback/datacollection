#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cassert>

using namespace std;

const int maxN = 1000005, maxTurns = 1005;

inline int getRange (int turn) { return turn * (turn + 1) / 2; }

bool reachable (int x, int y, int range)
{
	x = abs (x);
	y = abs (y);

	if (x + y > range) return false;
	if ((x + y) % 2 != range % 2) return false;

	return true;
}

char answer[maxTurns];

void solve (int x, int y, int caseNumber)
{
	int sum = abs (x) + abs (y);
	double approximate = sqrt (2 * sum);
	int from = max ((int)approximate - 100, 0), to = max ((int)approximate + 100, 0);

	int turns = 0;
	bool reach = false;

	for (turns = from; turns <= to; turns++)
	{
		int r = getRange (turns);
		if (reachable (x, y, r))
		{
			reach = true;
			break;
		}
	}

	if (!reach) { printf ("Failure! Point %i %i not reachable\n", x, y); assert (!"Failure");  }

	int fx = x, fy = y;

	int answerTurns = turns;
	answer[turns] = 0;
	while (turns >= 0)
	{
		char turn = 0;
		int range = getRange (turns - 1);

		if (reachable (x, y - turns, range)) { turn = 'N'; y -= turns; }
		else if (reachable (x, y + turns, range)) { turn = 'S'; y += turns; }
		else if (reachable (x - turns, y, range)) { turn = 'E'; x -= turns; }
		else if (reachable (x + turns, y, range)) { turn = 'W'; x += turns; }
		else { printf ("Failure! Point %i %i not reachable in %i turns\n", x, y, turns); assert (!"Failure"); }

		turns--;
		answer[turns] = turn;
	}
	assert (x == 0 && y == 0);

	printf ("Case #%i: %s\n", caseNumber, answer);

	for (int i = 0; i < answerTurns; i++)
	{
		if (answer[i] == 'N') y += i + 1;
		else if (answer[i] == 'S') y -= i + 1;
		else if (answer[i] == 'E') x += i + 1;
		else if (answer[i] == 'W') x -= i + 1;
		else assert (!"Failure");
	}

	assert (x == fx && y == fy);
	fprintf (stderr, "Case #%i: solved in %i turns\n", caseNumber, answerTurns);
}

int main()
{
	int nTests;
	scanf ("%i", &nTests);

	for (int i = 0; i < nTests; i++)
	{
		int x, y;
		scanf ("%i %i", &x, &y);
		solve (x, y, i + 1);
	}

	return 0;
}