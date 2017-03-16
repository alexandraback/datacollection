#include<bits/stdc++.h>
#define ll long long

using namespace std;

int reverseNum(int n)
{
	int ans = 0;
	while(n>0)
	{
		ans*=10;
		ans+=n%10;
		n/=10;
	}
	return ans;
}
int shortestTo[2000005];
vector<pair<int,int> > neb;
bool visited[2000005];
int dist[2000005];
int shortestPath(int n)
{
	if(shortestTo[n]<10000000)return shortestTo[n];
	int st = 1;
	queue<int> q;
	int cur,nn;
	q.push(st);
	fill(visited, visited+2000005, 0);
	fill(dist, dist+2000005, 10000000);
	dist[st] = 1;
	while(!q.empty())
	{
		cur = q.front(); q.pop();
		visited[cur] = true;
		if(cur == n)
		{
			shortestTo[cur] = dist[cur];
			return dist[cur];
		}
		else
		{
			nn = neb[cur].first;
			if(nn<2000005){ 
			if(!visited[nn])
			{
				dist[nn] = dist[cur]+1;
				q.push(nn);
				visited[nn] = true;
				shortestTo[nn] = dist[nn];
			}
			}
			nn = neb[cur].second;
			if(nn<2000005){
			if(!visited[nn])
			{
				dist[nn] = dist[cur]+1;
				q.push(nn);
				visited[nn] = true;
				shortestTo[nn] = dist[nn];
			}}
		}
	}
	return 10000000;
}


int main()
{
	int t;
	cin>>t;
	pair<int,int> npair;
	fill(shortestTo,shortestTo+2000005, 10000000);
	for(int i=0;i<=1000000;++i)
	{
		npair = make_pair(i+1, reverseNum(i));
		neb.push_back(npair);
	}
	int n;
	for(int i=1;i<=t;++i)
	{
		cin>>n;
		cout<<"Case #"<<i<<": "<<shortestPath(n)<<endl;
	}
	return 0;
}
