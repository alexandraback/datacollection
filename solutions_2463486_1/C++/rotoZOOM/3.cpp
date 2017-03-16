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

long long mas[40]={1,
4,
9,
121,
484,
10201,
12321,
14641,
40804,
44944,
1002001,
1234321,
4008004,
100020001,
102030201,
104060401,
121242121,
123454321,
125686521,
400080004,
404090404,
10000200001,
10221412201,
12102420121,
12345654321,
40000800004,
1000002000001,
1002003002001,
1004006004001,
1020304030201,
1022325232201,
1024348434201,
1210024200121,
1212225222121,
1214428244121,
1232346432321,
1234567654321,
4000008000004,
4004009004004,
100000020000001};


bool check (long long a)
{
	int b[32];
	int i,n=0;
	while (a)
	{
		b[n++]=a%10;
		a/=10;
	}
	for (i=0;i+i<n && b[i]==b[n-i-1];i++);
	return i+i>=n;
}

int main ()
{
	freopen ("input.txt","rt",stdin);
	freopen ("output.txt","wt",stdout);
	int test;

	int n=40;
/* generate
	for (long long i=1;;i++)
	{
		if (check(i))
		{
			long long di = i*i;
			if (di<i) break;
			if (check(di))
			{
				mas[n++]=di;
				fprintf (stderr,"%I64d\n",di);
			}
		}
	}
*/
	scanf ("%d",&test);
	for (int step=1;step<=test;step++)
	{
		long long a,b;
		int res=0;

		scanf ("%I64d %I64d",&a,&b);
		for (int i=0;mas[i]<=b;i++)
		{
			if (mas[i]>=a) res++;
		}
		printf ("Case #%d: %d\n",step,res);
	}
	return 0;
}