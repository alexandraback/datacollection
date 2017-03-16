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

long long v[10100];
long long mas[11][12];

int main ()
{
	freopen ("input.txt","rt",stdin);
	freopen ("output.txt","wt",stdout);
	int test;

	scanf ("%d",&test);
	for (int step=1;step<=test;step++)
	{
		int i,j,r,n,e,k;

		scanf ("%d %d %d",&e,&r,&n);
		for (i=0;i<n;i++) scanf ("%lld",&v[i]);
		memset (mas,0,sizeof(mas));
		for (i=n-1;i>=0;i--)
		{
			for (j=e;j>=min(e,r);j--)
			{
				for (k=0;k<=j;k++)
				{
					int ost=min(e,j-k+r);
					mas[j][i]=max(mas[j][i],v[i]*k+mas[ost][i+1]);
				}
			}
		}

		printf ("Case #%d: %lld",step, mas[e][0]);
		printf ("\n");
	}
	return 0;
}