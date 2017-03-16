#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	int cases;
	cin >> cases;

	for(int i=1; i<=cases; i++)
	{
		string coders, jammers;
		cin >> coders >> jammers;

		int bestDiff;
		string bestCoders = coders;
		string bestJammers = jammers;
		for(size_t x=0; x<bestCoders.size(); x++)
		{
			if(bestCoders[x] == '?')
			{
				bestCoders[x] = '0';
			}
			if(bestJammers[x] == '?')
			{
				bestJammers[x] = '0';
			}
		}
		bestDiff = abs(atoi(&bestCoders[0]) - atoi(&bestJammers[0]));

		for(size_t cNum = 0; cNum <= 999; cNum++)
		{
			string cGuess = to_string(cNum);
			string jGuess;
			while(cGuess.size() < coders.size())
			{
				cGuess = "0" + cGuess;
			}

			bool canTry = true;
			for(size_t x=0; x<cGuess.size(); x++)
			{
				if(coders[x] != '?')
				{
					if(coders[x] != cGuess[x])
					{
						canTry = false;
					}
				}
			}
			if(!canTry)
			{
				continue;
			}

			for(size_t jNum = 0; jNum <= 999; jNum++)
			{
				jGuess = to_string(jNum);
				while(jGuess.size() < coders.size())
				{
					jGuess = "0" + jGuess;
				}

				bool canTry = true;
				for(size_t x=0; x<jGuess.size(); x++)
				{
					if(jammers[x] != '?')
					{
						if(jammers[x] != jGuess[x])
						{
							canTry = false;
						}
					}
				}
				if(!canTry)
				{
					continue;
				}

				int curDiff = abs(atoi(&cGuess[0]) - atoi(&jGuess[0]));
				if(curDiff < bestDiff)
				{
					bestDiff = curDiff;
					bestCoders = cGuess;
					bestJammers = jGuess;
				}
				else if(curDiff == bestDiff)
				{
					if(cGuess < bestCoders)
					{
						bestCoders = cGuess;
						bestJammers = jGuess;
					}
					else if(cGuess == bestCoders)
					{
						if(jGuess < bestJammers)
						{
							bestJammers = jGuess;
						}
					}
				}

			}

		}


		cout << "Case #" << i << ": " << bestCoders << " " << bestJammers << endl;
	}

	return 0;
}
