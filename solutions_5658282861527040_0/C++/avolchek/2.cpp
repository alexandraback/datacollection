#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>

using namespace std;


#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

ll dp[40][2][2][2];
ll a, b, k;

ll rec(int pos, int lessA, int lessB, int lessK)
{
	if (pos == -1)
	{
		return 1;
	}
	
	if (dp[pos][lessA][lessB][lessK] != -1)
		return dp[pos][lessA][lessB][lessK];
		
	ll res = 0;
	
	int ai = bool(a & (1LL << pos));
	int bi = bool(b & (1LL << pos));
	int ki = bool(k & (1LL << pos));
	
	for (int i = 0; i < 2; i++)
	{
		if (!(i <= ai || lessA))
			continue;
			
		for (int j = 0; j < 2; j++)
		{
			if (!(j <= bi || lessB))
				continue;
				
			int c = i & j;
			
			if (!(c <= ki || lessK))
				continue;
				
			res += rec(pos - 1, lessA || (i < ai), lessB || (j < bi), lessK || (c < ki));
		}
	}
	
	return dp[pos][lessA][lessB][lessK] = res;
}

int main()
{
	srand(time(NULL));
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int t;
	scanf("%d\n", &t);
	
	for (int tt = 1; tt <= t; tt++)
	{
		cin >> a >> b >> k;
		
		a--;
		b--;
		k--;
		
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int h = 0; h < 2; h++)
				{
					for (int g = 0; g < 2; g++)
					{
						dp[i][j][h][g] = -1;
					}
				}
			}
		}
		
		cout << "Case #" << tt << ": " << rec(35, 0, 0, 0) << endl;
	}
	
	
	return 0;
}



