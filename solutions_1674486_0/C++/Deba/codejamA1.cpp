
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctype.h>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

#define CLR(x) memset((x),0,sizeof(x))
#define pb push_back
#define sz size()
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORALL(i,x) for(int i=0;i<x.size();i++)
#define FORALLR(i,x) for(int i=x.size()-1;i>=0;i--)
#define SWAP(x,y) (x)+=(y);y=(x)-(y);x=(x)-(y);
#define lint long long
#define MAX 1000
#define INF 1<<30

typedef vector<int> vi;
typedef vector<string> vs;

int cases,caseno;
struct node
{
	vi adj;
}nodes[10001];
int dist[1001];
int N;
void input()
{
	
	cin >> N;
	int a,b;
	FOR(i,N)
	{
		nodes[i+1].adj.clear();
	}

	FOR(i,N)
	{
		cin >> a;
		FOR( j, a )
		{
			cin >> b;
			nodes[i+1].adj.push_back( b );
		}
	}
	//cin >> a;
	
}
bool isDiamond(int s)
{
	bool diamond = false;
	CLR(dist);
	queue< int > q;
	q.push( s );
	dist[s] = 1;

	while( !q.empty() )
	{
		int u = q.front();
		q.pop();

		for( int i = 0; i < nodes[u].adj.size(); i++)
		{
			int v = nodes[u].adj[i];
			if( dist[v] >= 2)
			{
				diamond = true;
				break;
			}
			if( dist[v] ) continue;
			dist[v] = dist[u] + 1;
			q.push( v );
		}
		if( diamond ) break;
	}
	return diamond;
}
void process()
{
	bool diamond = false;
	FOR( i , N )
	{
		diamond = isDiamond( i+1 );
		if( diamond ) break; 
	}
	cout << "Case #"<< (++caseno)<< ": ";
	if( diamond )
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}
int main()
{
	freopen("input.txt", "r", stdin );
	freopen("outA1.txt", "w", stdout );
	cin >> cases;
	while( cases-- )
	{
		input();
		process();
	}
}