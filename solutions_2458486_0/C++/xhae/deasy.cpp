#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char dp[1 << 20];
int next[1 << 20];
vector <int> has;
int n, req[20];
vector <int> data[20];
int hash[1 << 20];

char getAns(int stat)
{
	char &ret = dp[stat];
	if(ret != -1) return ret;

	if(stat == 0) return ret = true;
	
	vector <int> curHas = has;
	for(int i=0;i<n;i++) 
		if((stat & (1 << i)) == false)
		{
			curHas[req[i]]--;
			for(int j=0;j<data[i].size();j++) curHas[data[i][j]]++;
		}

	ret = false;

	for(int i=0;i<n;i++)
	{
		if(stat & (1 << i))
		{
			if(curHas[req[i]] > 0 && getAns(stat ^ (1 << i)))
			{
				ret = true;
				next[stat] = (stat ^ (1 << i));
				break;
			}
		}
	}

	return ret;
}	

int main(void)
{
	for(int i=0;i<20;i++) hash[1 << i] = i;
	int T;
	scanf("%d", &T);
	for(int caseN = 1;caseN <= T; caseN++)
	{
		memset(dp, -1, sizeof(dp));
		has = vector<int>(200, 0);
		int K;
		scanf("%d %d", &K, &n);
		for(int i=0;i<K;i++) 
		{
			int cur;
			scanf("%d", &cur);
			has[cur - 1]++;
		}
		for(int i=0;i<n;i++)
		{
			int cn;
			scanf("%d %d", req + i, &cn);
			req[i]--;
			data[i].clear();
			for(int j=0;j<cn;j++)
			{
				int inp;
				scanf("%d", &inp);
				data[i].push_back(inp - 1);
			}
		}

		printf("Case #%d: ", caseN);
		if(getAns((1 << n) - 1) == false) printf("IMPOSSIBLE\n");
		else
		{
			int cur = (1 << n) - 1;
			while(cur)
			{
				int ncur = next[cur];
				printf("%d ", hash[cur - ncur] + 1);
				cur = ncur;
			}
			printf("\n");
		}
	}

	return 0;
}
