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

int T,k,l,s;
string s1,s2;
vector <int> ans;
char c[10];

int cnt()
{
	int res=0;
	forn(i,s-s2.size()+1)
	{
		int ok=1;
		forn(j,s2.size())
		{
			if(c[i+j]!=s2[j])
				ok=0;
		}
		res+=ok;
	}
	return res;
}

void dfs(int len)
{
	if(len==s)
	{
		ans.pb(cnt());
		return;
	}
	forn(i,k)
	{
		c[len]=s1[i];
		dfs(len+1);
		c[len]=0;
	}
}

int main()
{
	freopen("z.in", "rt", stdin);
	freopen("z.out", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	cin >>T;
	forn(I,T)
	{
		cin >>k>>l>>s;
		cin >>s1>>s2;
		ans.clear();
		dfs(0);

		double mmax=-1;
		double sum=0;
		forn(i,ans.size())
		{
			mmax=max(mmax,1.0*ans[i]);
			sum+=ans[i];
		}
		cout <<"Case #"<<I+1<<": "<<mmax-sum/ans.size()<<endl;
		 /*
		forn(i,ans.size())
			cout <<ans[i]<<' ';
		cout <<endl;
		*/
	}

	return 0;
}
