#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N, M, T, tmp, tmp2;
int A[105], B[105];
long long asize[105], bsize[105];
long long ans;
void solve(int a, int b, long long sum)
{
	if(a == N || b == M)
	{
		if(sum > ans)
			ans = sum;
		return;
	}
	if(A[a] == B[b])
	{
		if(asize[a] > bsize[b])
		{
			sum += bsize[b];
			asize[a] -= bsize[b];
			solve(a, b + 1, sum);
			asize[a] += bsize[b];
		}
		else
		{
			sum += asize[a];
			bsize[b] -= asize[a];
			solve(a + 1, b, sum);
			bsize[b] += asize[a];
		}
	}
	else
	{
		solve(a + 1, b, sum);
		solve(a, b + 1, sum);
	}
}
int main()
{
	freopen("e:\\C-small-attempt0.in", "r", stdin);
	freopen("e:\\C-small-attempt0.out", "w", stdout);
	cin >> T;
	for(int Tidx = 1; Tidx <= T; Tidx++)
	{
		cin >> N >> M;
		for(int i = 0; i < N; i++)
			cin >> asize[i] >> A[i];
		for(int i = 0; i < M; i++)
			cin >> bsize[i] >> B[i];
		ans = 0;
		solve(0, 0, 0);
		cout << "Case #" << Tidx << ": "; 
		cout << ans << endl;
	}
	return 0;
}

