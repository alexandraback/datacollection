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

int T,c,d,v;
int a[10];
int ii[5];
bool u[33];

bool chk()
{
	bool used[33];
	memset(used,0,sizeof(used));
	forn(i,1<<d)
	{
		int t=i;
		int s=0;
		forn(i,d)
		{
			if(t%2)
				s+=a[i];
			t/=2;
		}
		if(s<=30)	
			used[s]=1;
	}
	forn(i,v+1)
		if(!used[i])
			return 0;
	return 1;
}

int main()
{
	freopen("z.in", "rt", stdin);
	freopen("z.out", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	cin >>T;
	forn(I,T)
	{
		cerr <<"I "<<I+1<<endl;
		cin >>c>>d>>v;
		memset(u,0,sizeof(u));
		forn(i,d)
		{
			cin	>>a[i];
			u[a[i]]=1;
		}

		int ans=9,tans=0;
		for(ii[0]=0; ii[0]<v+1; ii[0]++)
		for(ii[1]=0; ii[1]<v+1; ii[1]++)
		for(ii[2]=0; ii[2]<v+1; ii[2]++)
		for(ii[3]=0; ii[3]<v+1; ii[3]++)
        {
        	tans=0;
        	bool ok=1;
        	forn(i,4)
        		forn(j,4)
        			if(i!=j && ii[i] && ii[j] && ii[i]==ii[j])
        				ok=0;
        	forn(i,4)
        	{
        		if(u[ii[i]])
        			ok=0;
        	}
        	if(!ok)
        		continue;

        	forn(i,4)
        		if(ii[i])
        		{
        			tans++;
        			u[ii[i]]=1;
        	    	a[d]=ii[i];
        	    	d++;
        	    }
        	if(chk())
        		ans=min(ans,tans);

        	forn(i,4)
        		if(ii[i])
        		{
        			tans--;
        			u[ii[i]]=0;
        	    	d--;
        	    	a[d]=0;
        	    }
        }
        if(ans==9)
        	ans=5;
		cout <<"Case #"<<I+1<<": "<<ans<<endl;
	}

	return 0;
}
