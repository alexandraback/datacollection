#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <windows.h>

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
ll s1, s2;
ll a[2000];
int n, col;
vector <ll> v1, v2;
int p[2000];

void main2()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		p[i] = i,
		cin >> a[i];
	gout << endl;
	srand(GetTickCount());

	for (int it = 0; it < 20000; it++)
	{
	 	random_shuffle(p, p+n);
	 	sort(a, a + n);
	 	v1.clear(); v2.clear();
	 	v1.PB(a[p[0]]);
	 	s1 = s2 = 0;
	 	s1 += a[p[0]];
	 	for (int i = 1; i < n; i++)
	 	{
	 		if (abs(s1-s2) > abs(s1-s2-a[p[i]]))
	 		{
	 			s2 += a[p[i]];
	 			v2.PB(a[p[i]]);
	 		}
	 		else
	 		if (abs(s1-s2) > abs(s1+a[p[i]]-s2))
	 		{
	 			s1 += a[p[i]];
	 			v1.PB(a[p[i]]);
	 		}

	 		if (s1 == s2)
	 		{
				for (int i = 0; i < SIZE(v1); i++)
					printf("%I64d%c", v1[i], " \n"[i+1==SIZE(v1)]);
				for (int i = 0; i < SIZE(v2); i++)
					printf("%I64d%c", v2[i], " \n"[i+1==SIZE(v2)]);
	 			return;
	 		}
	 	}
	}
	puts("Impossible");
}

int main()
{
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++)
		main2();

	return 0;
}
