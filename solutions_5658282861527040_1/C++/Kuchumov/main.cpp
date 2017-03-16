#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int int64;

bool get_bit(int64 mask, int64 pos)
{
	return (mask & (1LL << pos)) != 0;
}

const int M = 35;

int64 dp[M][M][M];

int64 solve2(int64 a, bool can_less_a, int64 b, bool can_less_b, int64 k, int64 pos)
{
 	if (pos == -1)
 		return 1;

 	if (dp[can_less_a][can_less_b][pos] != -1)
 		return dp[can_less_a][can_less_b][pos];
	
	int64 cur_ans = 0;

	if (get_bit(k, pos))
	{
		int64 last_a = (a & ((1LL << pos) - 1)) + 1;
		int64 last_b = (b & ((1LL << pos) - 1)) + 1;

		int64 m1;
		int64 m2;

		//both zero
		m1 = last_a;
		m2 = last_b;

		if (get_bit(a, pos) || can_less_a)
			m1 = (1LL << pos);

		if (get_bit(b, pos) || can_less_b)
			m2 = (1LL << pos);

		cur_ans += m1 * m2;
			 	
		//a - 1 b - 0
		if (get_bit(a, pos) || can_less_a)
		{
			m1 = last_a;
			m2 = last_b;
			if (can_less_a)
				m1 = (1LL << pos);

			if (get_bit(b, pos) || can_less_b)
				m2 = (1LL << pos);

			cur_ans += m1 * m2;	
		}

		//a - 0 b - 1
		if (get_bit(b, pos) || can_less_b)
		{
			m1 = last_a;
			m2 = last_b;
			if (get_bit(a, pos) || can_less_a)
				m1 = (1LL << pos);

			if (can_less_b)
				m2 = (1LL << pos);

			cur_ans += m1 * m2;
		}                                

		if ((get_bit(a, pos) || can_less_a) && (get_bit(b, pos) || can_less_b))
			cur_ans += solve2(a, can_less_a, b, can_less_b, k, pos - 1);
	}
	else
	{
	    //a - 1 b - 0
		if (get_bit(a, pos) || can_less_a)
			cur_ans += solve2(a, can_less_a, b, can_less_b | get_bit(b, pos), k, pos - 1);

		//a - 0 b - 1
		if (get_bit(b, pos) || can_less_b)
			cur_ans += solve2(a, can_less_a | get_bit(a, pos), b, can_less_b, k, pos - 1);

		//both zero
		cur_ans += solve2(a, can_less_a | get_bit(a, pos), b, can_less_b | get_bit(b, pos), k, pos - 1);
	}

	dp[can_less_a][can_less_b][pos] = cur_ans;

	return cur_ans;
}

int64 slow_solve(int64 a, int64 b, int64 k)
{
	int64 ans = 0;
 	for (int64 i = 0; i <= a; i++)
 		for (int64 j = 0; j <= b; j++)
 			if ((i & j) <= k)
 				ans++;
 	return ans;
}

int64 solve()
{
 	int64 a, b, k;
 	cin >> a >> b >> k;
 	a--;
 	b--;
    k--;

    for (int i = 0; i < M; i++)
    	for (int j = 0; j < M; j++)
    		for (int k = 0; k < M; k++)
    			dp[i][j][k] = -1;  

 	int64 m = solve2(a, false, b, false, k, 31);

 	return m;
}

int main()
{
	freopen("input.in", "r", stdin); freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int it = 1; it <= t; it++)
	{
	 	printf("Case #%d: %lld\n", it, solve());
	}

 	return 0;
}