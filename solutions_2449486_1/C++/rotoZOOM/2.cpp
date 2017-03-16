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

int mas[110][110];
int t[110][110];

int main ()
{
	freopen ("input.txt","rt",stdin);
	freopen ("output.txt","wt",stdout);
	int test;

	scanf ("%d",&test);
	for (int step=1;step<=test;step++)
	{
		int n,m,i,j,mx;

		scanf ("%d %d",&n,&m);
		for (i=0;i<n;i++) for (j=0;j<m;j++) scanf ("%d",&mas[i][j]);
		memset (t,0x7f,sizeof (t));
		for (i=0;i<n;i++)
		{
			mx=0;
			for (j=0;j<m;j++)mx=max(mas[i][j],mx);
			for (j=0;j<m;j++)t[i][j]=min(t[i][j],mx);
		}
		for (i=0;i<m;i++)
		{
			mx=0;
			for (j=0;j<n;j++)mx=max(mas[j][i],mx);
			for (j=0;j<n;j++)t[j][i]=min(t[j][i],mx);
		}
		for (i=0;i<n;i++)
		{
			for (j=0;j<m && mas[i][j]==t[i][j];j++);
			if (j<m) break;
		}
		printf ("Case #%d: %s\n",step,i<n?"NO":"YES");
	}
	return 0;
}