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
#define MIN(a, b) (((a) < (b))? (a): (b))
#define MAX(a, b) (((a) < (b))? (b): (a))
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

UN LL kkk(string &a)
{
	UN LL x = 0;
	MFOR(i, 0, a.size())
		x = x * 10 + a[i] - 48;
	return x;
}

void proc2(int start)
{
	MFOR(i, start, J.size())
	{
		if (J[i] == '?')
		{
			FOR(here, 0, 9)
			{
				J[i] = char(48 + here);
				proc2(i + 1);
			}
			J[i] = '?';
			return;
		}
	}
	UN LL A = kkk(C);
	UN LL B = kkk(J);
	UN LL dif;
	if (A > B)
		dif = A - B;
	else
		dif = B - A;
	ans = min(ans, MP(dif, MP(A, B)));
}

void proc(int start)
{
	MFOR(i, start, C.size())
	{
		if (C[i] == '?')
		{
			FOR(here, 0, 9)
			{
				C[i] = char(48 + here);
				proc(i + 1);
			}
			C[i] = '?';
			return;
		}
	}
	proc2(0);
}

string OUT(UN LL x)
{
	MFOR(i, 0, C.size())
		C[i] = '0';
	int t = C.size();
	while (x)
	{
		C[--t] = x % 10 + 48;
		x /= 10;
	}
	return C;
}

void solution()
{
	int T;
	cin >> T;
	FOR(test, 1, T)
	{
		printf("Case #%d: ", test);
		cin >> C >> J;
		ans.first = 1e19 + 5;
		proc(0);
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