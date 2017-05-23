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

int main() 
{
	assert(freopen("in.txt", "r", stdin));
	assert(freopen("out.txt", "w", stdout));
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	forn(t, T)
	{
		uint64  n, ans = 0;
		uint64 r, v;
		cin>>r>>v;
		uint64 c = 0;
		while (c <= v)
		{
			c += ((r +1)*(r+1)-r*r);
			ans++;
			r+=2;
		}
		if (c >= v)
		{
			cout<<"Case #"<<t+1<<": "<<ans-1<<endl;
		}


	}
	return 0;
}