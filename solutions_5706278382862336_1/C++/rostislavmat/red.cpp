#include <stdio.h>
#include <fstream>
#include <iomanip> 
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stdlib.h> 
#include <set>
#include <queue>
#include <string>
#include <string.h>
using namespace std;
//#pragma comment(linker, "/STACK:999999999")
#define ll long long
const long long MAXN = 102;
const long long INF=999999999;
const long double eps=0.00000000001;

long long gcd(long long a,long long b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

vector <long long> p,w;

int res(long long a)
{
	for (int i=0;i<41;i++)
		if (a>=w[i])
			return i;
}


long long atoll(string s)
{
	long long r=0;
	for (int i=0;i<s.length();i++)
	{
		r*=10;
		r+=(s[i]-'0');
		
	}
	return r;
}



int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int q;
	cin>>q;
	long long z=1;
	p.push_back(z);
	for (int i=0;i<40;i++)
	{
		z*=2;
		p.push_back(z);
	}
	w=p;
	reverse(w.begin(),w.end());
	for (int ss=1;ss<=q;ss++)
	{
		cout<<"Case #"<<ss<<": ";
		string s;
		cin>>s;
		string A="";
		int j=0;
		while (s[j]!='/')
		{
			A+=s[j];
			j++;
		}
		j++;
		string B="";
		while (j<s.length())
		{
			B+=s[j];
			j++;
		}
		long long a,b;
		a=atoll(A);
		b=atoll(B);
		//cin>>a>>b;
		long long h=gcd(a,b);
		a/=h;
		b/=h;
		if (p[40]%b!=0)
		{
			cout<<"Impossible"<<endl;
		}
		else
		{
			long long x=p[40]/b;
			a*=x;
			cout<<res(a)<<endl;
		}
	}


	return 0;
}