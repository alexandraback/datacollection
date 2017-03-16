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

int tc, n, m, x, y, z, k, w, ans, longest, tmp, tt, tmp2;
int A[1005], v[1005], pos[1005];
int l[1005], LINK[1005], ed[1005];
int aa, bb;

void DFS(int x, int y, int t)
{
	v[x] = t; pos[x] = y;
	if (v[A[x]] == 0) DFS(A[x], y + 1, t);
	else if (v[A[x]] == t) ans = max(ans, y - pos[A[x]] + 1);
}

void build(int x, int y)
{
	LINK[w] = l[x]; l[x] = w; ed[w] = y; w++;
}

void find(int x, int y)
{
	longest = max(y, longest);
	for (int i = l[x]; i != -1; i = LINK[i])
	{
		if (v[ed[i]] == 0) find(ed[i], y + 1);
	}
}

int main ()
{
	scanf("%d", &tc);
	while (tc--)
	{
		memset(v, 0, sizeof(v));
		memset(l, -1, sizeof(l));
		memset(A, 0 , sizeof(A));
		w = 0;
		
		scanf("%d", &n);
		FOE(i, 1, n) 
		{
			scanf("%d", &A[i]);
			build(A[i], i);
		}
		
		ans = 0;
		FOE(i, 1, n) if (v[i] == 0) DFS(i, 1, i);
		
		memset(v, 0, sizeof(v));
		
		tmp = 0;
		
		FOE(i, 1, n) if (A[A[i]] == i && A[i] > i) 
		{
			tmp += 2;
			v[i] = 1;
			v[A[i]] = 1;
			
			longest = 0;
			find(i, 0);
			aa = longest;
			
			longest = 0;
			find(A[i], 0);
			bb = longest;
			
			tmp += aa + bb;
		}
		
		printf("Case #%d: %d\n", ++tt, max(ans, tmp));
	}
	
	return 0;
}
		
		
		
