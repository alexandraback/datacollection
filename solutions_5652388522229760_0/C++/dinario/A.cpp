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
#define N 2100

int T;

LL lastNumber(LL a)
{
	bool was[10];
	memset(was, 0, sizeof(was));
	int cnt = 10;
	for (LL cur = a, iter = 0; iter < 200; cur += a, ++iter)
	{
		for (LL rest = cur; rest > 0; rest /= 10)
		{
			int digit = rest % 10;
			if (!was[digit])
			{
				cnt -= 1;
				was[digit] = true;
				if (cnt == 0)
				{
					re cur;
				}
			}
		}
	}
	re -1;
}

int main()
{
#ifdef _DINARISIO
	ifstream cin("A-small-attempt0.in");
	ofstream cout("A.out");
#endif
	/*for (int i = 0; i < 1000000; ++i)
	{
		if (lastNumber(i) == -1){
			continue;
		}
	}*/
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		LL a;
		cin >> a;
		LL res = lastNumber(a);
		cout << "Case #" << t + 1 << ": ";
		if (res == -1)
		{
			cout << "INSOMNIA" << endl;
			continue;
		}
		cout << res << endl;
	}
	
	re 0;
}