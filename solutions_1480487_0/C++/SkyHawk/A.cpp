//SkyHawk, CMC MSU

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

#define FOR(i,n) for(int i = 0;i < n;++i)
#define PII pair<int,int>
#define EPS 1e-9

int ar[1000];

int main(int argc, char** argv)
{
	freopen("INPUT.TXT","r",stdin);
	freopen("OUTPUT.TXT","w",stdout);
	int t;
	cin >> t;
	FOR(count,t)
	{
		int n;
		cin >> n;
		int a;
		double s = 0;	
		FOR(i,n)
		{
			cin >> ar[i];
			s+=ar[i];
		}
		//sort(ar.begin(),ar.end())
		double l = 0,r = s;
		while(r-l>EPS)
		{
			double m = (r+l)/2;
			double s1 = s;
			FOR(i,n)
				if(ar[i]<m)
					s1 -= m-(double)ar[i];
			if(s1>0)
				l = m;
			else
				r = m;
		}
		printf("Case #%d: ",count+1);
		//cerr << s << endl;
		FOR(i,n)
			if(ar[i]+EPS>l)
				printf("%.7f ",0.0000000000001);
			else
				printf("%.7f ",(l-(double)ar[i])*100.0/s);
		printf("\n");
	}
	return 0;
}
