#include  <stdio.h>   
#include <iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

void FileIn()
{
	freopen("A-small-attempt2.in","r",stdin);
	freopen("a.out","w",stdout);
}
double a[210];
int n;
double sum;
bool ok(double val,int id)
{
	double tmp = a[id] + sum * val/100.0;
	double lost = sum - sum * val/100.0;
	for(int i = 0; i < n; i ++)
	{
		if(i == id) continue;
		if(a[i] < tmp)
		{
			lost = lost - (tmp - a[i]);
			if(lost <= 0)
				return true;
		}
	}
	if(lost > 0)
		return false;
	else
		return true;
}
double getans(int id)
{
	double le = 0;
	double ri = 100;
	int cnt = 70;
	while(cnt --)
	{
		double mid = (le + ri) / 2.0;
		if(ok(mid,id))
			ri = mid;
		else
			le = mid;
	}
	return le;
}
int main()
{
	FileIn();
	int T;
	int cas;

	scanf("%d",&T);
	cas = 1;
	while(T--)
	{
		scanf("%d",&n);
		sum = 0;
		for(int i = 0; i < n ; i ++)
		{
			scanf("%lf",&a[i]);
			sum += a[i];	
		}
		
		printf("Case #%d:",cas++);
		for(int i = 0 ; i < n; i ++)
		{
			printf(" %.7lf",getans(i));
		}
		printf("\n");
	}
	return 0;
}
