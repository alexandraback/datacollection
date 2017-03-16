#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

const int SSIZE = 100;

vector<char*> pool;
stack<char*> ss;

struct St
{ int x, y, step; char * p; };

char * getstr()
{
	if(ss.empty())
	{
		for(int i=0; i<2000; i++)
		{
			char * s = new char[SSIZE];
			pool.push_back(s);
			ss.push(s);
		}
	}
	char * ret = ss.top();
	ss.pop();
	ret[0] = 0;
	return ret;
}

int abs(int n){ return n<0 ? -n : n; }

int dist(int x1, int y1, int x2, int y2)
{ return abs(x1-x2) + abs(y1-y2); }

bool visit[1000][1000];

int main()
{
	for(int i=0; i<2000; i++)
	{
		char * s = new char[SSIZE];
		pool.push_back(s);
	}

	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		for(int i=0; i<pool.size(); i++)
			ss.push(pool[i]);
		memset(visit, 0, sizeof(visit));

		queue<St> q;
		q.push((St){0, 0, 1, getstr()});
		while(!q.empty())
		{
			St cur = q.front(); q.pop();

			if(visit[cur.x+500][cur.y+500]){ ss.push(cur.p); continue; }
			visit[cur.x+500][cur.y+500] = true;
			int d = dist(cur.x, cur.y, x, y);
			if(d>400){ ss.push(cur.p); continue; }
			if(cur.x==x && cur.y==y)
			{
				printf("Case #%d: %s\n", t, cur.p);
				ss.push(cur.p);
				break;
			}

			char * s; int len = strlen(cur.p);
			s = getstr(); strcpy(s, cur.p);
			s[len+1] = 0; s[len] = 'E';
			q.push((St){cur.x+cur.step, cur.y, cur.step+1, s});
			s = getstr(); strcpy(s, cur.p);
			s[len+1] = 0; s[len] = 'W';
			q.push((St){cur.x-cur.step, cur.y, cur.step+1, s});
			s = getstr(); strcpy(s, cur.p);
			s[len+1] = 0; s[len] = 'N';
			q.push((St){cur.x, cur.y+cur.step, cur.step+1, s});
			s = getstr(); strcpy(s, cur.p);
			s[len+1] = 0; s[len] = 'S';
			q.push((St){cur.x, cur.y-cur.step, cur.step+1, s});

			ss.push(cur.p);
		}
		while(!q.empty())
		{
			St cur = q.front(); q.pop();
			ss.push(cur.p);
		}
		while(!ss.empty()) ss.pop();
	}

	for(int i=0; i<(int)pool.size(); i++)
		delete[] pool[i];
	return 0;
}

