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

string C, J;
pair <UN LL, pair <UN LL, UN LL> > ans;

string OUT(UN LL x)
{
	MFOR(i, 0, C.size())
		C[i] = '0';
	int t = C.size();
	while (x)
	{
		C[--t] = 48 + x % 10;
		x /= 10;
	}
	return C;
}

void proc(int start, UN LL A, UN LL B)
{
	if (start > 0)
	{
		A = A * 10 + C[start - 1] - 48;
		B = B * 10 + J[start - 1] - 48;
	}

	MFOR(i, start, C.size())
	{
		if (C[i] == '?' And J[i] == '?')
		{
			if (A == B)
			{
				for (char t1 = '0'; t1 <= '1'; t1++)
				{
					for (char t2 = '0'; t2 <= '1'; t2++)
					{
						C[i] = t1;
						J[i] = t2;
						if (t1 != '1' Or t2 != '1')
							proc(i + 1, A, B);
					}
				}
			}
			else if (A < B)
			{
				C[i] = '9';
				J[i] = '0';
				proc(i + 1, A, B);
			}
			else 
			{
				C[i] = '0';
				J[i] = '9';
				proc(i + 1, A, B);
			}
			C[i] = '?';
			J[i] = '?';
			return;
		}
		else if (C[i] == '?')
		{
			if (A == B)
			{
				for (char t1 = Max('0', J[i] - 1); t1 <= Min('9', J[i] + 1); t1++)
				{
					C[i] = t1;
					proc(i + 1, A, B);
				}
			}
			else if (A < B)
			{
				C[i] = '9';
				proc(i + 1, A, B);
			}
			else
			{
				C[i] = '0';
				proc(i + 1, A, B);
			}
			C[i] = '?';
			return;
		}
		else if (J[i] == '?')
		{
			if (A == B)
			{
				for (char t2 = Max('0', C[i] - 1); t2 <= Min('9', C[i] + 1); t2++)
				{
					J[i] = t2;
					proc(i + 1, A, B);
				}
			}
			else if (A < B)
			{
				J[i] = '0';
				proc(i + 1, A, B);
			}
			else
			{
				J[i] = '9';
				proc(i + 1, A, B);
			}
			J[i] = '?';
			return;
		}
		A = A * 10 + C[i] - 48;
		B = B * 10 + J[i] - 48;
	}
	UN LL dif;
	if (A > B)
		dif = A - B;
	else
		dif = B - A;
	ans = Min(ans, MP(dif, MP(A, B)));
}

void solution()
{
	int T;
	cin >> T;
	FOR(test, 1, T)
	{
		printf("Case #%d: ", test);
		cin >> C >> J;
		ans.first = 1e19;
		ans.first += 100;
		proc(0, 0, 0);
		cout << OUT(ans.second.first) << " " << OUT(ans.second.second) << endl;
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