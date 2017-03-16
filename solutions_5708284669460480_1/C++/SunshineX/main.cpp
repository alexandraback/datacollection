#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int KK,LL,SS;
int num[26];
double dp[110][110][110];
bool f[110][110][110];
struct Trie
{
	int next[110][26],fail[110],end[110];
	int root,L;
	int newnode()
	{
		for(int i = 0;i < 26;i++)
			next[L][i] = -1;
		end[L++] = 0;
		return L-1;
	}
	void init()
	{
		L = 0;
		root = newnode();
	}
	void insert(char buf[])
	{
		int len = strlen(buf);
		int now = root;
		for(int i = 0;i < len;i++)
		{
			if(next[now][buf[i]-'A'] == -1)
				next[now][buf[i]-'A'] = newnode();
			now = next[now][buf[i]-'A'];
		}
		end[now]++;
	}
	void build()
	{
		queue<int>Q;
		fail[root] = root;
		for(int i = 0;i < 26;i++)
			if(next[root][i] == -1)
				next[root][i] = root;
			else
			{
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		while( !Q.empty() )
		{
			int now = Q.front();
			Q.pop();
			for(int i = 0;i < 26;i++)
				if(next[now][i] == -1)
					next[now][i] = next[fail[now]][i];
				else
				{
					fail[next[now][i]]=next[fail[now]][i];
					Q.push(next[now][i]);
				}
		}
	}
	double solve(){
		memset(dp,0,sizeof(dp));
		memset(f,false,sizeof(f));
		dp[0][0][0] = 1.0;
		f[0][0][0] = true;
		for(int i = 0;i < SS;i++)
			for(int j = 0;j < L;j++)
				for(int k = 0;k <= i;k++){
					if(!f[i][j][k])continue;
					for(int x = 0;x < 26;x++){
						if(num[x] == 0)continue;
						int nj = next[j][x];
						int nk = k + end[nj];
						f[i+1][nj][nk] = true;
						dp[i+1][nj][nk] += dp[i][j][k]*num[x]/KK;
					}
				}
		int Max = 0;
		for(int j = 0;j < L;j++)
			for(int k = 0;k <= SS;k++)
				if(f[SS][j][k])
					Max = max(Max,k);
		//printf("%d\n",Max);
		double ans = 0;
		for(int j = 0;j < L;j++)
			for(int k = 0;k <= Max;k++){
				ans += (Max-k)*dp[SS][j][k];
				//if(f[SS][j][k])
					//printf("%d %d %.6lf\n",j,k,dp[SS][j][k]);
			}
		return ans;
	}
}ac;

char str1[110],str2[110];

int main()
{
//        freopen("in.txt","r",stdin);
//    freopen("out","w",stdout);
    int T;
	int iCase = 0;
	scanf("%d",&T);
	while(T--){
		iCase++;
		scanf("%d%d%d",&KK,&LL,&SS);
		scanf("%s%s",str1,str2);
		memset(num,0,sizeof(num));
		for(int i = 0;i < KK;i++)
			num[str1[i]-'A']++;
		ac.init();
		ac.insert(str2);
		ac.build();
		printf("Case #%d: %.10lf\n",iCase,ac.solve());
	}
    return 0;
}
