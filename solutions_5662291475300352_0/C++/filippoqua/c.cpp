#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <fstream>
#include <climits>
#include <iostream>
#include <queue>
#define ii pair<int,int>
#define ll long long

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct line
{
	long double m;
	long double q;
};

struct point
{
	long double x;
	long double y;
};

point intersez(line a, line b)
{
	point ris;
	ris.x = (a.q-b.q)/(b.m-a.m);
	ris.y = ris.x*a.m+a.q;
	return ris;
}

int main()
{
	vector<line> v;
	vector<long double> tFinaliCandidati;
	int t;
	int n,h,d,m;
	line temp;
	in >> t;
	for(int i=0; i<t; i++)
	{
		v.clear();
		tFinaliCandidati.clear();
		in >> n;
		for(int j=0; j<n; j++)
		{
			in >> d >> h >> m;
			for(int k=m; k<=m+h-1; k++)
			{
				temp.m = (long double) 360/k;
				temp.q = d;
				v.push_back(temp);
				tFinaliCandidati.push_back((long double)(360-temp.q)/temp.m + 0.0001);
				tFinaliCandidati.push_back((long double)(360-temp.q)/temp.m - 0.0001);
			}
		}
		int ris = INT_MAX;
		for(int j=0; j<(int)tFinaliCandidati.size(); j++)
		{
			int conta = 0;
			long double coeffAng = 360/tFinaliCandidati[j];
			line li;
			li.m=coeffAng;
			li.q=0;
			for(int k=0; k<(int)v.size(); k++)
			{
				line li2=v[k];
				point incontro = intersez(v[k], li);
				//conta+=(incontro.y>=0 && incontro.y<=360);
				//cout << k << " " << incontro.x << " " << incontro.y << endl;
				if(li2.m>li.m)
				{
					while(incontro.y<=360)
					{
						conta+=(incontro.y>=0 && incontro.x>=0);
						li2.q-=360;
						incontro =intersez(li2,li);
					}
				}
				else if(li2.m<li.m)
				{
					while(incontro.y>=0)
					{
						conta+=(incontro.y<=360 && incontro.x>=0);
						li2.q-=360;
						incontro =intersez(li2,li);
					}
				}
				else if(li2.q==0)
					conta=INT_MAX;
				
			}
			//cout << tFinaliCandidati[j] << " " << conta << endl;
			ris = min(ris,conta);
		}
		out << "Case #" << i+1 << ": " << ris << endl;
	}
	return 0;
}


