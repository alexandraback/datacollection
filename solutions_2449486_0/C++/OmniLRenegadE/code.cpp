#pragma comment(linker, "/STACK:36777216")
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define mp make_pair
#define __int64 long long
#define LL long long
bool work(int n, int m, vector <vector <int> > &a)
{
	vector <vector <bool> > u(n, vector < bool > (m,false) );
	while (true)
	{
		int res=-1;
		forn(i,n)
			forn(j,m)
				if (!u[i][j] && (res==-1 || a[i][j]<res))
					res = a[i][j];
		if (res==-1)
			break;
		bool add=true;
		forn(i,n)
		{
			add=true;
			forn(j,m)
				if (!u[i][j] && a[i][j] != res)
				{
					add=false;
					break;
				}
			if (add)
				forn(j,m)
					u[i][j]=true;
		}
		forn(j,m)
		{
			add=true;
			forn(i,n)
				if (!u[i][j] && a[i][j] != res)
				{
					add=false;
					break;
				}
			if (add)
				forn(i,n)
					u[i][j]=true;
		}
		forn(i,n)
			forn(j,m)
				if (a[i][j]==res && !u[i][j])
					return false;
	}
	forn(i,n)
		forn(j,m)
		if (u[i][j]==false)
			return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int T;
	cin>>T;
	int n,m;
	forn(t,T)
	{
		cout<<"Case #"<<(t+1)<<": ";
		cin>>n>>m;
		vector <vector <int> > a(n,vector <int> (m));
		forn(i,n)
			forn(j,m)
			cin>>a[i][j];
		if (work(n,m,a))
			cout<<"YES";
		else
			cout<<"NO";
		cout<<"\n";
	}
}