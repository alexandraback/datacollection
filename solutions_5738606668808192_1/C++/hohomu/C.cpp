#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
#include<iterator>
using namespace std;
#define FOR(i,s,e) for(int i = (s); i < (e); i++)
#define FOE(i,s,e) for(int i = (s); i <= (e); i++)
#define FOD(i,s,e) for(int i = (s); i >= (e); i--)
#define CLR(a) memset(a,0,sizeof(a))
#define ll long long
#include<ctime>
#include<cmath>
#include<vector>

int n, m, y, z, w, x;
int A[40];

int main ()
{
	scanf("%d", &n);
	scanf("%d %d", &n, &m);
	
	printf("Case #1:\n");
	
	A[0] = 1;
	A[n - 1] = 1;
	
	for (int i = 2; i < n; i += 2)
	for (int j = i + 2; j < n; j += 2)
	for (int k = n - 3; k >= 1; k -= 2)
	for (int l = k - 2; l >= 1; l -= 2)
	{
		A[i] = A[j] = A[k] = A[l] = 1;
		FOR(I, 0, n) printf("%d", A[I]); 
		printf(" 3 2 3 2 7 2 3 2 3\n");
		m--;
		if (m == 0) return 0; 
		A[i] = A[j] = A[k] = A[l] = 0;
	}
	
	return 0;
}
	
		
