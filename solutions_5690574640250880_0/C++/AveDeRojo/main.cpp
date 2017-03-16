#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <set>
#include <iomanip>
#include <cstdio>


using std::vector;
using std::ostream;
using std::istream;
using std::set;
using std::cout;

int R;
int C;

int xMove[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int yMove[8] = { 1, 0, -1, 1, -1, -1, 0, 1 };

bool isSafe(int x, int y, set<std::pair<int, int>> &sol)
{
	set<std::pair<int, int>>::iterator it = sol.find(std::make_pair(x,y));
	if (x >= 0 && x < R && y >= 0 && y < C && it == sol.end())
		return true;
	return false;
}

int checkNumber(set<std::pair<int, int>> &sol)
{
	using cordIter = set<std::pair<int, int>>::iterator;
	set<std::pair<int, int>> coords;
	for (cordIter it = sol.begin(), end = sol.end(); it != end; ++it)
	{
		for (int i = 0; i < 8; ++i)
		{
			std::pair<int, int> c = std::make_pair(it->first + xMove[i], it->second + yMove[i]);
			if (isSafe(c.first, c.second, sol))
			{
				coords.insert(c);
			}
		}
	}
	return coords.size() + sol.size();
}

set<std::pair<int, int>> take_coords(set<std::pair<int, int>> &sol)
{
	using cordIter = set<std::pair<int, int>>::iterator;
	set<std::pair<int, int>> coords;
	for (cordIter it = sol.begin(), end = sol.end(); it != end; ++it)
	{
		for (int i = 0; i < 8; ++i)
		{
			std::pair<int, int> c = std::make_pair(it->first + xMove[i], it->second + yMove[i]);
			if (isSafe(c.first, c.second, sol))
			{
				coords.insert(c);
			}
		}
	}

	for (cordIter it = sol.begin(), end = sol.end(); it != end; ++it)
	{
		std::pair<int, int> c = std::make_pair(it->first, it->second);
		coords.insert(c);
	}
	return coords;	
}

void printSolution(set<std::pair<int, int>> sol, std::ofstream& out, bool flag)
{
	vector<vector<int>> field(R);
	for (int i = 0; i < R; ++i)
	{
		field[i].assign(C, 1);
	}
	if (!flag)
	{
		using cordIter = set<std::pair<int, int>>::iterator;
		for (cordIter it = sol.begin(), end = sol.end(); it != end; ++it)
		{
			field[it->first][it->second] = 0;
		}

		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				if (i == 0 && j == 0)
					out << "c";
				else if (field[i][j] == 0)
					out << ".";
				else
					out << "*";
			}
			out << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				if (i == 0 && j == 0)
					out << "c";
				else
					out << "*";
			}
			out << std::endl;
		}
	
	}
}

bool solveKTUtil(int x, int y, set<std::pair<int, int>> &sol, int xMove[8],
	int yMove[8], int k)
{
	int i, next_x, next_y;
	int numb = checkNumber(sol);
	if (numb == k)
		return true;
	if (numb > k)
		return false;

	for (i = 0; i < 8; i++)
	{
		next_x = x + xMove[i];
		next_y = y + yMove[i];
		if (isSafe(next_x, next_y, sol))
		{
			sol.insert(std::make_pair(next_x, next_y));
			if (solveKTUtil(next_x, next_y, sol, xMove, yMove, k) == true)
				return true;
			else
				sol.erase(std::make_pair(next_x, next_y));
		}
	}
	return false;
}


bool solveKT(int k, set<std::pair<int, int>>& sol)
{
	std::pair<int, int> cords = std::make_pair(0, 0);
	sol.insert(cords);

	if (solveKTUtil(0, 0, sol, xMove, yMove, k) == false)
	{
		return false;
	}
	return true;
}

int main()
{
	std::ifstream in("C-small-attempt4.in");
	std::ofstream out("textOut.txt");
	int numberOfCases = 0;
	in >> numberOfCases;

	for (int i = 1; i < numberOfCases + 1; ++i)
	{
		int M = 0;
		in >> R >> C >> M;
		set<std::pair<int, int>> sol;
		bool flag = false;
		if (R * C - M == 1)
		{	
			flag = true;
		}
			
		if (solveKT(R * C - M, sol) || flag)
		{
			set<std::pair<int, int>> ans = take_coords(sol);
			out << "Case #" << i << ": " <<  std::endl;
			printSolution(ans, out, flag);
		}			
		else 
			out << "Case #" << i << ": " << std::endl << "Impossible" << std::endl;
	}
	system("pause");
	return 0;
}