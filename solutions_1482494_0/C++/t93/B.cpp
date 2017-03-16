#include <iostream>

using namespace std;

const int MAX = 1000;
int req1[MAX];
int req2[MAX];
int done[MAX];

int n;
int stars;
int moves;

bool do2()
{
	bool changed = false;
	for (int i = 0; i < n; i++)
	{
		if (stars >= req2[i] && done[i] != 2)
		{
			stars += 2 - done[i];
			moves++;
			done[i] = 2;
			changed = true;
		}
	}
	return changed;
}

bool do1()
{
	int best = -1;
	int bestScore = -1;

	for (int i = 0; i < n ; i++)
	{
		if (done[i] == 0 && stars >= req1[i] && req2[i] > bestScore)
		{
			bestScore = req2[i];
			best = i;
		}
	}

	if (best == -1) return false;

	stars++;
	done[best] = 1;
	moves++;
	return true;
}

int main()
{
	int cases;
	cin >> cases;

	for (int c = 0; c < cases; c++)
	{
		cin >> n;
		stars = 0;
		moves = 0;
		for (int i = 0; i < n; i++)
		{
			done[i] = 0;
			cin >> req1[i] >> req2[i];
		}

		while (stars < 2 * n)
		{
			while (do2());
			if (!do1()) break;
		}

		cout << "Case #" << c + 1 << ": ";

		if (stars != 2 * n)
		{
			cout << "Too Bad" << "\n";
		}
		else
		{
			cout << moves << "\n";
		}
	}
}
