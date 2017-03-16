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

#define x first
#define y second
#define pb push_back
#define mp make_pair

int n;
int t;
int a;
int motes[110];
int k;
int steps;
int c;
int main()
{
	/*
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	*/
	freopen("A-small-attempt2.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d\n",&t);
	for(int test = 0; test < t; test++)
	{
		scanf("%d%d",&a,&n);
		for(int i = 0; i < n; i++)
			scanf("%d",&motes[i]);
		sort(motes,motes+n);
		k = 0;
		while ((k < n)&&(a > motes[k]))
		{
			a += motes[k];
			k++;
		}
		if (k == n)
			c = 0;
		else
		{
			c = n - k;
			if (a != 1)
			{
				for(int i = k + 1; i <= n; i++)
				{
					int temp = n - i;
					int ta = a;
					for(int j = k; j < i; j++)
					{
						while(ta <= motes[j])
						{
							ta += ta-1;
							temp++;
						}
						ta += motes[j];
					}
					if (temp < c)
						c = temp;
				}
			}
		}
		printf("Case #%d: %d\n",test+1,c);
	}
	return(0);
}