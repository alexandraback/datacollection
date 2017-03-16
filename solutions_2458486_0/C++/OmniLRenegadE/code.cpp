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
bool work(int pos, bool msk[], int n, vector <vector <int> > &gr, int *type, int *keys, int *buf, bool *fl)
{
	bool all=true;
	if (pos==n)
		return true;
	LL m=0;
	forn(i,n)
		if (fl[i])
			m+=1<<i;
	if (msk[m]>0)
		return false;
	msk[m]=1;
	forn(i,n)
		if (fl[i]==0 && keys[type[i]]>0)
		{
			fl[i]=1;
			keys[type[i]]--;
			forn(j,gr[i].size())
				keys[gr[i][j]]++;
			buf[pos]=i;
			if (work(pos+1,msk,n,gr,type,keys,buf,fl))
				return true;
			forn(j,gr[i].size())
				keys[gr[i][j]]--;
			fl[i]=0;
			keys[type[i]]++;
		}
		return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("D-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int T,k,n,a,q;
	cin>>T;
	forn(t,T)
	{
		cout<<"Case #"<<(t+1)<<": ";
		cin>>k>>n;
		int keys[500]={0};
		forn(i,k)
		{
			cin>>a;
			a--;
			keys[a]++;
		}
		int *type=new int[n];
		vector <vector <int> > gr(n);
		forn(i,n)
		{
			cin>>type[i];
			type[i]--;
			cin>>q;
			forn(j,q)
			{
				cin>>a;
				a--;
				gr[i].push_back(a);
			}
		}
		bool msk[2000000]={0};
		int *buf=new int[n];
		bool *fl=new bool[n];
		forn(i,n)
		{
			fl[i]=0;
			buf[i]=0;
		}
		if (!work(0,msk,n,gr,type,keys,buf,fl))
			cout<<"IMPOSSIBLE";
		else
			forn(i,n)
				cout<<(buf[i]+1)<<' ';
		cout<<"\n";
	}
}