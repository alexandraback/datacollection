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

int n, m, x, y, z, k, w, tc, tt;
char S[105];
int A[105];

int main ()
{
	scanf("%d", &tc);
	
	while (tc--)
	{
		scanf("%s", S);
		n = strlen(S);
		
		FOR(i, 0, n) if (S[i] == '-') A[i] = 0;
		else A[i] = 1;
		
		x = 0;
		FOD(i, n - 1, 0) if ((x + A[i]) % 2 == 0) x++;
		
		printf("Case #%d: %d\n", ++tt, x);
	}
	
	return 0;
}
		
