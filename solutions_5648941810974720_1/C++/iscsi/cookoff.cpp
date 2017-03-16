#include <string>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <cassert>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <stack>

using namespace std;
typedef long long LL;
#define FOR(k,a,b) for(int k(a); k < (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ABS(a) ((a)>0?(a):-(a))
#define pb push_back



int main(int argv, char** argc) {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
// 	freopen("in.txt", "r", stdin);
// 	freopen("A-small-attempt0.out", "w", stdout);
	const char* ABC[10] = {
		"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
	};
	// Z, *, W, *, U, *, X,S,
	// X - 6
	// Z - 0
	// W - 2
	// U - 4
	// S - 7
	// O - 1
	// R - 3
	// V - 5
	// G - 8
	// 
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	char cc1[2300];
	FOR(tc, 1, T + 1)
	{
		int ctr = 0;
		scanf("%s", cc1);
		vector<int> w(30);
		REP(i,strlen(cc1))
		{
			w[cc1[i] - 'A']++;
			++ctr;
		}
		vector<int> r(10);
		while (ctr)
		{
			if (w['X' - 'A'])
			{
				int act = 6;
				r[act]++;
				REP(i, strlen(ABC[act]))
				{
					w[ABC[act][i] - 'A']--;
				}
				continue;
			}
			if (w['Z' - 'A'])
			{
				int act = 0;
				r[act]++;
				REP(i, strlen(ABC[act]))
				{
					w[ABC[act][i] - 'A']--;
				}
				continue;
			}
			if (w['W' - 'A'])
			{
				int act = 2;
				r[act]++;
				REP(i, strlen(ABC[act]))
				{
					w[ABC[act][i] - 'A']--;
				}
				continue;
			}
			if (w['U' - 'A'])
			{
				int act = 4;
				r[act]++;
				REP(i, strlen(ABC[act]))
				{
					w[ABC[act][i] - 'A']--;
				}
				continue;
			}
			if (w['S' - 'A'])
			{
				int act = 7;
				r[act]++;
				REP(i, strlen(ABC[act]))
				{
					w[ABC[act][i] - 'A']--;
				}
				continue;
			}
			if (w['O' - 'A'])
			{
				int act = 1;
				r[act]++;
				REP(i, strlen(ABC[act]))
				{
					w[ABC[act][i] - 'A']--;
				}
				continue;
			}
			if (w['R' - 'A'])
			{
				int act = 3;
				r[act]++;
				REP(i, strlen(ABC[act]))
				{
					w[ABC[act][i] - 'A']--;
				}
				continue;
			}
			if (w['V' - 'A'])
			{
				int act = 5;
				r[act]++;
				REP(i, strlen(ABC[act]))
				{
					w[ABC[act][i] - 'A']--;
				}
				continue;
			}
			if (w['G' - 'A'])
			{
				int act = 8;
				r[act]++;
				REP(i, strlen(ABC[act]))
				{
					w[ABC[act][i] - 'A']--;
				}
				continue;
			}
			if (w['N' - 'A'])
			{
				int act = 9;
				r[act]++;
				REP(i, strlen(ABC[act]))
				{
					w[ABC[act][i] - 'A']--;
				}
				continue;
			}
			
			REP(i, w.size())
			{
				if(w[i])
				{
					int alma = 42;
				}
			}
			break;
		}
		printf("Case #%d: ", tc);
		REP(i, 10)
		{
			REP(j, r[i])
				printf("%d", i);
		}
		printf("\n");
	}
	return 0;
}