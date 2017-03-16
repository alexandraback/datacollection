#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string.h>
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

int ML[1010];
int MH[1010];
int a[1010][1010];
int main()
{
	freopen("1.txt","w",stdout);
	int n,m,i,j;
	int t;
	cin>>t;

	for(int ii=1;ii<=t;ii++)
	{
		cin>>n>>m;
		memset(ML,0,sizeof(ML));
		memset(MH,0,sizeof(MH));

		int is=0;
		int k;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				cin>>a[i][j],MH[i]=max(MH[i],a[i][j]),ML[j]=max(ML[j],a[i][j]);
		}

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)if(a[i][j]<MH[i]&&a[i][j]<ML[j])
			{
				is=1;
				break;
			}
		}
		printf("Case #%d: ",ii);
		if(is)
			puts("NO");
		else
			puts("YES");
	}
}