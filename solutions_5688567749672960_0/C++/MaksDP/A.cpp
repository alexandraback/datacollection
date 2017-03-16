#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <queue>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

queue<ll> q;
const ll MAX=10000000;
bool used[MAX];
vector<ll> dist(MAX, MAX);

ll reverse(ll n)
{
	ll res=0;
	while(n>0)
	{
		res=res*10+n%10;
		n/=10;
	}
	return res;
}

map<ll, ll>::iterator it;

void bfs(ll res)
{
	while(!q.empty()) q.pop();

	q.push(0);
	memset(used, false, sizeof(used));
	used[0]=true;

	ll from, to, rev;

	while(!q.empty())
	{
		from=q.front();
		q.pop();
		
		if(!used[from+1])
		{
			used[from+1]=true;
			dist[from+1]=dist[from]+1;
			q.push(from+1);
		}
		rev=reverse(from);
		if(!used[rev])
		{
			used[rev]=true;
			dist[rev]=dist[from]+1;
			q.push(rev);
		}
		if((rev==res)||(from+1==res)) return;
	}
}



int main()
{
	FILE* inf=fopen("input.txt", "r");
	FILE* outf=fopen("output.txt", "w");

	int T;
	ll N;
	fscanf(inf, "%d", &T);
	dist[0]=0;

	for(int i=1; i<=T; i++)
	{
		fscanf(inf, "%lld", &N);
		ll res=0;

		if(dist[N]==MAX) bfs(N);
		res=dist[N];

		fprintf(outf, "Case #%d: %lld\n", i, res);
	}


	fclose(inf);
	fclose(outf);
	return 0;
}

