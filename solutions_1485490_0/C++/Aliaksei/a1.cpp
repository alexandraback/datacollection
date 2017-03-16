#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <ctime>
using namespace std;
vector <vector<int> > g;
vector <bool> used;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	for (int st=0; st<t; ++st)
	{
		printf ("Case #%d:", st+1);

		int n, m;
		long long a, b, lb;
		bool flag;
		cin>>n>>m;
		vector <pair<long long, int> > g;
		vector <pair<long long, int> > v;
		for (int i=0; i<n; ++i)
		{
			cin>>a>>b;
			if (i==0) {g.push_back(make_pair(a, b)); lb=b;}
			else if(b==lb) (g.end()-1)->first+=a;
			else {g.push_back(make_pair(a, b)); lb=b;}
		}
n=g.size();
		for (int i=0; i<m; ++i)
		{
			flag=false;
			cin>>a>>b;
			for (int j=0; j<n; ++j)
				if (g[j].second==b) flag=true;
			if (flag) v.push_back(make_pair(a, b));
		}

		m=v.size();
		
		

	
		long long bst=0;
		if (n==2)
			for (int i=0; i<m+1; ++i)
			{
				long long bt=0;
				long long a0=g[0].first;
				long long a1=g[1].first;
				for (int j=0; j<i; ++j)
					if (v[j].second==g[0].second) {
						bt+=min(a0, v[j].first);
						a0-=min(a0, v[j].first);
					}
				for (int j=i; j<m; ++j)
					if (v[j].second==g[1].second) {
						bt+=min(a1, v[j].first);
						a1-=min(a1, v[j].first);
					}
				bst=max(bst, bt);
			}
		else if (n==1)
		{
			long long bt=0;
				long long a0=g[0].first;

			for (int i=0; i<m; ++i)
				if (v[i].second==g[0].second) {
						bt+=min(a0, v[i].first);
						a0-=min(a0, v[i].first);
					}
			bst=max(bst, bt);

		}
		else if (n==3)
		{
			if (g[0].second!=g[2].second)
				for (int i=0; i<m+1; ++i) {
					for (int j=i; j<m+1; ++j)
					{
						long long bt=0;
				long long a0=g[0].first;
				long long a1=g[1].first;
				long long a2=g[2].first;
				for (int k=0; k<i; ++k)
					if (v[k].second==g[0].second) {
						bt+=min(a0, v[k].first);
						a0-=min(a0, v[k].first);
					}
				for (int k=i; k<j; ++k)
					if (v[k].second==g[1].second) {
						bt+=min(a1, v[k].first);
						a1-=min(a1, v[k].first);
					}
				for (int k=j; k<m; ++k)
					if (v[k].second==g[2].second) {
						bt+=min(a2, v[k].first);
						a2-=min(a2, v[k].first);
					}
					bst=max(bst, bt);
					}
					
				}
			else
			{
					for (int i=0; i<m+1; ++i) {
					for (int j=i; j<m+1; ++j)
					{
						long long bt=0;
				long long a0=g[0].first;
				long long a1=g[1].first;
				long long a2=g[2].first;
				for (int k=0; k<i; ++k)
					if (v[k].second==g[0].second) {
						bt+=min(a0, v[k].first);
						a0-=min(a0, v[k].first);
					}
				for (int k=i; k<j; ++k)
					if (v[k].second==g[1].second) {
						bt+=min(a1, v[k].first);
						a1-=min(a1, v[k].first);
					}
				for (int k=j; k<m; ++k)
					if (v[k].second==g[2].second) {
						bt+=min(a2, v[k].first);
						a2-=min(a2, v[k].first);
					}
bst=max(bst, bt);
					}
					
				}

					long long bt=0;
					long long a0=g[0].first+g[2].first;
					for (int i=0; i<m; ++i)
				if (v[i].second==g[0].second) {
						bt+=min(a0, v[i].first);
						a0-=min(a0, v[i].first);
					}
			bst=max(bst, bt);



			}






		}
		
		cout<<" "<<bst;
		
		
		printf("\n");


	}


}