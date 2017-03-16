//Standard libraries
#include <iostream>
#include <cstdio>
#include <cstdlib>
//Useful C libraries
#include <climits>
#include <cstring>
#include <cctype>
//Imp. STL data structures
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
//I/O fun
#include <sstream>
#include <fstream>
//Random
#include <algorithm>
//Debugging and misc.
#include <ctime>
#include <time>
//Math libraries
#include <ctgmath>
#include <random>
#include <cmath>
using namespace std;

int maxi = 0, t, k, l, s;
string keyboard, need;

void countsubstrings(string& A)
{
	int tmp = 0;
	for(int i = 0;i < int(A.size())-int(need.size());i++)
	{
		if(A.substr(i, i+int(need.size())) == need)
			tmp++;
	}	
	maxi = max(tmp, maxi);
}

void solver(string yet, int key)
{
	if(key == s)
	{
		countsubstrings(yet);
	}
	else
	{
		yet.append("U");
		for(int i = 0;i < int(keyboard.size());i++)
		{
			yet[int(yet.size())-1] = keyboard[i];
			solver(yet, key+1);
		}
	}
}

int main(void)
{
	scanf("%d", &t);
	string tmp;
	for(int rep = 1;rep <= t;rep++)
	{
		scanf("%d%d%d", &k, &l, &s);
		cin >> keyboard >> need;
		solver(tmp, 0);
		printf("Case #%d: %d\n", rep, maxi);
	}
}