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

int t;
long long q[10000000];

bool is_pal(long long x)
{
	string s = "";
	for (; x; x/=10) s += x%10+'0';
	string t = s;
	reverse(t.begin(), t.end());
	return t==s;
}

void main2()
{
	long long a, b;
	cin >> a >> b;
	gout << lower_bound(q, q+t, b+1)-lower_bound(q, q+t, a) << endl;
}

int main()
{
	for (int i = 1; i <= 10000000; i++)
	 	if (is_pal(i))
	 		if (is_pal(1LL*i*i))
	 			q[t++] = 1LL*i*i;
	cerr << "Finish\n";

	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++)
		main2();

	return 0;
}
