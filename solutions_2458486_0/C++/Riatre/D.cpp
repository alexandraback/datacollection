#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> F[1<<21];  // damn smallest

int main(void)
{
	freopen("D-small-attempt0.in","rt",stdin);
	freopen("D-small.out","wt",stdout);
	int T = 0;
	scanf("%d",&T);
	int TK = 0;
	while(T--)
	{
		printf("Case #%d: ",++TK);
		int K = 0;
		int N = 0;
		scanf("%d %d",&K,&N);
		
		int openWith[22] = {0};
		int contain[22][44] = {0};
		int ccnt[22] = {0};
		int keyCount[222] = {0};
		for(int i = 0;i < K;i++)
		{
			int x = 0;
			scanf("%d",&x);
			keyCount[x]++;
		}
		for(int i = 0;i < N;i++)
		{
			scanf("%d",&openWith[i]);
			scanf("%d",&ccnt[i]);
			for(int j = 0;j < ccnt[i];j++)
			{
				scanf("%d",&contain[i][j]);
			}
		}
		
		for(int i = 0;i < (1<<N);i++) F[i].clear();
		
		queue<int> q;
		q.push(0);
		while(!q.empty())
		{
			int x = q.front(); q.pop();
			int ckey[222] = {0};
			for(int i = 0;i < N;i++)
			{
				if(!(x&(1<<i))) continue;
				ckey[openWith[i]]--;
				for(int j = 0;j < ccnt[i];j++) ckey[contain[i][j]]++;
			}
			for(int i = 0;i < N;i++)
			{
				if(x&(1<<i)) continue;
				if(ckey[openWith[i]]+keyCount[openWith[i]] <= 0) continue;
				int nx = x|(1<<i);
				vector<int> ns = F[x];
				ns.push_back(i);
				if(F[nx].size() == 0) { F[nx] = ns; q.push(nx); }
				else if(F[nx] > ns) F[nx] = ns;
			}
		}
		
		if(F[(1<<N)-1].size() != N) puts("IMPOSSIBLE");
		else
		{
			for(int i = 0;i < N;i++)
			{
				printf("%d%c",F[(1<<N)-1][i]+1,i == N-1 ? '\n' : ' ');
			}
		}
	}
	return 0;
}
