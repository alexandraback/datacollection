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
#include <string>

using namespace std;

#define ABS(a) (((a) > 0)? (a): -(a))
#define MIN(a, b) (((a) < (b))? (a): (b))
#define MAX(a, b) (((a) < (b))? (b): (a))
#define MFOR(i, a, n) for (int i = (a); i < (n); i++)
#define FOR(i, a, n) for (int i = (a); i <= (n); i++)
#define DFOR(i, a, n) for (int i = (a); i >= (n); i--)
#define SORT(a, first_element, last_element) sort(&(a)[(first_element)], &(a)[(last_element) + 1])
#define SQR(a) (a) * (a)
#define PI 3.14159265358979323846264
#define MEMS(a, b) memset((a), (b), sizeof(a))
#define MP make_pair
#define PB push_back
#define endl '\n'
#define LL long long
#define UN unsigned
#define Or ||
#define And &&
/////////////////////////////////////////////

string ANS[2] = {"NO", "YES"};
string s;

/*

   1  i  j  k
1  1  i  j  k
i  i -1  k -j
j  j -k -1  i
k  k  j -i -1

*/

//\\
| 0 | 1 | 2 | 3 |  4 |  5 |  6 |  7 | \
| 1 | i | j | k | -1 | -i | -j | -k | \

char mult[4][4] = {0, 1, 2, 3, 1, 4, 3, 6, 2, 7, 4, 1, 3, 2, 5, 4};
//char zn[4][4] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1};

char per(char a)
{
	if (a == '1')
		return 0;
	if (a == 'i')
		return 1;
	if (a == 'j')
		return 2;
	return 3;
}

char MUL(char a, char b)
{
	int zn = 0;
	if (a / 4)
		zn ^= 4;
	if (b / 4)
		zn ^= 4;
	
	return mult[a % 4][b % 4] ^ zn;
}

char ST(char x, LL pw)
{
	if (pw == 1)
		return x;

	LL pw2 = pw / 2;
	char d = ST(x, pw2);
	d = MUL(d, d);
	if (pw & 1)
		d = MUL(x, d);
	return d;
}

char gather()
{
	int sz = s.size();
	char t = s[0];

	MFOR(i, 1, sz)
		t = MUL(t, s[i]);

	return t;
}



void solution()
{
	int T;
	cin >> T;
	FOR(t, 1, T)
	{
		int ans = 0;
		LL L, X;
		cin >> L >> X >> s;
		int sz = s.size();
		
		MFOR(i, 0, sz)
			s[i] = per(s[i]);

		if (X > 20)
		{
			char t = gather();
			t = ST(t, X - 20);
			string p = s;
			FOR(i, 2, 10)
				s = s + p;
			s = s + t + s;
		}
		else
		{
			string p = s;
			FOR(q, 2, X)
				s = s + p;
		}
		
		sz = s.size();
		int left = 0;
		int right = sz - 1;
		char ti = s[0];
		while (ti != 1 And left + 1 < right)
		{
			left++;
			ti = MUL(ti, s[left]);
		}

		char tk = s[right];
		while (tk != 3 And right - 1 > left)
		{
			right--;
			tk = MUL(s[right], tk);
		}

		left++;
		right--;
		char tj = s[left];
		FOR(i, left + 1, right)
			tj = MUL(tj, s[i]);
		if (ti == 1 And tj == 2 And tk == 3 And left <= right)
			ans = 1;
		else
			ans = 0;

		printf("Case #%d: ", t);
		cout << ANS[ans] << endl;
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

double OcZ2X = clock();
#else
//freopen("unionday.in", "r", stdin);
//freopen("unionday.out", "w", stdout);
#endif

solution();

#ifdef Time
double P2HxQ = clock();
printf("\n*** Total time = %.3f sec ***\n", (P2HxQ - OcZ2X) / CLOCKS_PER_SEC);
#endif
}