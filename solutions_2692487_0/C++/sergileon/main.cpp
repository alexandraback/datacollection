#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <queue>
#include <functional>
#include <stack>
#include <cstdlib>
#include <complex>
#include <sstream>
#include <memory.h>

using namespace std;

typedef long long LL;	
typedef vector<int> vint;
typedef vector< vector<int> > vvint;
//typedef complex<double> cd;

int main()
{
//#ifdef DEBUG
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
//#endif
	int t;
	scanf("%d",&t);
	for ( int i = 1; i <=t; i ++)
	{
		int ans = 1000;
		int size , n;
		scanf("%d %d",&size,&n);
		vector <int> P;
		for ( int j = 0; j < n ; j ++)
		{
			int t;
			scanf("%d",&t);
			P.push_back(t);
		}
		sort(P.begin(),P.end());
		int pred[101];
		pred[100] = 0;
		int count = 0;
		for ( int j = 0 ; j < n; j ++)
		{
			while ( size <=P[j])
			{
				if ( size==1)
				{
					count = 10000000;
					break;
				}
				count++;
				size=size+ size- 1;
			}
			size+=P[j];
			pred[j] = count;
		}
		for ( int j = n - 1; j>=0; j --)
		{
			if (n-1 - j + pred[j] < ans)
			{
				ans = n-1 - j + pred[j];
			}
		}
		printf("Case #%d: %d\n",i,min(ans,n));
	}
	return 0;
}