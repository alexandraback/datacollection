#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>
#include <vector>
#include <map>
#include <ctime>
#include <functional>
#include <utility>

#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double

using namespace std;

int t,tt,i,zn;
//string s,cur,buf;
ll x,l,Left,Right;
string s;
char cur;

void print(int x)
{
	cout<<"Case #"<<tt<<": "<<(x==1 ? "YES" : "NO")<<endl;
	return;
}

char mult(int zn1,char c1,int zn2,char c2,int & zn)
{
	int curzn=1;
	char ans;
	if (c1=='1')
	{
		ans=c2;
		zn=zn1*zn2;			
	}
	if (c1=='i')
	{
		if (c2=='1')
			ans=c1;
		if (c2=='i')
			ans='1',curzn=-1;
		if (c2=='j')
			ans='k';
		if (c2=='k')
			ans='j',curzn=-1;
	   	zn=zn1*zn2*curzn;
	}
	if (c1=='j')
	{
		if (c2=='1')
			ans=c1;
		if (c2=='i')
			ans='k',curzn=-1;
		if (c2=='j')
			ans='1',curzn=-1;
		if (c2=='k')
			ans='i';
	   	zn=zn1*zn2*curzn;
	}
	if (c1=='k')
	{
		if (c2=='1')
			ans=c1;
		if (c2=='i')
			ans='j';
		if (c2=='j')
			ans='i',curzn=-1;
		if (c2=='k')
			ans='1',curzn=-1;
	   	zn=zn1*zn2*curzn;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output2.txt","w",stdout);
	cin>>t;
	for (tt=1; tt<=t; tt++)
	{
		cin>>l>>x;
		cin>>s;
		cur=s[0];
		zn=1;
		for (i=1; i<l; i++)
			cur=mult(zn,cur,1,s[i],zn);
		if (cur=='1')
		{
			if (zn==1 || x%2==0)
			{			
				print(0);
				continue;
			}
		}
		else
		{
			if (x%2==1 || x%4==0)
			{
				print(0);
				continue;
			}
		}
		cur=s[0];
		zn=1;
		for (Left=1; Left<l*min(x,(ll)16); Left++)
		{
			if (cur=='i' && zn==1) break;
			cur=mult(zn,cur,1,s[Left%l],zn);
		}
		if (!(cur=='i' && zn==1))
		{
			print(0);
			continue;
		}
		Left--;

		cur=s[l-1];
		zn=1;
		for (Right=l*x-2; Right>=l*(x-min(x,(ll)16)); Right--)
		{
			if (cur=='k' && zn==1) break;
			cur=mult(1,s[Right%l],zn,cur,zn);
		}
		if (!(cur=='k' && zn==1))
		{
			print(0);
			continue;
		}
		Right++;
		if (Left<Right)
			print(1);
		else
			print(0);
	}

	return 0;
}


    