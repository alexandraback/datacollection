#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>

#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>


using namespace std;



typedef double real;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<unsigned int, unsigned int> pip;
typedef vector<int> vint;







#define TNAME "similar"
#define forn(i, n) for(int i = 0; i < n; ++i)


unsigned long long s[10000001];


#define MODULE 1000000007 

int64 recurs(int64 l, int64 r, int64 st, int64 fn, int64 R, vint & v, int64 E)
{
	if (l > r) 
		return 0;
	int64 vmax = v[l];
	int pos = l;
	for (int i = l; i <= r; ++i)
	{
		if (vmax <= v[i])
		{
			vmax = v[i];
			pos = i;
		}
	}
	int64 e = min(E, st + R * (pos - l));
	int64 z = min( e,e -fn +  R * (r - pos));
	return z*vmax + recurs(l, pos-1, st, e- R , R, v, E) + recurs(pos+1, r, e - z +R, fn , R, v, E);



}


int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	forn(t, T)
	{
		int64 E, R, N, ans = 0, curr ;
		cin>>E>>R>>N;
		vint v(N);
		curr = E;
		forn(i, N)
		{
			cin>>v[i];

		}
		ans = recurs(0, N-1, E, 0 , R, v, E);
		cout<<"Case #"<<t+1<<": "<<ans<<endl;
		


	}
	return 0;
}