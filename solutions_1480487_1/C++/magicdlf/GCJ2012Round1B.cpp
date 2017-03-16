// GCJ2012Round1B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "string.h"
#include "stdio.h"
#include "vector"
#include "algorithm"

using namespace std;

vector<int> s;

int test(int n, double Y, int X)
{
	double score=s[n]+Y*X;
	double rest=1.0-Y;
	for(int i=0;i<s.size();i++)
	{
		if(i==n) continue;
		double need=0.0;
		if(s[i]<score)
		{
			need=(score-s[i])/X;
		}
		if(need>rest)
		{
			return 1;
		}
		rest-=need;
	}
	return 0;
}

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N;
		cin>>N;
		int X=0;
		s.clear();
		for(int i=0;i<N;i++)
		{
			int j;
			cin>>j;
			s.push_back(j);
			X+=j;
		}
		cout<<"Case #"<<tc+1<<":";
		for(int i=0;i<N;i++)
		{
			double l=0.0,r=1.0;
			double ans=1.0;
			for(int j=0;j<64;j++)
			{
				double mid=(l+r)/2;
				if(test(i,mid,X))
				{
					ans=min(ans,mid);
					r=mid;
				}
				else
				{
					l=mid;
				}
			}
			printf(" %.6lf",ans*100);
		}
		cout<<endl;
	}
	return 0;
}