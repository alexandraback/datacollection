#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;
#define re return
#define LL long long
#define EPS 0.00000000000001
#define MOD 1000000009
#define INF 1000000000000000000LL
#define L 16
#define NEED 50
#define BASE_BOUND 11
#define PRIMES_SET_BOUND 1023
//#define PRIMES_SET_BOUND 2147483648

int lp[PRIMES_SET_BOUND + 1];
vector<int> primes;

typedef struct{
	char s[L];
	bool b[L];
	int proves[BASE_BOUND];
}tJamCoin;
int T;

bool tryGetJamCoin(tJamCoin & result)
{
	for (int i = 1; i + 1 < L; ++i)
	{
		result.b[i] = rand() % 2;
	}
	result.b[0] = 1;
	result.b[L - 1] = 1;
	for (int base = 2; base < BASE_BOUND; ++base)
	{
		bool bOK = false;
		for (int divizor : primes)
		{
			LL rest = 0;
			for (int i = 0; i < L; ++i)
			{
				rest = (rest*base) % divizor;
				rest = (rest + result.b[i]) % divizor;
			}
			if (rest == 0)
			{
				bOK = true;
				result.proves[base] = divizor;
				break;
			}
		}
		if (!bOK)
		{
			return false;
		}
	}
	for (int i = 0; i < L; ++i)
	{
		result.s[i] = '0' + result.b[i];
	}
	result.s[L] = 0;
	return true;
}

int main()
{
#ifdef _DINARISIO
	ifstream cin("B-large.in");
	ofstream cout("A.out");
#endif

	for (int i = 2; i <= PRIMES_SET_BOUND; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			primes.push_back(i);
		}
		for (int j = 0; j < (int)primes.size() && primes[j] <= lp[i] && i*primes[j] <= PRIMES_SET_BOUND; ++j)
		{
			lp[i * primes[j]] = primes[j];
		}
	}
	
	cout << "Case #1:"<<endl;
	set<LL>was;
	for (int cnt = 0; cnt < NEED;)
	{
		tJamCoin jamCoin;
		if (tryGetJamCoin(jamCoin))
		{
			LL cur = 0;
			for (int i = 0; i < L; ++i)
			{
				cur <<= 1;
				cur |= jamCoin.b[i];
			}
			if (was.find(cur) != was.end()) continue;
			was.insert(cur);

			cout << jamCoin.s;
			for (int i = 2; i < BASE_BOUND; ++i)cout << " " << jamCoin.proves[i];
			
			cout << endl;
			cnt++;
		}
	}
	re 0;
}