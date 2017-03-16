#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)

typedef long long ll;
typedef double ld;

int	fx[] = {-1, 0, +1, 0}, fy[] = {0, +1, 0, -1},
	ex[] = {-1, -1, 0, +1, +1, +1, 0, -1}, ey[] = {0, +1, +1, +1, 0, -1, -1, -1};

using namespace std;

int test_num, case_number;

#define gout case_number++, printf("Case #%d: ",case_number), cout

int a[1000];

void main2()
{
	int s = 0, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a+i),
		s += a[i];

	gout;
	for (int i = 0; i < n; i++)
	{
	 	double lo = 0, hi = 100, mi, curs, left, need;

	 	for (int it = 0; it < 200; it++)
	 	{
			mi = (lo+hi)/2.;
			curs = a[i] + mi/100.*s;
			left = 100-mi;

			for (int j = 0; j < n; j++)
				if (i != j && a[j]<curs)
				{
					need = (curs-a[j])/s*100;
					left -= need;
				}

			if (left >= -1e-10)
				lo = mi;
			else
				hi = mi;
	 	}
		printf("%.7lf%c", (lo+hi)/2., " \n"[i+1==n]);
	}
}

int main()
{
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++)
		main2();

	return 0;
}
