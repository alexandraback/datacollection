#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define P2(x) (1LL<<(x))

const int maxn = 100;

int n;
int a[maxn], s[maxn];

int A[maxn], B[maxn], la, lb;

bool search ( int dep, int sum = 0 )
{
	if( la + lb > 0 && sum == 0 )
		return true;
		
	if( dep == 0 ) return false;
	int t = dep - 1;
	if( sum > 0 && sum - s[t] > 0 || sum < 0 && sum + s[t] < 0 ) 
	{
		return false;
	}
	
	A[la ++] = a[t];
	if( search( dep-1, sum + a[t] ) ) return true;
	la --;
	
	if( la > 0 )
	{
		B[lb ++] = a[t];
		if( search( dep-1, sum - a[t] ) ) return true;
		lb --;
	}
	
	if( search( dep-1, sum ) ) return true;
	
	return false;
}

int main ()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T ;	
	scanf("%d",&T);
	for(int t = 1; t <= T; t ++ )
	{
		scanf("%d",&n);
		for(int i = 0; i < n; i ++ ) scanf("%d", a+i);
		sort( a, a+n );	
		s[0] = a[0];
		for(int i = 1; i < n; i ++ ) s[i] = s[i-1] + a[i];
		la = lb = 0;
		printf("Case #%d:\n", t);
		if( !search(n) )
		{
			puts("Impossible");
			continue;
		}
		for(int i = 0; i < la; i ++ )
			printf("%d ", A[i]);
		puts("");
		for(int i = 0; i < lb; i ++ )
			printf("%d ", B[i]);
		puts("");
	}
	
	fclose(stdin);
	fclose(stdout);	

	return 0;
}
