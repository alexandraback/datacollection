#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 10010

int e, r, n;
int values[MAXN];
int rmq_array[MAXN][16];

void build_rmq()
{
	for (int i = 0; i < n; i++)
		rmq_array[i][0] = i;
	for (int l = 1; (1 << l) <= n; l++)
		for (int i = 0; i + (1<<l) <= n; i++)
		{
			int j = i + (1 << (l - 1));
			int left = rmq_array[i][l - 1];
			int right = rmq_array[j][l - 1];
			if (values[left] >= values[right])
				rmq_array[i][l] = left;
			else
				rmq_array[i][l] = right;
		}
}

int rmq(int i, int j)
{
	int len = j - i;
	if (len <= 0 || len > n)
		return n;
	
	int k = log(len) / log(2);
	while ((1 << k) > len)
		k--;
	while ((1 << (k + 1)) <= len)
		k++;
	
	int left = rmq_array[i][k];
	int right = rmq_array[j - (1 << k)][k];
	if (values[left] >= values[right])
		return left;
	else
		return right;
}

long long solve(int s, int t, long long se, long long ee)
{
	if (t - s <= 0)
		return 0;
		
	cerr << "solving " << s << " " << t << " " << se << " " << ee << endl;
	if (t - s == 1)
	{
		long long start = se;
		long long remain = max(0ll, ee - r);
		long long energy = start - remain;
		cerr << energy << " energy spent on " << s << endl;
		return values[s] * energy;
	}
	
	int mid = rmq(s, t);
	long long mid_start = min((long long)e, se + (mid - s) * (long long)r);
	long long mid_remain = max(0ll, ee - (t - mid) * (long long)r);
	long long mid_energy = mid_start - mid_remain;
	
	cerr << mid_energy << " energy spent on " << mid << endl;
	
	return solve(s, mid, se, mid_start) + solve(mid + 1, t, mid_remain + r, ee) + mid_energy * values[mid];
}

int main()
{
	int caseN;
	scanf("%d", &caseN);
	for (int caseI = 1; caseI <= caseN; caseI++)
	{
		scanf("%d%d%d", &e, &r, &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &values[i]);
		build_rmq();
		
		long long ans = solve(0, n, e, 0);
		cout << "Case #" << caseI << ": " << ans << endl;
	}
	return 0;
}
