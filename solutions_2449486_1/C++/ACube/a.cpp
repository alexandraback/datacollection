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

int n, m;
int a[200][200];
int s[200][200];

void main2()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", s[i]+j);
	int N = n*m;
	memset(a, 0, sizeof(a));
	for (int dN=1; dN && N>0; N-=dN)
	{
		dN = 0;
		// Go by rows
		for (int i = 0; i < n; i++)
		{
			int el = -1;
		 	for (int j = 0; j < m; j++)
		 		if (!a[i][j])
		 			el = s[i][j];
		 	if (el==-1) continue;
		 	bool ok = 1;
		 	for (int j = 0; j < m; j++)
		 		if (s[i][j]==el || (a[i][j] && s[i][j]<el));
		 		else ok = 0;
			if (!ok) continue;
			for (int j = 0; j < m; j++)
				if (!a[i][j]) a[i][j] = 1, dN++;
		}
		// Go by columns
		for (int j = 0; j < m; j++)
		{
			int el = -1;
			for (int i = 0; i < n; i++)
				if (!a[i][j])
					el = s[i][j];
			if (el==-1) continue;
			bool ok=1;
			for (int i = 0; i < n; i++)
				if (s[i][j]==el || (a[i][j]&&s[i][j]<el));
				else ok = 0;
			if (!ok) continue;
			for (int i = 0; i < n; i++)
				if (!a[i][j]) a[i][j] = 1, dN++;
		}
	}

	gout << (N?"NO":"YES") << endl;
}

int main()
{
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++)
		main2();

	return 0;
}
