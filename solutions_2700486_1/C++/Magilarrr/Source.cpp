#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <cstring>
#include <stack>
using namespace std;

#define pb push_back
#define mp make_pair
int t;

double c[3000][3000];
int n;
int x;
int y;
double p;

int main()
{
	//freopen("input.txt","r",stdin);
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d\n",&t);
	c[0][0] = 1;
	c[0][1] = 1/2;
	c[1][1] = 1/2;
	for(int i = 1; i < 2950; i++)
	{
		c[0][i] = c[0][i-1]/2;
		for(int j = 1; j < i; j++)
		{
			c[j][i] = (c[j][i-1]+c[j-1][i-1])/2;
		}
		c[i][i] = c[i-1][i-1]/2;
	}
	for(int test = 0; test < t; test++)
	{
		scanf("%d%d%d",&n,&x,&y);
		int wave = (abs(x)+y)/2;
		int wave_up = (wave+1)*(2*wave+1);
		int wave_down = (wave)*(2*wave - 1);
		if (x == 0)
		{
			if (n >= wave_up)
				p = 1;
			else
				p = 0;
		}
		else
		{
			if (n >= (wave_up - 1))
				p = 1;
			else
			{
				int k = n - wave_down;
				int side = (wave_up - wave_down - 1)/2;
				//y - height, we need at least y at our side
				y++;
				if (k - side >= y)
				{
					p = 1;
				}
				else
				{
					if (k < y)
					{
						p = 0;
					}
					else
					{
						p = 0;
						/*
						p = 0;
						if (k <= side)
						{
						*/
							for(int i = y; i <= k; i++)
							{
								p += c[i][k];
							}
							/*
						}
						else
						{
							y -= (k - side);
							k = k - 2*(k - side);
							for(int i = y; i <= k; i++)
							{
								p += c(i,k);
							}
							for(int i = 0; i < k; i++)
								p /= 2;
						}
						*/
					}
				}
			}
		}
		printf("Case #%d: %0.7f\n",test+1,p);
	}
	return(0);
}