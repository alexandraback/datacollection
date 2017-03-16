#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <vector>
#include <stack>
#include <string>
#include <queue>
  
using namespace std;
  
#define ABS(a) (((a) > 0)? (a): -(a))
#define Min(a, b) (((a) < (b))? (a): (b))
#define Max(a, b) (((a) < (b))? (b): (a))
#define MFOR(i, a, n) for (int i = (a); i < (n); i++)
#define FOR(i, a, n) for (int i = (a); i <= (n); i++)
#define DFOR(i, a, n) for (int i = (a); i >= (n); i--)
#define SQR(a) (a) * (a)
#define All(a) (a).begin(), (a).end()
#define PI 3.1415926535897932384626433832795
#define MEMS(a, b) memset((a), (b), sizeof(a))
#define MP make_pair
#define PB push_back
#define endl '\n'
#define LL long long
#define UN unsigned
#define Or ||
#define And &&
/////////////////////////////////////////////

int best;
int bestmask;
int J, P, S, K;
int JP[22][22], JS[22][22], PS[22][22];
int ON;

int prepJ[33], prepP[33], prepS[33];

void prep(int x)
{
	int on = 0;
	while (x)
	{
		if (x & 1)
		{
			int j, p, s;
			prepJ[on] = 1 + on / P / S;
			prepP[on] = 1 + (on / S) % P;
			prepS[on] = 1 + on % S;
		}
		x >>= 1;
		on++;
	}
}

void curia(int x)
{
	int on = 0;
	while (x)
	{
		if (x & 1)
		{
			int j, p, s;
			j = prepJ[on];
			p = prepP[on];
			s = prepS[on];
			JP[j][p] = 0;
			JS[j][s] = 0;
			PS[p][s] = 0;
		}
		x >>= 1;
		on++;
	}
}

bool check(int x)
{
	int y = x;
	int on = 0;
	while (y)
	{
		on += (y & 1);
		y >>= 1;
	}
	if (on <= best)
		return false;
	ON = on;

	on = 0;
	while (x)
	{
		if (x & 1)
		{
			int j, p, s;
			j = prepJ[on];
			p = prepP[on];
			s = prepS[on];
			JP[j][p]++;
			JS[j][s]++;
			PS[p][s]++;
			
			if (JP[j][p] > K Or JS[j][s] > K Or PS[p][s] > K)
				return false;
		}
		x >>= 1;
		on++;
	}
	return true;
}

void solution()
{
	int T;
	cin >> T;
	FOR(test, 1, T)
	{
		printf("Case #%d: ", test);
		cin >> J >> P >> S >> K;
		if (K >= S)
		{
			cout << J * P * S << endl;
			FOR(j, 1, J)
			{
				FOR(p, 1, P)
				{
					FOR(s, 1, S)
						cout << j << " " << p << " " << s << endl;
				}
			}
			continue;
		}


		bestmask = 0;
		best = 0;
		int mx = (1 << (J * P * S));
		prep(mx - 1);

		bool f = true;
		DFOR(i, mx - 1, 0)
		{
			if (!check(i))
			{
				curia(i);
				continue;
			}
		
			curia(i);
			bestmask = i;
			best = ON;
		}
		cout << best << endl;
		best = 0;
		while (bestmask)
		{
			if (bestmask & 1)
			{
				int j, p, s;
				j = 1 + best / P / S;
				p = 1 + (best / S) % P;
				s = 1 + best % S;
				cout << j << " " << p << " " << s << endl;
			}
			best++;
			bestmask >>= 1;
		}
	}
}

/*-------------------*/
  
int main()
{
#ifdef Files
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
/*Test*/
//freopen("input.txt", "w", stdout);
long double OcZ2X = clock();
#else
//freopen("laboratory.in", "r", stdin);
//freopen("laboratory.out", "w", stdout);
#endif
/*
 　　　　　　　　　　　 　∧__∧
　　　　　　　　　　　 　( ° ͜ʖ°)
　　　　　　　　　　　 　⊂　　 つ
　　　　　　　　　　　　　(つ ﾉ
　　　　　　　　　　　　　 (ノ
　　　　　＼　　　　　　☆
　　　　　　　　　　　　　|　　　　　☆
　　　　　　　　　　(⌒ ⌒ヽ　　　/
　　　　＼　　（´⌒　　⌒　　⌒ヾ　　　／
　　　　　 （’⌒　;　⌒　　　::⌒　　）
　　　　　（´*/    solution();   /*:::　）　／
　　☆─　（´⌒;:　　　　::⌒`）　:;　　）
　　　　　（⌒::　　　::　　　　　::⌒　）
　　 　／　（　　　　ゝ　　ヾ　丶　　ソ　─
*/
#ifdef Time
long double P2HxQ = clock();
printf("\n*** Total time = %.3f sec ***\n", (P2HxQ - OcZ2X) / CLOCKS_PER_SEC);
#endif
}