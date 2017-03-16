#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<queue>
#include<vector>
#include<set>
#include<deque>
#include<functional>
#include<cstdlib>
#include<list>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;
int test, n, m, num, ans, cover, now;
int **a;
int **b;

void update(int x,int y) {
	a[x][y] = -1;
	int tmp = ans - 1;
	for (int l = -4; l <= 4; ++ l)
		for (int r = -4; r <= 4; ++ r) {
			int p = x + l;
			int q = y + r;
			if (p >= 0 && p < n && q >= 0 && q < m && a[p][q] == 0) {
				if (a[p-1][q] == -1 || a[p+1][q] == -1 || a[p][q-1] == -1 || a[p][q+1]==-1) ++ tmp;
			}
		}
	if (tmp < now) {
		now = tmp;
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < m; ++ j)
				b[i][j] = a[i][j];
		for (int l = -4; l <= 4; ++ l)
			for (int r = -4; r <= 4; ++ r) {
				int p = x + l;
				int q = y + r;
				if (p >= 0 && p < n && q >= 0 && q < m && b[p][q] == 0) {
					if (a[p-1][q] == -1 || a[p+1][q] == -1 || a[p][q-1] == -1 || a[p][q+1]==-1) b[p][q] = 1;
				}
			}
	}
	a[x][y] = 1;
}

int main()
{
	scanf("%d",&test);
	for (int t = 1; t <= test; ++ t) {
		printf("Case #%d: ", t);
		scanf("%d%d%d",&n,&m,&num);
		a = new int*[n];
		b = new int*[n];
		for (int i = 0; i < n; ++ i) {
			a[i] = new int[m];
			b[i] = new int[m];
		}
		ans = 0;
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < m; ++ j)
				if (!i || !j || i==n-1 || j==m-1)
					a[i][j] = 1, ++ ans;
				else 
					a[i][j] = 0;
		for (int cover = n * m; cover > num; -- cover) {
			now = 0x7fffffff;
			for (int i = 0; i < n; ++ i)
				for (int j = 0; j < m; ++ j)
					if (a[i][j] == 1)
						update(i,j);
			for (int i = 0; i < n; ++ i)
				for (int j = 0; j < m; ++ j)
					a[i][j] = b[i][j];
			if (now < ans)
				ans = now;
		}
		printf("%d\n", ans);
		for (int i = 0; i < n; ++ i) {
			delete[] a[i];
			delete[] b[i];
		}
		delete[] a;
		delete[] b;
	}
	return 0;
}