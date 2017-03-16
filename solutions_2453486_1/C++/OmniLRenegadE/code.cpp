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
int check(string &s)
{
	int x=0,o=0,t=0;
	forn(i,s.length())
	{
		if (s[i]=='X')
			x++;
		if (s[i]=='O')
			o++;
		if (s[i]=='T')
			t++;
	}
	if (x==4 || x==3 && t==1)
		return -1;
	if (o==4 || o==3 && t==1)
		return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,q;
	cin>>n;
	forn(i,n)
	{
		cout<<"Case #"<<(i+1)<<": ";
		vector <string> a(4);
		forn(j,4)
			cin>>a[j];
		bool has=false;
		bool won=false;
		forn(j,4)
			forn(k,4)
				if(a[j][k]=='.')
					has=true;
		string s;
		forn(j,4)
		{
			s="";
			forn(k,4)
				s+=a[j][k];
			q=check(s);
			if (q==1 && !won)
				cout<<"O won";
			if (q==-1 && !won)
				cout<<"X won";
			if (q!=0)
			{
				won=true;
				break;
			}
		}
		forn(j,4)
		{
			s="";
			forn(k,4)
				s+=a[k][j];
			q=check(s);
			if (q==1 && !won)
				cout<<"O won";
			if (q==-1 && !won)
				cout<<"X won";
			if (q!=0)
			{
				won=true;
				break;
			}
		}
		s="";
		forn(j,4)
			s+=a[j][j];
		q=check(s);
		if (q==1 && !won)
			cout<<"O won";
		if (q==-1 && !won)
			cout<<"X won";
		if (q!=0)
			won=true;
		s="";
		forn(j,4)
			s+=a[3-j][j];
		q=check(s);
		if (q==1 && !won)
			cout<<"O won";
		if (q==-1 && !won)
			cout<<"X won";
		if (q!=0)
			won=true;
		if (!won && !has)
			cout<<"Draw";
		if (!won && has)
			cout<<"Game has not completed";
		cout<<"\n";
	}
}