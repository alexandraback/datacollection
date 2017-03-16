#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,int> pdi;
const int INF = (int)1e9;
const double EPS = 1e-9;

const char cstart = 'S', cend = 'E';	// cend processed first
const char LEFT = 1, RIGHT = 2, BOTH = 3;

const int nmax = 55;
int n;
char lane[nmax];
int s[nmax], p[nmax];
pdi y[nmax];
vector<int> adj[nmax];
bool vis[nmax];

struct event
{
	double t;
	char type;
	int a, b;

	event(double t, char type, int a, int b)
		:t(t), type(type), a(a), b(b)
	{}
	
	bool operator<(const event& o) const
	{
		if(abs(t - o.t) > EPS)
			return t < o.t;
		return type < o.type;
	}
};

void computePositions(double t)
{
	for(int i=0;i<n;i++)
		y[i] = pdi(p[i] + s[i] * t, i);
	sort(y, y+n);
}

void rmEdge(int a, int b)				// b to a
{
	for(int k=0;k<adj[b].size();k++)
		if(adj[b][k] == a)
		{
			adj[b][k] = adj[b].back();
			adj[b].pop_back();
			break;
		}	
}

void expand()
{
	for(int i=0;i<n;i++)
		if((i == 0 || y[i].first - y[i-1].first >= 5 - EPS) && (i == n-1 || y[i+1].first - y[i].first >= 5-EPS))
		{
			int a = y[i].second;
			lane[a] = BOTH;
			for(int j=0;j<adj[a].size();j++)
			{
				int b = adj[a][j];
				rmEdge(a, b);
			}
			adj[a].clear();
		}
}

void setlane(int u, char val)
{
	assert(lane[u] & val);
	if(lane[u] == BOTH)
	{
		lane[u] = val;
		for(int j=0;j<adj[u].size();j++)
			setlane(adj[u][j], BOTH - val);
		adj[u].clear();
	}
}

int dist(int a, int b)
{
	memset(vis, false, sizeof(vis));
	queue<pii> q;
	q.push(pii(0, a));
	vis[a] = true;
	while(!q.empty())
	{
		int u = q.front().second;
		int d = q.front().first;
		q.pop();
		if(u == b)
			return d;
		for(int i=0;i<adj[u].size();i++)
		{
			int v = adj[u][i];
			if(!vis[v])
			{
				q.push(pii(d+1, v));
				vis[v] = true;
			}
		}
	}
	return -1;
}

int main(int argc,char* argv[])
{
	int num_test_cases;
	scanf("%d",&num_test_cases);
	for(int test_case=1; test_case<=num_test_cases; test_case++)
	{
		scanf("%d", &n);
		for(int i=0;i<n;i++)
		{
			char ch;
			scanf(" %c%d%d", &ch, s+i, p+i);
			if(ch == 'L')
				lane[i] = LEFT;
			else
				lane[i] = RIGHT;
			adj[i].clear();
		}
		
		computePositions(0);
		expand();

		vector<event> events;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(s[i] == s[j])
					continue;
				double t = (double)(p[i] + 5 - p[j]) / (s[j] - s[i]);
				char type = s[i] > s[j] ? cstart : cend;
				if(t >= 0)
					events.push_back(event(t, type, i, j));
			}
		sort(events.begin(), events.end());

		double collisionTime = 0;
		for(int i=0;i<events.size() && !collisionTime;i++)
		{
			double t = events[i].t;
			char type = events[i].type;
			int a = events[i].a;
			int b = events[i].b;
			/*
			for(int i=0;i<n;i++)
				printf("%d ", lane[i]);
			printf("\n");
			printf("%lf %c %d %d\n", t, type, a, b);
			for(int i=0;i<n;i++)
			{
				printf("%d: ", i);
				for(int j=0;j<adj[i].size();j++)
					printf("%d ", adj[i][j]);
				printf("\n");
			}
			printf("\n");
			*/
			computePositions(t);
			if(type == cend)
			{
				rmEdge(a, b);
				rmEdge(b, a);
				expand();
			}
			else
			{
				if(lane[a] == BOTH && lane[b] == BOTH)
				{
					int d = dist(a, b);
					if(d != -1 && d % 2 == 0)
					{
						collisionTime = t;
						break;
					}
					if(d != 1)
					{
						adj[a].push_back(b);
						adj[b].push_back(a);
					}
				}
				else
				{
					for(int k=0;k<2;k++)
					{
						if(lane[a] < BOTH)
						{
							char otherlane = BOTH - lane[a];
							if(!(lane[b] & otherlane))
							{
								collisionTime = t;
								break;
							}
							setlane(b, otherlane);
						}
						swap(a, b);
					}
				}
			}
		}

		printf("Case #%d: ",test_case);
		if(collisionTime)
			printf("%lf\n", collisionTime);
		else
			printf("Possible\n");
	}
	return 0;
}
