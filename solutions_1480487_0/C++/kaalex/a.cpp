//Aleksander "kaalex" Kramarz

#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <map>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#define x first
#define y second
using namespace std;

int z, n;
double s[2000], sum;

bool check(int k, double d)
{
	double x = sum-d;
	for(int i = 0; i < n; i++)
	{
		if(i == k)
			continue;
		if(s[i] >= s[k]+d)
			continue;
		if(s[k]+d-s[i] > x)
			return 0;
		x -= s[k]+d-s[i];
	}
	return 1;
}

int main()
{
	scanf("%d",&z);
	for(int f = 1; f <= z; f++)
	{
		scanf("%d",&n);
		sum = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%lf",s+i);
			sum += s[i];
		}
		printf("Case #%d: ", f);
		for(int i = 0; i < n; i++)
		{
			double p=0, q=1;
			for(int j = 0; j < 500; j++)
			{
				double d = (p+q)/2;
				if(check(i,d*sum))
					p = d;
				else
					q = d;
			}
			printf("%.6lf ", p*100);
		}
		puts("");
	}
}
