#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;

int TEST;
vector<int> start;
vector<int> current;
vector<int> inside[22];
vector<int> arr;
int type[22];
int N,K,dp[(1 << 20) + 5];
bool vis[22];
vector<int> ANS;
int sol(int mask)
{
	if(mask == (1 << N) - 1)
		return dp[mask] = 1;
	if(dp[mask] != -1)
		return dp[mask];
	for(int i = 0 ; i < N; i++)
	{
		if(vis[i] || !start[type[i]])
			continue;
		start[type[i]]--;
		vis[i] = 1;
		for(int j = 0 ; j < inside[i].size(); j++)
			start[inside[i][j]]++;
		if(sol(mask | (1<<i)))
		{
			for(int j = 0 ; j < inside[i].size(); j++)
				start[inside[i][j]]--;
			start[type[i]]++;
			vis[i] = 0;
			return dp[mask] = 1;
		}
		for(int j = 0 ; j < inside[i].size(); j++)
			start[inside[i][j]]--;
		start[type[i]]++;
		vis[i] = 0;
	}
	return dp[mask] = 0;
}

void track(int mask,int now)
{
	if(mask == (1 << N) - 1)
	{
		ANS.push_back(now);
		return;
	}
	if(now != -1)
		ANS.push_back(now);
	for(int i = 0 ; i < N; i++)
	{
		if(vis[i] || !start[type[i]])
			continue;
		start[type[i]]--;
		vis[i] = 1;
		for(int j = 0 ; j < inside[i].size(); j++)
			start[inside[i][j]]++;
		if(sol(mask | (1<<i)))
		{
			track(mask | (1<<i),i);
			return;
		}
		for(int j = 0 ; j < inside[i].size(); j++)
			start[inside[i][j]]--;
		start[type[i]]++;
		vis[i] = 0;
	}
	return;
}

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("test.out","w",stdout);
	cin >> TEST;
	for(int T = 1; T <= TEST; ++T)
	{
		memset(dp,-1,sizeof dp);
		memset(vis,0,sizeof vis);
		map<int,int> mapper;
		int cnt = 0;
		cin >> K >> N;
		arr.clear();
		start.clear();
		start.resize(N,0);
		arr.resize(K);
		for(int i = 0 ; i < K; i++)
			cin >> arr[i];
		for(int i = 0 ; i < N; i++)
		{
			cin >> type[i];
			if(mapper.find(type[i]) == mapper.end())
				mapper[type[i]] = cnt++;
			type[i] = mapper[type[i]];
			int tmp;
			cin >> tmp;
			inside[i].resize(tmp);
			for(int j = 0; j < tmp; j++)
				cin >> inside[i][j];
		}
		for(int i = 0 ; i < arr.size(); i++)
			if(mapper.find(arr[i]) != mapper.end())
				start[mapper[arr[i]]]++;
		for(int i = 0 ; i < N; i++)
		{
			vector<int> tmp;
			for(int j = 0 ; j < inside[i].size(); ++j)
				if(mapper.find(inside[i][j]) != mapper.end())
					tmp.push_back(mapper[inside[i][j]]);
			inside[i].clear();
			for(int j = 0 ; j < tmp.size(); ++j)
				inside[i].push_back(tmp[j]);
		}
		ANS.clear();
		int ans = sol(0);
		if(ans == 0)
			cout << "Case #"<<T<<": IMPOSSIBLE"<<endl;
		else
		{
			track(0,-1);
			cout << "Case #"<<T<<":";
			for(int i = 0; i < ANS.size(); i++)
				cout << " " << ANS[i] + 1;
			cout << endl;
		}

	}
    return 0;
}
