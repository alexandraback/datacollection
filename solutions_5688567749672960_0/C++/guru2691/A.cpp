#include<bits/stdc++.h>

using namespace std;

vector<int> G[1000010];
int A[1000100];
int rev(int i)
{
	int ret = 0;
	while(i)
	{
		ret = i%10 + 10*ret;
		i /= 10;
	}
	return ret;
}

void pre()
{
	for(int i=1;i<=1000000;i++)
	{
		G[i].push_back(i+1);
		G[i].push_back(rev(i));
	}
	
	queue<int> Q;
	Q.push(1);
	A[1] = 1;
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		int sz = G[u].size();
		
		for(int i=0;i<sz;i++)
		{
			int v = G[u][i];
			if(A[v] ==0)
			{
				Q.push(v);
				A[v] = A[u]+1;
			}
		}
	}
}

int main()
{
	int T;
	cin>>T;
	pre();
	for(int idx=1;idx<=T;idx++)
	{
		int N;
		cin>>N;
		cout<<"Case #"<<idx<<": "<<A[N]<<'\n';
	}	
	return 0;
}
