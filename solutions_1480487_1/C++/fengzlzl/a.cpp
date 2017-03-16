#include <string> 
#include <vector> 
#include <algorithm> 
#include <numeric> 
#include <iostream> 
#include <sstream> 
#include <queue> 
#include <set> 
#include <map> 
#include <list> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cassert> 
#include <cmath> 
#include <complex> 
#include <cstring>
using namespace std; 

int tot, n;
int s[210];

int main() 
{
	freopen("a.txt", "r", stdin);
	freopen("aout.txt", "w", stdout);	
	int T, i, l, r, mid, cas=0;
	scanf("%d", &T);
	while (T--)
	{		
		scanf("%d", &n);
		tot = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d", &s[i]);
			tot += s[i];
		}
		printf("Case #%d:", ++cas);
		int ss = tot * 2;
		double v = tot*2/(double)n;
		int m = n;
		for (i=0; i<n; i++)
		  if (s[i]>=v)
		  {
		  	m--;
		  	ss -= s[i];
		  }
		
		for (i=0; i<n; i++)
		{
			double ans;
			if (s[i]>=v) ans = 0;
			else ans = (ss/(double)m - s[i])/(double)tot;
			if (ans<0) ans = 0;
			printf(" %.8lf",  ans*100);
		}
		printf("\n");
		
	}
        return 0; 

} 
/*
1
4 0 0 0 1

1
9 0 0 0 0 0 0 85 0 0

1
2 999 1


*/



