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

int T,n;
pair <string,string> s;
PII a[50];
int k,ANS;
map <string,int> mapp;
string d[50];

vector <PII> res;

PII f[50];
int check()
{
	forn(i,50)
		f[i]=mp(0,0);
	/*
	forn(i,res.size())
		cout <<d[res[i].x]<<' '<<d[res[i].y]<<endl;
	*/
	int ans=0;
	forn(i,n)
	{
		if(f[res[i].x].x!=0 && f[res[i].y].y!=0)
			ans++;
		f[res[i].x].x++;
		f[res[i].y].y++;
	}
	//cout <<ans<<endl;
	return ans;
}

int main()
{
	freopen("z.in", "rt", stdin);
	freopen("z.out", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	cin >>T;
	forn(I,T)
	{
		k=1;
		ANS=-1;
		mapp.clear();

		cin >>n;
		forn(i,n)
		{
			cin >>s.x>>s.y;
			if(mapp[s.x]==0)
			{
				d[k]=s.x;
				mapp[s.x]=k++;
			}
			if(mapp[s.y]==0)
			{
				d[k]=s.y;
				mapp[s.y]=k++;
			}

			a[i]=mp(mapp[s.x],mapp[s.y]);
		}

		forn(i,1<<n)
		{
			int c=i;
			res.clear();

			forn(j,n)
			{
				if(c%2)
					res.pb(a[j]);
				c/=2;
			}
			c=i;
			forn(j,n)
			{
				if(c%2==0)
					res.pb(a[j]);
				c/=2;
			}
			ANS=max(ANS,check());
		}

		cout <<"Case #"<<I+1<<": "<<ANS<<"\n";
		cerr <<"END\n";
	}

	return 0;
}
