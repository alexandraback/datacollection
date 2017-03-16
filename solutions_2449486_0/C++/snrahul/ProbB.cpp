#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>
#include <list>
#include <deque>
#include <map>
#include <bitset>
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;

int main()
{
	int t;
	ifstream in("B-small-attempt1.in");
	ofstream out("out.out");
	in >> t;
	int x[100][100],y[100][100];
	for(int cases = 1; cases <= t; cases++)
	{
		int n, m;
		in >> n >> m;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				in >> x[i][j];
				y[i][j] = 100;
			}
		}
		vector<int> rh(n),ch(m);
		for(int i=0;i<n;i++)
		{
			int maxh = 0;
			for(int j=0;j<m;j++)
			{
				if(maxh<x[i][j])
					maxh = x[i][j];
			}
			rh[i] = maxh;
		}
		for(int j=0;j<m;j++)
		{
			int maxh = 0;
			for(int i=0;i<n;i++)
			{
				if(maxh<x[i][j])
					maxh = x[i][j];
			}
			ch[j] = maxh;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(y[i][j]>rh[i])
					y[i][j] = rh[i];
			}
		}

		for(int j=0;j<m;j++)
		{
			for(int i=0;i<n;i++)
			{
				if(y[i][j]>ch[j])
					y[i][j] = ch[j];
			}
		}

		bool found = true;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(y[i][j]!=x[i][j])
					found = false;
			}
			if(!found)
				break;
		}
		
		if(found)
			out << "Case #" << cases << ": " << "YES" << endl;
		else
			out << "Case #" << cases << ": " << "NO" << endl;
	}
	system("pause");
	return 0;
}