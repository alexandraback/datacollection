#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
#define f0(i,N) for (int i=0; i< N; i++) 
#define f1(i,N) for (int i=1; i<=N; i++) 
int a[7][7], found=0;
ll B, M;

ll fact(ll N)
{
	if (N == 1) return 1;
	return N*fact(N - 1);
}

void print_a()
{
	f1(i, B)
	{
		f1(j, B) cout << a[i][j] << " ";
		cout << endl;
	}
	return;
}

ll no_ways(int i)
{
	if (i == B) return 1;
	ll ans = 0;
	for (int j = 1; j <= B; j++)
	if (j!=i && a[i][j]==1)
		{
			ans += no_ways(j);
		}
	return ans;
}

void recur(int i, int j)
{
	if (i == B)
	{
		if (no_ways(1) == M)
		{
			found = 1;
		}
		return;
	}
	if (!found)
	{
		if (i == j)
		{
			a[i][j] = 0;
			recur(i, j + 1);
		}
		else if (j == B)
		{
			a[i][j] = 1;
			recur(i + 1, i+1);
		}
		else
		{
			if (!a[j][i]) a[i][j] = 1;
			recur(i, j + 1);
			a[i][j] = 0;
			recur(i, j + 1);
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	f1(t, T)
	{
		found = 0;
		memset(a, 0, sizeof(a));
		cout << "Case #" << t << ": ";
		cin >> B >> M;
		recur(1, 2);
		if (!found) {
			cout << "IMPOSSIBLE" << endl; continue;
		}
		cout << "POSSIBLE" << endl;
		print_a();
		//no_ways(1);
	}
	return 0;
}
