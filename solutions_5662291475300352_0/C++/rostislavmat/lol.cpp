#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

long long get(long long a)
{
	vector <long long> z;
	long long x=a;
	while (x!=0)
	{
		z.push_back(x%10);
		x/=10;
	}
	//reverse(z.begin(),z.end());
	long long y=0;
	for (long long i=0;i<z.size();i++)
	{
		y*=10;
		y+=z[i];
	}
	return y;
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	long long q;
	cin>>q;
	for (long long qq=0;qq<q;qq++)
	{
		cout<<"Case #"<<qq+1<<": ";
		long long n;
		cin>>n;
		vector <pair <long double,long double> > pos;
		for (long long i=0;i<n;i++)
		{
			long long d,h,m;
			cin>>d>>h>>m;
			for (long long i=0;i<h;i++)
			{
				pos.push_back(make_pair(d,(m+h)));
			}
		}
		sort(pos.begin(),pos.end());
		if (pos.size()<=1)
		{
			cout<<0<<endl;
			
		}
		else
		{
			long double sp=pos[0].second,sp1=pos[1].second;
			long double p=pos[0].first,p1=pos[1].first;
			/*long double t=p/360.0*sp;
			long double len=360.0*t/sp1;*/
			if (sp==sp1)
			{
				cout<<0<<endl;
				continue;
			}
			long double rr=abs(sp/(sp-sp1));
			rr*=sp1;
			long double t=(p1-p)*rr/360;
			long double len=360.0*t/sp;
			if (len+p>360)
			{
				cout<<0<<endl;
				continue;
			}
			p1=len+p;
			p=p1;
			if (sp1>sp)
				swap(sp,sp1);
			t=1*rr;
			len=360.0*t/sp;
			if (len+p>360)
			{
				cout<<0<<endl;
				continue;
			}
			else
			{
				cout<<1<<endl;
				continue;
			}
		}
	}
		
	return 0;
}



