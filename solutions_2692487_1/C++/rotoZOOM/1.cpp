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

int mas[101];
int n;

int doit (int i, int v)
{
	while (i<n && mas[i]<v)
	{
		v+=mas[i++];
	}
	if (i>=n) return 0;
	if (v<2) return n-i;
	int r=0;
	while (v<=mas[i])
	{
		v+=v-1;
		r++;
	}
	return min(n-i,doit(i,v)+r);
}

int main ()
{
	freopen ("input.txt","rt",stdin);
	freopen ("output.txt","wt",stdout);
	int test;

	scanf ("%d",&test);
	for (int step=1;step<=test;step++)
	{
		int r,m,k,i,j,u,b,a;

		scanf ("%d %d",&a,&n);
		for (i=0;i<n;i++) scanf ("%d",&mas[i]);
		sort (mas,mas+n);
		r=doit(0,a);

		printf ("Case #%d: %d",step,r);
		printf ("\n");
	}
	return 0;
}