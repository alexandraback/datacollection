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

bool check(uint64 v, uint64 r, uint64 k)
{
	uint64 c = (1+2*r)+4*(k-1)/2;
	if (c <=v/k)
		return true;
	else
		return false;

}


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
		uint64 i = 0;
		uint64 le = 1, ri = v;
		while (le != ri)
		{
			uint64 k = (le+ri)/2+1;
			if (check(v, r, k))
			{
				le = k;
			}
			else
			{
				ri = k-1;
			}

		}

			cout<<"Case #"<<t+1<<": "<<le<<endl;
		


	}
	return 0;
}