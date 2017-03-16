#pragma comment(linker, "/STACK:65000000")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>

using namespace std;

#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vit vi::iterator
#define vpi vector<pii >
#define sq(x) (x)*(x)

int mas[1000];
int n;
int s;

bool calc(int pos, double val)
{
	double sum = 0.0;
	for(int i=0; i<n; ++i)
		if(i!=pos)
			if(mas[i]< mas[pos]+s*val )
				sum+=(mas[pos]+s*val-mas[i])/(double)s;
	return sum > 1.0 - val;
}

double bsrc(int pos)
{
	double from = 0;
	double to = 1;
	double ser;
	for(int i=0; i<50; ++i)
	{
		ser = (from+to)*0.5;
		if(calc(pos, ser))
			to = ser;
		else
			from = ser;
	}
	return to;
}

void test(int t)
{
	s=0;
	scanf("%d",&n);
	for(int i=0; i<n ;++i)
	{
		scanf("%d",mas+i);
		s+=mas[i];
	}
	printf("Case #%d:",t);
	for(int i=0; i<n; ++i)
		printf(" %.8lf",bsrc(i)*100.0);
	printf("\n");
}

int main()
{
	freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0; i<t; ++i)
		test(i+1);
	return 0;
}