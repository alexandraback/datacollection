#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef unsigned long long ull;

int main ()
{
	freopen ("input.txt","rt",stdin);
	freopen ("output.txt","wt",stdout);
	int test;

	scanf ("%d",&test);
	for (int step=1;step<=test;step++)
	{
		ull r,t,le,ri,m;
		long double all;
		scanf ("%llu %llu",&r,&t);
		le=1;
		ri=1000000000;
		while (le<ri)
		{
			m = (le+ri)>>1;
			all=(long double)r*(long double)m*2+(2+(m-1)*4)*m/2;
			if (all>t+0.1)ri=m;
			else le=m+1;
		}
		printf ("Case #%d: %llu",step,le-1);
		printf ("\n");
	}
	return 0;
}