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

#define p_b push_back
#define m_p make_pair


using namespace std;

long long p,q,gc,con;
string s;
int t,tt,i,j,num;

long long gcd(long long p,long long q)
{
	while (p!=0 && q!=0)
	{
		if (p>q) p=p%q;
		else q=q%p;

	}
	return p+q;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>t;
	for (tt=1; tt<=t; tt++)
	{
		cin>>s;
		for (i=0; i<(int)s.length(); i++)
		{
			if (s[i]=='/') break;
		}
		p=0;
		for (j=0; j<i; j++)
		{
			p=p*10+(s[j]-'0');
		}
		q=0;
		for (j=i+1; j<(int)s.length(); j++)
		{
			q=q*10+(s[j]-'0');
		}
		gc=gcd(p,q);
		p=p/gc;
		q=q/gc;
		con=1;
		num=0;
		while (con<q) 
		{	
			con*=2;
			num++;
		}
		if (con!=q)
		{
			cout<<"Case #"<<tt<<": impossible"<<endl;
			continue;
		}
		if (p==1 && q==2)
		{
			cout<<"Case #"<<tt<<": 1"<<endl;	
			continue;
		}
		if (p>(q/2))
		{
			cout<<"Case #"<<tt<<": 1"<<endl;
			continue;	
		}
		num=0;
		while (p<(q/2))
		{
			q=q/2;
			num++;
		}
		cout<<"Case #"<<tt<<": "<<num+1<<endl;	
	}
	return 0;
}


