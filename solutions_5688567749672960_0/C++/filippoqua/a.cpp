#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <fstream>
#include <climits>
#include <iostream>
#include <queue>
#define ii pair<int,int>
#define ll long long
#define MAXN 1000000

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
int dist[MAXN+1];

ll reverse(ll a)
{
	ll ris = 0;
	while(a>0)
	{
		ris*=10;
		ris+=a%10;
		a/=10;
	}
	return ris;
}

int main()
{
	for(ll i=0; i<=MAXN; i++)
	{
		dist[i]=MAXN;
	}
	dist[1]=1;
	queue<ll> bfs;
	bfs.push(1);
	while(!bfs.empty())
	{
		ll v = bfs.front();
		bfs.pop();
		if(v+1<=MAXN && v+1>0 && dist[v]+1<dist[v+1])
		{
			dist[v+1]=dist[v]+1;
			bfs.push(v+1);
		}
		ll rev = reverse(v);
		if(rev<=MAXN && rev>0 && dist[v]+1<dist[rev])
		{
			dist[rev]=dist[v]+1;
			bfs.push(rev);
		}
	}
	int t;
	ll n;
	in >> t;
	for(int i=0; i<t; i++)
	{
		in >> n;
		out << "Case #" << i+1 << ": " << dist[n] << endl;
	}
	return 0;
}
