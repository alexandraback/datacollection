#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100010;

double p[MAXN];
int N, M;

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	int T;	cin >> T;
	for(int cas = 1; cas <= T; ++ cas)
	{
		cin >> N >> M;
		p[0] = 1.0;
		double ans = M + 2;
		for(int i = 1; i <= N; ++ i)
		{
			cin >> p[i];
			p[i] *= p[i - 1];
			ans = min(ans, p[i] * (N + M - 2*i + 1) + (1 - p[i]) * (N + M - 2*i + 1 + M + 1));	
		}	
		printf("Case #%d: %.10f\n", cas, ans);
	}
	
	
	return 0;	
}
