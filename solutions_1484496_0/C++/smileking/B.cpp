/*
 * B.cpp
 *
 *  Created on: 2012-5-6
 *      Author: jesliwang
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

vector<int> hah[2000100];
int dp[1<<20+1];
int main(int argc, char* argv[])
{
	int T;
	scanf("%d",&T);
	for(int cas = 1; cas <= T; cas ++)
	{
	int n;
	int list[510];
	memset(dp, 0, sizeof(dp));
	scanf("%d", &n);
	int sum = 0;
	for(int i=0; i < n; i++)
	{
		scanf("%d", &list[i]);
		sum += list[i];
	}
	for(int i=1;i<=sum;i++)
	{
		hah[i].clear();
	}

	for(int i=0;i<n;i++)
	{
		dp[1<<i] = list[i];
		hah[list[i]].push_back(1<<i);
	}

	for(int i=1;i <= sum; i++)
	{

		if(dp[i] != 0)
		{
			for(int j=0; j< n; j++)
			{

				if(!(i & (1<<j)))
				{
					dp[i | (1<<j)] = dp[i] + list[j];
					hah[list[j]+dp[i]].push_back(i | (1<<j));

				}
			}
		}

	}
	printf("Case #%d:\n", cas);
	for(int i=1;i<=sum;i++)
	{
		if(hah[i].size() >1)
		{
			for(int j=0;j<hah[i].size();j++)
			{
				for(int x=j+1; x<hah[i].size(); x++)
				{
					if(!(hah[i][j]&hah[i][x]))
					{
						bool yy = false;
						for(int love = 0; love < n; love ++)
						{
							if(hah[i][j] & (1<<love))
							{
								if(yy)
									printf(" ");
								printf("%d", list[love]);
								yy = true;
							}

						}
						printf("\n");
						yy = false;
						for(int love = 0; love < n; love ++)
						{
							if(hah[i][x] & (1<<love))
							{
								if(yy)
									printf(" ");
								printf("%d", list[love]);
								yy = true;
							}


						}
						printf("\n");
						goto label;
					}
				}
			}
		}
	}
	printf("Impossible\n");
label:
		;
	}




	return 0;
}



