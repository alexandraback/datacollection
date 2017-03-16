#include <iostream>
#include <algorithm>
using namespace std;

int N, M, T;
long long a[100];
int A[100];
long long b[100];
int B[100];

long long solve(int i, int j)
{
	if (i >= N || j >= M)
		return 0;
	long long res = 0;
	if (A[i] == B[j])
	{
		if (a[i] == b[j])
			return a[i] + solve(i+1, j+1);
		if (a[i] > b[j])
		{
			a[i] -= b[j];
			res = b[j] + solve(i, j+1);
			a[i] += b[j];
			return res;
		}
		if (a[i] < b[j])
		{
			b[j] -= a[i];
			res = a[i] + solve(i+1, j);
			b[j] += a[i];
			return res;
		}
	}
	else
	{
		return max(solve(i+1, j), solve(i, j+1));
	}
}

int main()
{
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		cin >> N >> M;
		for (int i=0; i<N; i++)
			cin >> a[i] >> A[i];
		for (int i=0; i<M; i++)
			cin >> b[i] >> B[i];

		cout << "Case #" << t << ": " << solve(0, 0) << endl;
	}

	return 0;
}