#pragma warning(disable: 4996)
#include <string>
#include <cctype>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <memory.h>
#include <assert.h>
using namespace std;

// BrattleShip
/*
int Calculate(int r, int c, int w)
{
	int numOfShip = c / w;
	int rem = c%w;
	if (rem == 0)
	{
		return r*numOfShip + w - 1;
	}
	else
	{
		return r*numOfShip + w;
	}
}


int main(void)
{
//	freopen("A-small-attempt0 (1).in", "r", stdin);
 	freopen("A-large (1).in", "r", stdin);
// 	freopen("1.txt", "r", stdin);
	freopen("Alarge.out", "w", stdout);
	int nTest;

	scanf("%d", &nTest);
	for (int i = 0; i < nTest; i++)
	{
		int r, c, w;
		scanf("%d %d %d", &r, &c, &w);
		cout << "Case #" << i + 1 << ": " << Calculate(r, c, w) << endl;

	}

	return 1;
}

*/


//Typewriter Monkey

/*
map<char, int> kbd;
string target;

double Calculate(int	k, int tar, int s)
{

	return 1.0;
}

int main(void)
{
	//	freopen("A-small-attempt0 (1).in", "r", stdin);
	// 	freopen("A-large (1).in", "r", stdin);
	freopen("1.txt", "r", stdin);
	freopen("1.out", "w", stdout);
	int nTest;

	scanf("%d", &nTest);
	for (int i = 0; i < nTest; i++)
	{
		kbd.clear();
		int k, tar, s;
		scanf("%d %d %d", &k, &tar, &s);
		char tmp;
		scanf("%c", &tmp); //the return char
		for (int keys = 0; keys < k ; keys++)
		{
			scanf("%c", &tmp);
			if (kbd.find(tmp) == kbd.end())
			{
				kbd[tmp] = 1;
			}
			else
				kbd[tmp]++;
		}
		char buf[128];
		scanf("%s", buf);
		target.assign(buf);


		cout << "Case #" << i + 1 << ": " << Calculate(k, tar, s) << endl;

	}

	return 1;
}

*/

// Less Money

int Allcoins[12];


int Calculate(int deno, int val)
{

	int b = 0;
	Allcoins[deno] = val;

	int biggest = Allcoins[0];
	for (int i = 1; i < deno+1 ; i++)
	{
		biggest = max(biggest, Allcoins[i] - Allcoins[0]);
	}

	while (biggest)
	{
		biggest = biggest / 2;
		b++;
	}

	int added = 0;
	for (int j = 0; j <= b ; j++)
	{
		int tar = pow(2, j);
		bool found=false;
		for (int i = 0; i < deno; i++)
		{
			if (Allcoins[i]  == tar)
			{
				found = true;
				break;
			}
		}
		if (found == false)
		{
			added++;
		}
	}



	return added;
}

int main(void)
{
	//	freopen("A-small-attempt0 (1).in", "r", stdin);
	// 	freopen("A-large (1).in", "r", stdin);
	freopen("C-small-attempt2.in", "r", stdin);
	//freopen("1.txt", "r", stdin);
	freopen("csmall2.out", "w", stdout);
	int nTest;

	scanf("%d", &nTest);
	for (int i = 0; i < nTest; i++)
	{

		int k, deno, val;
		scanf("%d %d %d", &k, &deno, &val);

		for (int coins = 0; coins < deno; coins++)
		{
			scanf("%d", Allcoins+coins);
		}



		cout << "Case #" << i + 1 << ": " << Calculate(deno, val) << endl;

	}

	return 1;
}