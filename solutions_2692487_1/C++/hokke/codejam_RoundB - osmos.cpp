#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n,a[1000000];
int m;

void solve(int now,_int64 sum,int plus)
{

	if(m > plus+(n-now))
	{
		m=plus+n-now;
	}

	if(now== n)
	{
		return;
	}

	while(a[now] < sum && now < n)
	{
		sum+=a[now];
		now++;
	}

	if(m > plus+(n-now))
	{
		m=plus+n-now;
	}

	if(now== n)
	{
		return;
	}

	_int64 tmpsum=sum;
	int tmp=0;

	while(a[now] >= tmpsum && tmpsum > 1)
	{
		tmpsum=tmpsum*2-1;
		tmp++;
	}

	if(n-now <= tmp)
	{
		return;
	}
	else if(tmp != 0)
		solve(now,tmpsum, plus+tmp);

	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i,j,k;
	int c;
	int t;
	int mote;
	ifstream ifs;
	ifs.open("input.txt");
	
	ofstream ofs;
	ofs.open("output.txt");

	ifs >> t;

	for(c=0;c<t;c++)
	{
		ifs >> mote >> n;
		m=n;
		for(i=0;i<n;i++)
			ifs >> a[i];
		sort(a,a+n);
		solve(0,mote,0);
		ofs << "Case #" << c+1 << ": " << m <<endl;
	}

	return 0;
}

