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

int a[2000];
int n, S, p;

void main2 ()
{
	scanf("%d%d%d", &n, &S, &p);

	int res = 0;

	for (int i = 0; i < n; i++)
	{
	 	cin >> a[i];
	 	res += (a[i] >= 3*p-2);
	}

	int left = max(0, S-(n-res)), cando = S-left;

	for (int i = 0; i < n; i++)
	{
	 	bool ok = 0;

	 	for (int f1 = p; f1 <= 10; f1++)
	 		for (int f2 = f1; f2 >= f1-2; f2--)
	 			for (int f3 = f1-2; f3 >= f1-2; f3--)
	 				if (f3>=0 && f1+f2+f3 == a[i])
	 					ok = 1;

	 	if (ok)
	 		if (a[i] >= 3*p-2)
		 		left = max(0, left-1);
		 	else
		 	if (cando-- > 0)
		 		res++;
	}

	gout << res - left << endl;
}

int main ()
{
	scanf ( "%d", &test_num );

	for ( int i = 0; i < test_num; i++ )
		main2 ();

	return 0;
}
