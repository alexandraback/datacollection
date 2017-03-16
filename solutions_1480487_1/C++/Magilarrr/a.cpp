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
int s[250];
int sum;
double low, high,middle;
double ans[250];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&test);
	for(int t = 1; t <= test; t++)
	{
		sum = 0;
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&s[i]);
			sum+=s[i];			
		}
		printf("Case #%d:",t);
		for(int i = 0; i < n; i++)
		{
			low = 0;
			high = 100;
			for(int j = 0; j < 200; j++)
			{
				middle = (low+high)/2;
				double temp = s[i]+ (sum*middle)/100;
				double left = sum*(100-middle)/100;
				double need = 0;
				if ((sum-s[i]+left) < (temp*(n-1)))
				{
					high = middle;
				}
				else
				{
					for(int k = 0; k < n; k++)
					{
						if (k == i) continue;
						if (s[k] < temp)
							need+=temp-s[k];
					}
					if (need > left)
						high = middle;
					else
					{
						low = middle;
					}
				}
			}
			ans[i] = (high+low)/2;
			printf(" %0.6f",ans[i]);
		}
		printf("\n");

	}
	return(0);
}