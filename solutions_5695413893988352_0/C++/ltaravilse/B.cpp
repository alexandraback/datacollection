#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),e.end()

struct res{
	bool defined;
	string st1, st2;
	long long calc() const
	{
		long long a,b;
		istringstream iss;
		iss.str(st1 + " "+ st2);
		iss.clear();
		iss >> a >> b;
		if(a>b)
			return a-b;
		return b-a;
	}
	bool operator<(const res &otra) const
	{
		if(calc() != otra.calc())
			return this->calc() < otra.calc();
		long long a,b,otraa,otrab;
		istringstream iss;
		iss.str(st1 + " "+ st2 + " "+ otra.st1 + " "+ otra.st2);
		iss.clear();
		iss >> a >> b >> otraa >> otrab;

		if(a != otraa)
			return a < otraa;
		return b < otrab;
	}
	bool operator==(const res &otra) const
	{
		return st1 == otra.st1 && st2 == otra.st2;
	}
};

int main()
{
	int casos;
	cin >> casos;
	for(int casito=1;casito<=casos;casito++)
	{
		string st1, st2;
		cin >> st1 >> st2;
		int n = st1.size();
		res r,aux;
		r.defined = false;
		aux.defined = true;
		for(int i=0;i<st1.size();i++)
		{
			if(st1[i] == '?' && st2[i] == '?')
			{
				string a1 = st1, b1 = st2;
				a1[i] = '0';
				b1[i] = '1';
				for(int j=i+1;j<n;j++)
				{
					if(a1[j] == '?')
						a1[j] = '9';
					if(b1[j] == '?')
						b1[j] = '0';
				}
				aux.st1 = a1;
				aux.st2 = b1;
				if(!r.defined || aux < r)
				{
					r.defined = true;
					r.st1 = aux.st1;
					r.st2 = aux.st2;
				}
				string a2 = st1, b2 = st2;
				a2[i] = '1';
				b2[i] = '0';
				for(int j=i+1;j<n;j++)
				{
					if(a2[j] == '?')
						a2[j] = '0';
					if(b2[j] == '?')
						b2[j] = '9';
				}
				aux.st1 = a2;
				aux.st2 = b2;
				if(!r.defined || aux < r)
				{
					r.defined = true;
					r.st1 = aux.st1;
					r.st2 = aux.st2;
				}
				istringstream iss;
				iss.str(st1.substr(0,i) + " "+ st2.substr(0,i));
				iss.clear();
				long long a,b;
				iss >> a >> b;
				if(i == 0 || a == b)
				{
					st1[i] = '0';
					st2[i] = '0';
				}
				else if(a < b)
				{
					st1[i] = '9';
					st2[i] = '0';	
				}
				else
				{
					st1[i] = '0';
					st2[i] = '9';
				}
			}
			else if(st1[i] == '?')
			{
				if(st2[i] != '0')
				{
					string a1 = st1, b1 = st2;
					a1[i] = b1[i]-1;
					for(int j=i+1;j<n;j++)
					{
						if(a1[j] == '?')
							a1[j] = '9';
						if(b1[j] == '?')
							b1[j] = '0';
					}
					aux.st1 = a1;
					aux.st2 = b1;
					if(!r.defined || aux < r)
					{
						r.defined = true;
						r.st1 = aux.st1;
						r.st2 = aux.st2;
					}
				}
				if(st2[i] != '9')
				{
					string a2 = st1, b2 = st2;
					a2[i] = b2[i]+1;
					for(int j=i+1;j<n;j++)
					{
						if(a2[j] == '?')
							a2[j] = '0';
						if(b2[j] == '?')
							b2[j] = '9';
					}
					aux.st1 = a2;
					aux.st2 = b2;
					if(!r.defined || aux < r)
					{
						r.defined = true;
						r.st1 = aux.st1;
						r.st2 = aux.st2;
					}
				}
				istringstream iss;
				iss.str(st1.substr(0,i) + " "+ st2.substr(0,i));
				iss.clear();
				long long a,b;
				iss >> a >> b;
				if(i == 0 || a == b)
					st1[i] = st2[i];
				else if(a < b)
					st1[i] = '9';	
				else
					st1[i] = '0';
			}
			else if(st2[i] == '?')
			{
				if(st1[i] != '9')
				{
					string a1 = st1, b1 = st2;
					b1[i] = a1[i]+1;
					for(int j=i+1;j<n;j++)
					{
						if(a1[j] == '?')
							a1[j] = '9';
						if(b1[j] == '?')
							b1[j] = '0';
					}
					aux.st1 = a1;
					aux.st2 = b1;
					if(!r.defined || aux < r)
					{
						r.defined = true;
						r.st1 = aux.st1;
						r.st2 = aux.st2;
					}
				}
				if(st1[i] != '0')
				{
					string a2 = st1, b2 = st2;
					b2[i] = a2[i]-1;
					for(int j=i+1;j<n;j++)
					{
						if(a2[j] == '?')
							a2[j] = '0';
						if(b2[j] == '?')
							b2[j] = '9';
					}
					aux.st1 = a2;
					aux.st2 = b2;
					if(!r.defined || aux < r)
					{
						r.defined = true;
						r.st1 = aux.st1;
						r.st2 = aux.st2;
					}
				}
				istringstream iss;
				iss.str(st1.substr(0,i) + " "+ st2.substr(0,i));
				iss.clear();
				long long a,b;
				iss >> a >> b;
				if(i == 0 || a == b)
					st2[i] = st1[i];
				else if(a < b)
					st2[i] = '0';	
				else
					st2[i] = '9';
			}
		}
		aux.st1 = st1;
		aux.st2 = st2;
		if(!r.defined || aux < r)
		{
			r.defined = true;
			r.st1 = aux.st1;
			r.st2 = aux.st2;
		}
		cout << "Case #"<<casito <<": "<< r.st1 <<" "<< r.st2 << endl;
	}
}