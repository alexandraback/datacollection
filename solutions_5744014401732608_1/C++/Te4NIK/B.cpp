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

i64 t,n,m;
int a[55][55];

int main()
{
	freopen("z.in", "rt", stdin);
	freopen("z.out", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

    cin >>t;
    forn(I,t)
    {
    	cout <<"Case #"<<I+1<<": ";
    	cin >>n>>m;

    	forn(i,n)
    		forn(j,n)
    			a[i][j]=0;
    	for(int i=1; i<n-1; i++)
    		a[0][i]=1;
    	for(int i=1; i<n-1; i++)
    		for(int j=i+1; j<n-1; j++)
    			a[i][j]=1;

    	i64 st=1;
    	forn(i,n-3)
    		st*=2;

    	for(int i=n-2; i>0; i--)
    	{
    		if(m>=st)
    		{
    			m-=st;
    			a[i][n-1]=1;
    		}
    		st/=2;
    	}
    	if(m>0)
    	{
    		a[0][n-1]=1;
    		m--;
    	}

    	if(m>0)
    	{
    		cout <<"IMPOSSIBLE"<<endl;
    		continue;
    	}
    	cout <<"POSSIBLE"<<endl;
    	forn(i,n)
    	{
    		forn(j,n)
    			cout <<a[i][j];
    		cout <<endl;
    	}			
    }

	return 0;
}
