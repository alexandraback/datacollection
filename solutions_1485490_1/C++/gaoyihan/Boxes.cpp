#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

long long opt[110][110];
long long a[110], b[110];
int A[110], B[110];
int n, m;

long long extend(int x, int y)
{
	if (opt[x][y] != -1) return opt[x][y];
	long long ret = 0;
	for (int t = 1; t <= 100; t++ )
	{
		long long l = 0, r = 0;
		int p = x, q = y;
		while (p <= n && q <= m)
		{
			if (l <= r) {
				if (p < n && A[p] == t) l += a[p];
				p ++;
			} else {
				if (q < m && B[q] == t) r += b[q];
				q ++;
			}
			ret = max(ret, min(l, r) + extend(p, q));
		}
	}
	opt[x][y] = ret;
	return ret;
}

void work(int casen)
{
	scanf( "%d %d", &n, &m );
	for (int i = 0; i < n; i++ )
		cin >> a[i] >> A[i];
	for (int i = 0; i < m; i++ )
		cin >> b[i] >> B[i];
	memset( opt, 0xff, sizeof( opt ) );
	long long ans = extend(0, 0);
	cout << "Case #" << casen << ": " << ans << endl;
}

int main()
{
	freopen( "in.txt", "r", stdin );
	freopen( "out.txt", "w", stdout );
	int test_cases;
	scanf( "%d", &test_cases );
	for (int i = 0; i < test_cases; i++ )
		work(i + 1);
}
 