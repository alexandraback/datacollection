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


int n;
int x;
int y;
double p;
int c(int a, int b)
{
	int mult = 1;
	for(int i = b; i >= (b-a+1); i--)
		mult *= i;
	for(int i = 1; i <= a; i++)
		mult /= i;
	return(mult);
}
int main()
{
	//freopen("input.txt","r",stdin);
	freopen("B-small-attempt2.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d\n",&t);
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
								p += c(i,k);
							}
							for(int i = 0; i < k; i++)
								p /= 2;
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