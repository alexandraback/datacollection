#include <cstdio>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;


int main(void)
{
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);

	int t ;
	scanf("%d", &t);

	for (int q = 1; q <= t; q++)
	{
		int n,m,k;
		scanf("%d%d%d", &n, &m, &k);

		if (n > m)
		{
			swap(n,m);
		}
		if ((n <= 2) || (m <= 2))
		{
			printf("Case #%d: %d\n",q,k);
		}
		else
		{
			int ans;
			if ((n == 4) && (m == 5))
			{
				if (k <= 4)
					ans = k;
				else
					if (k <= 5)
						ans = 4;
					else
						if (k <= 8)
							ans = 6;
						else
							if (k <= 10)
								ans = 7;
							else
								if (k <= 12)
									ans = 8;
								else
									if (k <= 14)
										ans = 9;
									else
										if (k <= 16)
											ans = 10;
										else
										{
											int diff = k - 16;
											ans = 10 + diff;
										}
			}
			if ((n == 3) && (m == 6))
			{
				if (k <= 4)
					ans = k;
				else
					if (k <= 5)
						ans = 4;
					else
						if (k <= 8)
							ans = 6;
						else
							if (k <= 11)
								ans = 8;
							else
								if (k <= 14)
									ans = 10;
								else
								{
									int diff = k - 14;
									ans = 10 + diff;
								}

			}
			if ((n == 4) && (m == 4))
			{
				if (k <= 4)
					ans = k;
				else
					if (k <= 5)
						ans = 4;
					else
						if (k <= 8)
							ans = 6;
						else
							if (k <= 10)
								ans = 7;
							else
								if (k <= 12)
									ans = 8;
								else
								{
									int diff = k - 12;
									ans = 8 + diff;
								}
			}
			if ((n == 3) && (m == 5))
			{
				if (k <= 4)
					ans = k;
				else
					if (k <= 5)
						ans = 4;
					else
						if (k <= 8)
							ans = 6;
						else
							if (k <= 11)
								ans = 8;
							else
							{
								int diff = k - 11;
								ans = 8 + diff;
							}
			}
			if ((n == 3) && (m == 4))
			{
				if (k < 4)
					ans = k;
				else
					if (k <= 5)
						ans = 4;
					else
						if (k <= 8)
							ans = 6;
						else
						{
							int diff = k - 8;
							ans = 6 + diff;
						}
			}
			if ((n == 3) && (m == 3))
			{
				if (k < 4)
					ans = k;
				else
					if (k <= 5)
						ans = 4;
					else
					{
						int diff = k - 5;
						ans = 4 + diff;
					}
			}
			printf("Case #%d: %d\n",q,ans);
		}
	}

	return 0;
}