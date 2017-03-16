#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

#define MR 2010
char s[MR];

string t[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
int ord[10] = { 0,2,4,6,8,3,5,7,9,1 };

int pos[MR];

string go()
{
	multiset < char > M;
	int n = strlen(s), pom = 0;
	int itr = 0;
	memset(pos, 0, sizeof(pos));
	while (pom < n)
	{
		REP(i, 10)
		{
			while (true)
			{
				itr++;
				int wsk = 0;
				REP(k, t[ord[i]].length())
				{

					REP(j, n)
						if (s[j] == t[ord[i]][wsk] && !pos[j])
						{
							wsk++;
							pos[j] = itr;
							break;
						}
				}
				if (wsk == t[ord[i]].length())
				{
					M.insert(ord[i] + '0');
					pom += t[ord[i]].length();
				}
				else
				{
					REP(j, n) if (pos[j] == itr) pos[j] = 0;
					break;
				}
			}
		}
	}

	string res = "";
	for (auto it = M.begin(); it != M.end(); it++) res += *it;

	return res;
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(c, T)
	{
		scanf("%s", s);
		printf("Case #%d: %s\n", c + 1, go().c_str());
	}
	return 0;
}