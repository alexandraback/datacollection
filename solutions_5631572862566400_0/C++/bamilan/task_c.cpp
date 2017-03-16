//#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORI(i, a, n) for(int i = (int)(a); i < (int)(n); i++)



int n;
int arr[1010];
std::vector<bool> visited;




int searchSnakePreferredEnd(int start, std::vector<bool> tempVisited, std::vector<int> ends)
{
	int size = 1;

	int first = start;
	int current = start;
	int last = start;
	int next = arr[current];

	tempVisited[start] = true;

	while (next != first && next != last && !tempVisited[next])
	{
		last = current;
		int temp = arr[next];
		current = next;
		next = temp;
		tempVisited[current] = true;

		size++;
	}

	FOR(i, ends.size())
	{
		if (next == ends[i]) return size;
	}

	return 0;
}


int searchClosedCycle(int start, std::vector<bool> tempVisited)
{
	int size = 1;

	int first = start;
	int current = start;
	int last = start;
	int next = arr[current];

	tempVisited[start] = true;

	while (next != first && next != last && !tempVisited[next])
	{
		last = current;
		int temp = arr[next];
		current = next;
		next = temp;
		tempVisited[current] = true;

		size++;
	}

	if (next == start)
	{
		return size;
	}

	return 0;
}


int searchOpenCycle(int start, std::vector<bool> tempVisited)
{
	int size = 1;

	int first = start;
	int current = start;
	int last = start;
	int next = arr[current];

	tempVisited[start] = true;

	while (next != first && next != last && !tempVisited[next])
	{
		last = current;
		int temp = arr[next];
		current = next;
		next = temp;
		tempVisited[current] = true;

		size++;
	}

	if (next == last)
	{
		return size;
	}

	return 0;
}



int tryIt()
{
	visited.clear();
	visited.reserve(n + 5);
	FOR(i, n + 5) visited.push_back(false);


	// search the longest complete cycle
	int longestClosedCycle = 0;
	FOR(i, n)
	{
		int c = searchClosedCycle(i, visited);
		if (c > longestClosedCycle) longestClosedCycle = c;
	}


	// search for open cycles
	int totalLength = 0;
	std::vector<std::vector<int>> cycles;
	std::vector<int> openEnds;

	int best = 0;
	int bestIndex = -1;
	bool found = true;

	while (found)
	{
		best = 0;
		bestIndex = -1;

		FOR(i, n)
		{
			if (!visited[i])
			{
				int c = searchOpenCycle(i, visited);
				if (c > best)
				{
					best = c;
					bestIndex = i;
					found = true;
				}
			}
		}

		if (best > 0)
		{
			totalLength += best;
			std::vector<int> tempVec;

			int current = bestIndex;
			while (!visited[current])
			{
				tempVec.push_back(current);
				visited[current] = true;
				current = arr[current];
			}
			cycles.push_back(tempVec);
		}
		else
		{
			found = false;
		}
	}


	FOR(i, (int)cycles.size())
	{
		if (cycles[i].size() == 2)
		{
			openEnds.push_back(cycles[i][0]);
			openEnds.push_back(cycles[i][1]);
		}
		else
		{
			openEnds.push_back(cycles[i][(int)cycles[i].size() - 1]);
		}
	}

	if (openEnds.size() == 0) return longestClosedCycle;
	

	// need to search longest sequences with ending in any of the preferred nodes
	best = 0;
	bestIndex = -1;
	found = true;

	while (found)
	{
		best = 0;
		bestIndex = -1;

		FOR(i, n)
		{
			if (!visited[i])
			{
				int c = searchSnakePreferredEnd(i, visited, openEnds);
				if (c > best)
				{
					best = c;
					bestIndex = i;
					found = true;
				}
			}
		}

		if (best > 0)
		{
			totalLength += best;

			int current = bestIndex;
			while (!visited[current])
			{
				visited[current] = true;
				current = arr[current];
			}

			openEnds.push_back(bestIndex);
			FOR(i, (int)openEnds.size()) if (openEnds[i] == current) openEnds[i] = -1;
		}
		else
		{
			found = false;
		}
	}

	return totalLength;
}


int main()
{
	//freopen("C-small-attempt0.in", "r", stdin);
	//freopen("C-small-attempt0.out", "wb", stdout);

	int numOfTestcases;
	std::cin >> numOfTestcases;

	FOR(i, numOfTestcases)	// IRD VISSZA NUMOFTESTCASESRE
	{
		std::cout << "Case #" << (i + 1) << ": ";		// KOMMENTEZD VISSZA

		std::cin >> n;

		int temp;
		FOR(i, n)
		{
			std::cin >> temp;
			arr[i] = temp - 1;
		}
		
		std::cout << tryIt() << std::endl;
	}

	return 0;
}