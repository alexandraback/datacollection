#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define in(n) scanf("%d",&n)
#define INF 1000000000000000000LL

string a,b;

ll abso(ll a)
{
	if(a<0)
		return -a;
	return a;
}

pair<ll,pair<string,string> > diff(string c1,string c2)
{
	ll num = 0;
	int i;
	for(i=0;i<c1.length();i++)
	{
		num = (10*num + c1[i]-'0');
	}
	ll num2 = 0;
	for(i=0;i<c1.length();i++)
	{
		num2 = (10*num2 + c2[i]-'0');
	}
	
	pair<ll,pair<string,string> > d;
	d = make_pair(abso(num-num2),make_pair(c1,c2));
	return d;
}

pair<ll,pair<string,string> > solve(int start)
{
	//cout<<"Solving : "<<start<<endl;
	if(start == a.length())
		return diff(a,b);
	
	pair<ll,pair<string,string> > d1,d2,d3;
	int i;
	string s1,s2;
	
	if(a[start] == '?' && b[start] == '?')
	{
		a[start] = '0';
		b[start] = '0';
		d1 = solve(start+1);

		a[start] = '0';
		b[start] = '1';
		//find maximum and minimum
		string s1,s2;
		s1 = a;
		s2 = b;
		for(i=start+1;i<s1.length();i++)
			{
				if(s1[i] == '?')
					s1[i] = '9';
				if(s2[i] == '?')
					s2[i] = '0';
			}
		d2 = diff(s1,s2);

		a[start] = '1';
		b[start] = '0';
		s1 = a;
		s2 = b;
		for(i=start+1;i<s1.length();i++)
			{
				if(s1[i] == '?')
					s1[i] = '0';
				if(s2[i] == '?')
					s2[i] = '9';
			}
		d3 = diff(s1,s2);
		
		a[start] = '?';
		b[start] = '?';
		//cout<<d1.first<<":"<<d2.first<<":"<<d3.first<<endl;
		if(d1.first <= d2.first && d1.first<=d3.first)
		{
			return d1;
		}
		else if(d2.first<=d1.first && d2.first<=d3.first)
		{
			return d2;
		}
		else
			return d3;		
	}

	else if(a[start] == '?')
	{
		if(b[start]!='0')
		{
			a[start] = '0'+(b[start]-'0'-1);
			//find maximum and minimum
			string s1,s2;
			s1 = a;
			s2 = b;
			for(i=start+1;i<s1.length();i++)
				{
					if(s1[i] == '?')
						s1[i] = '9';
					if(s2[i] == '?')
						s2[i] = '0';
				}
			d1 = diff(s1,s2);
		}
		else
		{
			d1 = make_pair(INF,make_pair(a,b));
		}

		a[start] = b[start];
		d2 = solve(start+1);

		if(b[start]!='9')
		{
			a[start] = '0'+(b[start]-'0'+1);
			s1 = a;
			s2 = b;
			for(i=start+1;i<s1.length();i++)
				{
					if(s1[i] == '?')
						s1[i] = '0';
					if(s2[i] == '?')
						s2[i] = '9';
				}
			d3 = diff(s1,s2);
		}
		else
		{
			d3 = make_pair(INF,make_pair(a,b));
		}

		a[start] = '?';
		
		if(d1.first <= d2.first && d1.first<=d3.first)
		{
			return d1;
		}
		else if(d2.first<=d1.first && d2.first<=d3.first)
		{
			return d2;
		}
		else
			return d3;
	}

	else if(b[start]=='?')
	{
		if(a[start]!='0')
		{
			b[start] = '0'+(a[start]-'0'-1);
			//find maximum and minimum
			string s1,s2;
			s1 = a;
			s2 = b;
			for(i=start+1;i<s1.length();i++)
				{
					if(s1[i] == '?')
						s1[i] = '9';
					if(s2[i] == '?')
						s2[i] = '0';
				}
			d1 = diff(s1,s2);
		}
		else
		{
			d1 = make_pair(INF,make_pair(a,b));
		}

		b[start] = a[start];
		d2 = solve(start+1);

		if(a[start]!='9')
		{
			b[start] = '0'+(a[start]-'0'+1);
			s1 = a;
			s2 = b;
			for(i=start+1;i<s1.length();i++)
				{
					if(s1[i] == '?')
						s1[i] = '0';
					if(s2[i] == '?')
						s2[i] = '9';
				}
			d3 = diff(s1,s2);
		}
		else
		{
			d3 = make_pair(INF,make_pair(a,b));
		}

		b[start] = '?';

		if(d1.first <= d2.first && d1.first<=d3.first)
		{
			return d1;
		}
		else if(d2.first<=d1.first && d2.first<=d3.first)
		{
			return d2;
		}
		else
			return d3;
	}

	else
	{
		//cout<<"Here"<<endl;
		if(a[start]==b[start])
		{
			d1 = solve(start+1);
		}
		else if(a[start]<b[start])
		{
			s1 = a;
			s2 = b;
			for(i=start+1;i<s1.length();i++)
				{
					if(s1[i] == '?')
						s1[i] = '9';
					if(s2[i] == '?')
						s2[i] = '0';
				}
				//cout<<"ok"<<endl;
			d1 = diff(s1,s2);
		}
		else
		{
			s1 = a;
			s2 = b;
			for(i=start+1;i<s1.length();i++)
				{
					if(s1[i] == '?')
						s1[i] = '0';
					if(s2[i] == '?')
						s2[i] = '9';
				}
			d1 = diff(s1,s2);
		}
		return d1;
	}

}

int main()
{
	int t,k;
	pair<ll,pair<string,string> > d;
	cin>>t;
	for(k=1;k<=t;k++)
	{
		cin>>a;
		cin>>b;
		//cout<<a<<":"<<b<<endl;
		d = solve(0);
		//if(d.second.first!=d.second.second)
 		//	cout<<a<<" "<<b<<" : "<<d.second.first<<" "<<d.second.second<<endl;
		cout<<"Case #"<<k<<": "<<d.second.first<<" "<<d.second.second<<endl;
	}
}