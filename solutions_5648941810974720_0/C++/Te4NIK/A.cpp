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

int a[10];
string s;
int kl[300];

bool check(string ts)
{
	forn(i,ts.size())
		if(kl[ts[i]]==0)
			return 0;
	forn(i,ts.size())
		kl[ts[i]]--;	
	return 1;
}

void solve()
{
	while(check("ZERO"))  //z
		a[0]++;
	while(check("TWO"))   //w
		a[2]++;
	while(check("SIX"))   //x
		a[6]++;
    while(check("EIGHT")) //g
		a[8]++;

    while(check("SEVEN")) //s
		a[7]++;
    while(check("THREE")) //h
		a[3]++;
    while(check("FOUR"))  //r
		a[4]++;

    while(check("ONE")) //o
		a[1]++;
    while(check("FIVE")) //v
		a[5]++;

    while(check("NINE")) //e
		a[9]++;
}

int main()
{
	freopen("z.in", "rt", stdin);
	freopen("z.out", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	int T;
	cin >>T;
	forn(I,T)
	{
		cin >>s;
		forn(i,10)
			a[i]=0;
		forn(i,300)
			kl[i]=0;

		forn(i,s.size())
			kl[s[i]]++;
		
		solve();

		cout <<"Case #"<<I+1<<": ";
		forn(i,10)
			forn(j,a[i])
				cout <<i;
		cout <<"\n";
	}

	return 0;
}
