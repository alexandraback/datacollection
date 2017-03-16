#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>

#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define vpii vector <pair<int, int> >
#define vpll vector <pair<ll, ll> >
#define pll pair<ll, ll>

#define f first
#define s second

#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)

#define pb push_back
#define pob pop_back

#define max_size 100005
#define max_capacity INT_MAX

using namespace std;

ll visited[1000005];

ll reverse(ll n)
{
	ll ret = 0;
	while(n>0)
	{
		ret = ret*10 + n%10;
		n /= 10;
	}

	return ret;
}

ll bfs(ll n)
{
	for(ll i=1; i<=n; i++)
		visited[i] = 0;

	queue <ll> bfs;
	bfs.push(1);
	visited[1] = 1;
	while(!bfs.empty())
	{
		ll cur = bfs.front();
		bfs.pop();

		if(cur==n)
			break;

		if(!visited[cur+1])
		{
			visited[cur+1] = visited[cur]+1;
			bfs.push(cur+1);
		}

		if(!visited[reverse(cur)])
		{
			visited[reverse(cur)] = visited[cur]+1;
			bfs.push(reverse(cur));
		}
	}

	return visited[n];
}

int main()
{
	ll t;
	cin>>t;
	for(ll c=1; c<=t; c++)
	{
		ll n;
		cin>>n;
		cout<<"Case #"<<c<<": ";
		cout<<bfs(n)<<endl;
	}

	return 0;
}