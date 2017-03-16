#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define pb push_back
#define mp make_pair
#define sz size()
#define x first
#define y second
#define forn(i, n) for(int i=0; i<(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef pair < int, int > PII;

int T;
string s1,s2;
vector <int> v1,v2;
int diff,c1,c2;

bool check(int c, string s)
{
	string ss="";
	forn(i,s.size())
	{
		ss=char(c%10+'0')+ss;
		c/=10;
	}

	forn(i,s.size())
		if(s[i]!='?' && s[i]!=ss[i])
			return 0;
	return 1;
}

string tra(int c)
{
	string res="";
	forn(i,s1.size())
	{
		res=char(c%10+'0')+res;
		c/=10;
	}
	return res;
}

void norm(int I, string s1, string s2)
{
	int p=0;
	forn(i,s1.size())
	{
		if(p==0 && s1[i]!='?' && s2[i]!='?' && s1[i]!=s2[i])
		{
			if(s1[i]>s2[i])
				p=1;
			else
				p=-1;
		}
		if(p==0)
		{
			if(s1[i]!='?')
				s2[i]=s1[i];
			else
			if(s2[i]!='?')
				s1[i]=s2[i];
			else
			{
				s1[i]='0';
				s2[i]='0';
			}
		}
		if(p==1)
		{
			if(s1[i]=='?')
				s1[i]='0';
			if(s2[i]=='?')
				s2[i]='9';
		}
		if(p==-1)
		{
			if(s1[i]=='?')
				s1[i]='9';
			if(s2[i]=='?')
				s2[i]='0';
		}
	}
	cout <<"Case #"<<I+1<<": "<<s1<<' '<<s2<<'\n';
}

int main()
{
	freopen("z.in", "rt", stdin);
	freopen("z.out", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	cin >>T;
	forn(I,T)
	{
		cin >>s1>>s2;
		v1.clear();
		v2.clear();
		diff=999999;

		forn(i,int(pow(10,s1.size())+0.001))
		{
			if(check(i,s1))
				v1.pb(i);
			if(check(i,s2))
				v2.pb(i);
		}

		forn(i,v1.size())
			forn(j,v2.size())
			{
				if(abs(v1[i]-v2[j])<diff)
				{
					diff=abs(v1[i]-v2[j]);
					c1=v1[i];
					c2=v2[j];
				}
			}
		//cout <<s1<<' '<<s2<<' '<<diff<<endl;
		cout <<"Case #"<<I+1<<": "<<tra(c1)<<' '<<tra(c2)<<'\n';
	}

	return 0;
}
