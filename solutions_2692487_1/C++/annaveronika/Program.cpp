#ifdef DEBUG_OUTPUT
#include "debug_output.h"
#else
#define DEBUG(x)
#endif

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <cstdio>
#include <cassert>
#include <math.h>
using namespace std;


// Enlarge MSVS stack size
#pragma comment(linker, "/STACK:16777216")

#define pb push_back
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define sz(x) static_cast<int>(x.size())
typedef long long int64;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

template<class T> T sqr(const T& t) {return t * t;}
template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}

void initialize()
{
    freopen("_.in", "r", stdin);
    freopen("_.out", "w", stdout);
	std::ios_base::sync_with_stdio (false);
}

void input(int& asin, vector<int>& notes)
{
	cin >> asin;
	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int note;
		cin >> note;
		notes.push_back(note);
	}
}

void output()
{

}

int GetMinNotes(int asin, vector<int>& notes, int begin)
{
	if (asin == 1)
		return notes.size();


	if (begin == notes.size())
		return 0;

	int K = 0;

    while (notes[begin] >= asin)
	{
		asin += asin - 1;
		K++;
	}

	asin += notes[begin];

	int rest = notes.size() - begin;
	int changes = K + GetMinNotes(asin, notes, begin + 1);

	return min(rest, changes);
}

int main()
{
	initialize();

	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int asin;
		vector<int> notes;
		input(asin, notes);
		sort(notes.begin(), notes.end());

		int result = GetMinNotes(asin, notes, 0);
		cout << "Case #" << i + 1 << ": " << result << endl;
		output();
	}

	return 0;
}

