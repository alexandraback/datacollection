#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <string.h>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

ifstream fin("input.txt");
ofstream fout("output.txt");

int tc;

map<ll,ll> m;
//int m[200];

int lu = 130000;
ll rez=0;

ll rev(ll x)
{
	ll l=0;
	while (x)
	{
		l = l*10+(x%10);
		x/=10;
	}
	return l;
}

int lv=0;

ll rec(ll x)
{
	if (m[x]) return m[x];
	lv++;
	if (lv>lu) return x;
	m[x] = x;
	m[x] = min(m[x],1+rec(x-1));
	if (x%10) m[x] = min(m[x],1+rec(rev(x)));
	lv--;
	return m[x];
}



ll n;
void bfs()
{
	ll l=1;
	ll mm=1,mn=0;
	while (true)
	{
		if (mm==n) {rez=l; return;}
		mn =0;
		if (mm+1<=n) mn = max(mn,mm+1);
		if (rev(mm)<=n) mn = max(mn,rev(mm));
		mm=mn;		
		//cout<<"level "<<l<<" done\n";
		l++;	
	}
}

int main()
{
	fin>>tc;

	m[1] = 1;

	for (int tt=1; tt<=tc; tt++)
	{
		fin>>n;
		rez=n;

		bfs();

		fout<<"Case #"<<tt<<": ";
		fout<<rez;
		fout<<'\n';
	}

	return 0;
}