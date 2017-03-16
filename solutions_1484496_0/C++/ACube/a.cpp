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
ll s1, s2;
ll a[2000];
int n, col, MID = 2000001;
vector <ll> v1, v2;
int w[21][4000005];
bool d[21][4000005];

bool dfs(int u, int s)
{
	if (s==2000001) return 1;
	if (u == n) return 0;
	if (w[u][s]==col) return d[u][s];
	w[u][s] = col;

	d[u][s] = dfs(u+1, s);
	d[u][s] |= dfs(u+1, s+a[u]);
	d[u][s] |= dfs(u+1, s-a[u]);

	return d[u][s];
}

void output(int u, int s)
{
//	cerr << "Here s = " << s << " MID = " << MID << endl;
 	if (s==MID) return;
 	if (u == n) return;
// 	cerr << dfs(u, s) << endl;

 	if (dfs(u+1, s))
 		output(u+1, s);
 	else
 	if (dfs(u+1, s+a[u]))
 	{
		v1.PB(a[u]);
		output(u+1, s+a[u]);
 	}
 	else
 	{
 		assert(dfs(u+1, s-a[u]));
		v2.PB(a[u]);
		output(u+1, s-a[u]);
 	}
}

void main2()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	s1 = s2 = 0;
	col++;
	gout << endl;
	for (int i = 0; i < n; i++)
		if (dfs(i, a[i]+MID))
		{
			v1.clear(); v2.clear();
			v1.PB(a[i]);

		 	output(i, a[i]+MID);

			for (int i = 0; i < SIZE(v1); i++)
				printf("%I64d%c", v1[i], " \n"[i+1==SIZE(v1)]);
//			cerr << SIZE(v1) << " " << SIZE(v2) << endl;
			for (int i = 0; i < SIZE(v2); i++)
				printf("%I64d%c", v2[i], " \n"[i+1==SIZE(v2)]);

		 	return;
		}
	for (int i = 0; i < n; i++)
		if (dfs(i, MID-a[i]))
		{
			v1.clear(); v2.clear();
			v2.PB(a[i]);

		 	output(i, a[i]+MID);

			for (int i = 0; i < SIZE(v1); i++)
				printf("%I64d%c", v1[i], " \n"[i+1==SIZE(v1)]);
//			cerr << SIZE(v1) << " " << SIZE(v2) << endl;
			for (int i = 0; i < SIZE(v2); i++)
				printf("%I64d%c", v2[i], " \n"[i+1==SIZE(v2)]);

		 	return;
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
