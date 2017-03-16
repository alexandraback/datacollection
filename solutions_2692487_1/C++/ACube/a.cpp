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

int a[2000000];

void main2()
{
	int A, n;
	scanf("%d%d", &A, &n);
	for (int i = 0; i < n; i++) scanf("%d", a+i);
	sort(a, a+n);
	long long cur = A;
	int tot = 0, best = n;
	for (int i = 0; i < n; i++) {
		best = min(best, tot + n-i);
		if (cur == 1 && a[i] > 0) {
			tot = n;
		 	break;
		}
		while (cur <= a[i]) cur += cur-1, tot++;
		cur += a[i];
	}
	best = min(best, tot);

	gout << best << endl;
}

int main()
{
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++)
		main2();

	return 0;
}
