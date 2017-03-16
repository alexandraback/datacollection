#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A.out", "w", stdout);
	
	
	int ncase;
	//scanf("%d",&ncase);
	cin>>ncase;

	int t,i;
	
	for(t=0;t<ncase;t++)
	{
		string str;long n,L;
		cin>>str>>n;
		L=str.size();
		int k=0;
		long ttl=0;
		long cnt=0;
		int s2[1000];
		const char* nm=str.c_str();
		for(i=L-1;i>=0;i--)
		{
			if (!(*(nm+i)=='a'||*(nm+i)=='e'||*(nm+i)=='i'||*(nm+i)=='o'||*(nm+i)=='u'))
			{
				k++;
				if (k>=n) 
				{
						s2[ttl]=i;
						ttl++;
				}
			}
			else
			{
				k=0;
			}
		}
		int l1,l2;
		
		long ans=0;
		for(i=0;i<ttl-1;i++)
		{
			l1=s2[i]-s2[i+1];
			l2=L-1-s2[i]-n+2;
			ans+=l1*l2;

		}
		
		l1=s2[ttl-1]+1;
		l2=L-1-s2[ttl-1]-n+2;
		ans+=l1*l2;	
		if (ttl==0) ans=0;
		cout<<"Case #"<<t+1<<": "<<ans<<endl;
	}
}