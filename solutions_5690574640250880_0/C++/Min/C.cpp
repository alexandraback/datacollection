// CodeJam 2014
// Autor: Benjamín de la Fuente Ranea

#include <stdarg.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

#include <Windows.h>

using namespace std;

#include "BigIntegerLibrary.hh"

#define FILE_INPUT	"C-small-attempt2"
//#define FILE_INPUT	"C"

struct Problem
{
	int		r, c, m;
	bool	minimum;

};

Problem reduceProblem(Problem _p)
{
	if (_p.c > 3 && _p.c - _p.r >= 0 && _p.m >= _p.r)
		return reduceProblem({_p.r, _p.c - 1, _p.m - _p.r, false});
	else if (_p.r > 3 && _p.m >= _p.c)
		return reduceProblem({_p.r - 1, _p.c, _p.m - _p.c, false});
	else
	{
		_p.minimum = true;
		return _p;
	}
}

void printHSolution(const Problem& _pOrig)
{
	printf("%s%sc\n", string(_pOrig.m, '*').c_str(), string(_pOrig.c - _pOrig.m - 1, '.').c_str());
}

void printVSolution(const Problem& _pOrig)
{
	for (int i = 0; i < _pOrig.m; ++i)
		printf("*\n");

	for (int i = 0; i < _pOrig.r - _pOrig.m - 1; ++i)
		printf(".\n");

	printf("c\n");
}

void printFullSolution(const Problem& _pOrig)
{
	for (int i = 0; i < _pOrig.r - 1; ++i)
		printf("%s\n", string(_pOrig.c, '*').c_str());

	printf("%sc\n", string(_pOrig.c-1, '*').c_str());
}

void printSolution(const Problem& _pOrig, const Problem& _p)
{
	for (int i = 0; i < _pOrig.r - _p.r; ++i)
		printf("%s\n", string(_pOrig.c, '*').c_str());

	int minesLeft = _p.m;
	for (int i = _pOrig.r - _p.r; i < _pOrig.r - 2; ++i)
	{
		printf("%s", string(_pOrig.c - _p.c, '*').c_str());
		int numMines = min(minesLeft, _p.c);
		if (numMines > 0 && numMines == _p.c - 1)
			--numMines;

		if (numMines > 0)
		{
			minesLeft -= numMines;
			printf("%s", string(numMines, '*').c_str());
		}
		else
			numMines = 0;
		printf("%s\n", string(_p.c - numMines, '.').c_str());
	}

	printf("%s", string(_pOrig.c - _p.c, '*').c_str());
	int numMines = min(minesLeft, _p.c-2);
	if (numMines > 0)
	{
		minesLeft -= numMines;
		printf("%s", string(numMines, '*').c_str());
	}
	else
		numMines = 0;
	printf("%s\n", string(_p.c - numMines, '.').c_str());

	printf("%s", string(_pOrig.c - _p.c, '*').c_str());
	numMines = min(minesLeft, _p.c-2);
	if (numMines > 0)
	{
		minesLeft -= numMines;
		printf("%s", string(numMines, '*').c_str());
	}
	else
		numMines = 0;
	printf("%sc\n", string(_p.c-numMines-1, '.').c_str());

	if (minesLeft != 0)
		DebugBreak();
}

void main()
{
	freopen(FILE_INPUT".in", "r", stdin);
	freopen(FILE_INPUT".out", "w", stdout);

	unsigned numCases;
	scanf("%d\n", &numCases);
	for (unsigned i = 1; i <= numCases; ++i)
	{
		int R, C, M;
		scanf("%d %d %d\n", &R, &C, &M);

		printf("Case #%d:\n", i);

		const Problem pOrig = {R, C, M, false};
		if (pOrig.r == 1)
			printHSolution(pOrig);
		else if (pOrig.c == 1)
			printVSolution(pOrig);
		else if (pOrig.m == pOrig.c * pOrig.r - 1)
			printFullSolution(pOrig);
		else
		{
			const Problem p = reduceProblem(pOrig);
			if (p.r == 3 && p.c == 3 && (p.m == 2 || p.m == 4))
				printf("Impossible\n");
			else if ((p.r == 2 || p.c == 2) && p.m == 1)
				printf("Impossible\n");
			else if (p.m <= p.r*p.c - 4)
				printSolution(pOrig, p);
			else
				printf("Impossible\n");
		}
	}
}
