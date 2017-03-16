#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 2000003;
const double eps = 1e-9;
int n;
int arr[1000];
double arr2[1000];


bool calc(double p,double val,double sum)
{
	double cur = val + sum*p;

	double ost = 1. - p; 
	
	for(int i=0;i<n-1;i++)
		if(arr2[i] < cur)
			ost -= (cur - arr2[i])/sum;
	if(ost < 0)
		return true;
	return false;
}

double solve(int v)
{
	double sum = 0;
	int sz = 0;
	for(int i=0;i<n;i++)
	{
		sum += arr[i];
		if(i != v)
			arr2[sz++] = arr[i];
	}
	sort(arr2,arr2+sz);

	double l = 0., r = 1.0;
	
	while(fabs(l-r) > eps)
	{
		double mid = (l+r)/2;

		if(!calc(mid, arr[v], sum))
			l = mid;
		else
			r = mid;
	}
	return l;
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int test;
	cin>>test;

	for(int i=0;i<test;i++)
	{
		printf("Case #%d: ",i+1);
		cin>>n;
		for(int j=0;j<n;j++)	
			cin>>arr[j];
		for(int j=0;j<n;j++)
			printf("%.6lf ",solve(j)*100.);
		printf("\n");
	}
	


	return 0;
}