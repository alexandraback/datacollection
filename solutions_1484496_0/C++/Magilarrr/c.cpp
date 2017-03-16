#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

int test;
int n;
int a[600];
int sum;
int tsum;
int sums[600];
int state[600];
bool ans;
int d2[30];
int ans1;
int ans0;
bool find(int temp,int v)
{
	if (tsum == temp)
	{
		ans = 1;
		return true;
	}
	else
	{
		for(int i = v; i < n;i++)
		{
			if ((state[i] == 0)&&(tsum-a[i] >= temp))
			{
				state[i] = 2;
				tsum -= a[i];
				ans0--;
				if (!find(temp,i+1))
				{
					tsum += a[i];
					state[i] = 0;
					ans0++;
				}
				else
				{
					return true;
				}
			}
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&test);
	d2[0] = 1;
	for(int i = 1; i < 25; i++)
		d2[i] = d2[i-1]*2;
	for(int t = 1; t <= test; t++)
	{
		printf("Case #%d:\n",t);
		ans = false;
		sum = 0;
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
		{
			sum+=a[i];
			scanf("%d",&a[i]);
			state[i] = 0;
		}
		sort(a,a+n);
		for(int i = 1; i < d2[n]; i++)
		{
			ans1 = 0;
			ans0 = 0;
			int temp = 0;
			tsum = 0;
			for(int j = 0; j < n; j++)
				if (i & d2[j])
				{
					state[j] = 1;
					temp+=a[j];
					ans1++;
				}
				else
				{
					state[j] = 0;
					tsum+=a[j];
				}
			ans0 = n - ans1;
			find(temp,0);
			if (ans)
				break;
		}
		if (ans)
		{
			int temp = 0;
			for(int i = 0; i < n; i++)
			{
				if (state[i] == 1)
				{
					temp++;
					if (temp == ans1)
					{
						printf("%d\n",a[i]);
					}
					else
						printf("%d ",a[i]);
				}
			}
			temp = 0;
			for(int i = 0; i < n; i++)
			{
				if (state[i] == 0)
				{
					temp++;
					if (temp == ans0)
					{
						printf("%d\n",a[i]);
					}
					else
						printf("%d ",a[i]);
				}
			}
		}
		else
			printf("Impossible\n");

	}
	return(0);
}