#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

typedef long long ll;

ifstream fin("input.txt");
ofstream fout("output.txt");

int tc;

int m=0;
int k,l,s;

string kk;
string key;

int c[30];

long double rez=0;

void check(string ss)
{
	int au=0;
	long double co=1;

	for (int i=0; i<ss.length(); i++)
		co*=(long double)(c[ss[i]-'A'])/k;
	for (int i=0; i<ss.length(); i++)
		if (ss.substr(i,l)==key) au++;
	m = max(au,m);
	co*=au;
	rez+=co;
}

string tmp;
void rec(int ll)
{
	if (ll==s) {check(tmp); return;}

	for (int i=0; i<30; i++)
		if (c[i])
		{
			tmp[ll]=i+'A';
			rec(ll+1);
		}
}

int main()
{
	fin>>tc;

	fout<<fixed<<setprecision(9);
	cout<<fixed<<setprecision(9);

	for (int tt=1; tt<=tc; tt++)
	{
		m=0;
		rez=0;
		for (int i=0; i<30; i++) c[i]=0;

		fin>>k>>l>>s;
		fin>>kk>>key;

		tmp = string(s,'A');
		for (int i=0; i<k; i++)
			c[kk[i]-'A']++;

		rec(0);

		rez = m-rez;

		fout<<"Case #"<<tt<<": ";
		fout<<rez;
		fout<<'\n';
		cout<<"Case #"<<tt<<": ";
		cout<<rez;
		cout<<'\n';
	}

	return 0;
}
