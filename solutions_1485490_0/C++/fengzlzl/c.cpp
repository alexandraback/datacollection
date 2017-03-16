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
using namespace std; 

const int maxn = 400;

long long a[maxn], b[maxn];
int ta[maxn], tb[maxn];
int n, m;

long long cal(int typea, long long number, int l, int r)
{
	long long num=0;
	for (int j=l; j<r; j++)
		if (typea==tb[j]) num += b[j];
	return min(num, number);	
}


int main() 
{ 
	freopen("c.in", "r", stdin);
	freopen("cout.txt", "w", stdout);
int cas=0;
	long long ans, val;
	int T, i, j;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (i=0; i<n; i++)
		  scanf("%I64d%d", &a[i], &ta[i]);
		  
		if (n>1 && ta[0]==ta[1])
		{
			a[0]+=a[1];
			n--;
			a[1]=a[2];
			ta[1]=ta[2];
		}
		
		if (n>1 && ta[0]==ta[1])
		{
			a[0]+=a[1];
			n--;
		}
		
		if (n>2 && ta[1]==ta[2])
		{
			a[1]+=a[2];
			n--;
		}
		
		for (i=0; i<m; i++)
		  scanf("%I64d%d", &b[i], &tb[i]);
		if (n==1) ans = cal(ta[0], a[0], 0, m);
		else if (n==2)
		{
			ans = 0;
			for (i=0; i<=m; i++)
			{
				val = cal(ta[0], a[0], 0, i) + cal(ta[1], a[1], i, m);
				if (val>ans) ans = val;
			}
		}
		else if (n==3)
		{
			ans = 0;
			for (i=0; i<=m; i++)
			 for (j=i; j<=m; j++)
			 {
				val = cal(ta[0], a[0], 0, i)+cal(ta[1], a[1], i, j)+cal(ta[2], a[2], j, m);
				if (val>ans) ans = val;	 	
			 }
			if (ta[0]==ta[2])
				ans = max(ans, cal(ta[0], a[0]+a[2], 0, m));
		}
		printf("Case #%d: %I64d\n", ++cas, ans);
	}
        return 0; 

} 


