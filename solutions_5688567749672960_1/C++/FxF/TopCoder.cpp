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

LL rev(LL x)
{
	LL y = 0;
	if (x % 10 == 0)
		return x;

	while (x)
	{
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}

LL calc(LL n)
{
	if (n == 1)
		return 1;
	if (n == 0)
		return -1;
	LL x = n;
	vector <char> a;
	a.clear();
	LL q = 1;
	while (x)
	{
		a.PB(x % 10);
		x /= 10;
		q = q * 10;
	}
	if (a.size() == 1)
		return n;

	q /= 10;

	// 39542
	// 10000
	// 10093
	// 39001
	// 39542
	
	// 24593

	// 10093
	// 39001

	int md = (a.size() + 1) / 2;
	LL sec = 0, fir = 0;
	MFOR(i, md, a.size())
		sec = sec * 10 + a[i];
	reverse(a.begin(), a.end());
	md = a.size() / 2;
	MFOR(i, md, a.size())
	{
		fir = fir * 10 + a[i];
	}

	if (fir > 0)
	{
		LL sum = fir + sec - 1;
		if (sec > 1)
			sum++;
		sum += calc(q - 1) + 1;
		return sum;
	}
	else
	{
		LL sum = n - q;
		sum += calc(q - 1) + 1;
		return sum;
	}
}

LL s_ans(LL n)
{
	LL q = calc(n);
	int p = 0;
	while (n > 1 And p < 10)
	{
		p++;
		n--;
		q = MIN(calc(n) + p, q);
		q = MIN(calc(rev(n)) + p + 1, q);
	}
	return q;
}

void solution()
{
	int T;
	cin >> T;
	
	int t = 0;
	while (T--)
	{
		LL n, ans;
		cin >> n;
		t++;
		ans = s_ans(n);
		printf("Case #%d: ", t);
		cout << ans << endl;
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