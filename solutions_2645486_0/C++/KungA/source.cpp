#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
using namespace std;

int v[100];
int E, R, N;

int solve(int e, int i)
{
	if (i == N)
		return 0;
	e = min(e, E);

	int res = 0;
	for (int j = 0; j <= e; j++)
		res = max(res, solve(e - j + R, i + 1) + j * v[i]);
	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "rt", stdin);
		freopen("output.txt", "wt", stdout);
	#endif

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> E >> R >> N;
		for (int i = 0; i < N; i++)
			cin >> v[i];

		int ans = solve(E, 0);


		cout << "Case #" << t + 1 << ": " << ans;		
		cout << endl;
	}
}
































