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
char S[1005];
char pre[1005], last[1005];
bool ok;

int main ()
{
	scanf("%d", &tc);
	
	while(tc--)
	{
		scanf("%s", S);
		n = strlen(S);
		
		w = 0; k = 0;
		
		FOR(i, 1, n)
		{
			ok = 0;
			FOD(j, w - 1, 0) if (S[i] > pre[j]) { pre[w++] = S[i]; ok = 1; break; }
			else if (S[i] < pre[j]) { last[k++] = S[i]; ok = 1; break; }
			if (ok == 1) continue;
			if (S[i] >= S[0]) pre[w++] = S[i]; 
			else last[k++] = S[i];
		}
		
		printf("Case #%d: ", ++tt);
		FOD(i, w - 1, 0) printf("%c", pre[i]);
		printf("%c", S[0]);
		FOR(i, 0, k) printf("%c", last[i]);
		printf("\n");
	}
	
	return 0;
}
