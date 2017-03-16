#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

double dp[128][128];
bool used[128][128];

char keyb[128];
char lett[128];
int next[128];
int K, L, S;

void GetNext(char T[],int next[])
{
	next[1] = 0;
	int j=1;
	int k=0;
	while(j < T[0])
	{
		if((k==0)||(T[j]==T[k]))
		{
			j++;
			k++;
			next[j]=k;
		}
		else {
			k=next[k];
		}
	}
}

int GetMax()
{
	bool flag = true;
	int i, j;
	for(i = 1; i <= L; i ++)
	{
		int j;
		for(j = 0; j < K; j ++)
		{
			if(keyb[j] == lett[i])break;
		}
		if(j == K)flag = false;
	}
	if(flag == false)return 0;
	if(S < L)return 0;
	for(i = 2; i <= L; i ++)
	{
		for(j = 0; j+i <= L; j ++)
		{
			if(lett[j+1] != lett[j+i])break;
		}
		if(j+i > L)break;
	}
	i --;
	int ans = 1;
	S -= L;
	ans += S/i;
	//printf("%d\n", ans);
	return ans;
}

double dfs(int loc, int rest)
{
	int cur, nxt;
	double res = 0;
	cur = loc;
	if(rest <= 0)
	{
		return 0.0;
	}
	if(used[loc][rest])
	{
		return dp[loc][rest];
	}
	
	for(int i = 0; i < K; i ++)
	{
		loc = cur;
		while(loc > 0)
		{
			if(lett[loc]==keyb[i])
			{
				break;
			}
			else 
			{
				loc=next[loc];
			}
		}
		loc ++;
		if(loc == L+1)
		{
			res += (1.0 + dfs(loc, rest-1))/K;
		}
		else 
		{
			res += dfs(loc, rest-1)/K;
		}
	}
	loc = cur;
	dp[loc][rest] = res;
	used[loc][rest] = true;
	//printf("%d %d %lf\n", loc, rest, res);
	return res;
}
 
int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int t, cas;
	
	scanf("%d", &t);
	for(cas = 1; cas <= t; cas ++)
	{
		int n, m;
		int i, j, k;
		
		scanf("%d%d%d", &K, &L, &S);
		scanf("%s%s", keyb, lett+1);
		
		lett[0] = L+1;
		lett[L+1] = '#';
		GetNext(lett, next);
		
		memset(used, false, sizeof(used));
		double ansDp = dfs(1, S);
		double ansMx = (double)GetMax();
		printf("Case #%d: %lf\n", cas, ansMx-ansDp);
	}
	
	return 0;
}
