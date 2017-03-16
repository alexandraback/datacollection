// Alfonso2 Peterssen
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define SZ(c) ((int)(c).size())
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)

typedef long long int64;

const int
	MAXN = 100;

vector< string > W;

struct edge
{
	int from, to;
	int firstError;
	int lastError;
	int errorCount;
};
vector< edge > G[MAXN];

struct state
{
	int u;
	int lastError;
};



int __dist[MAXN][MAXN];
#define dist(i, j) (__dist[(i)][(j) + 5])

bool __inQueue[MAXN][MAXN];
#define inQueue(i, j) (__inQueue[(i)][(j) + 5])

bool operator < (state & a, state & b)
{
	return dist(a.u, a.lastError) > dist(b.u, b.lastError);
}

int bfs(int from, int to)
{
	//queue< state > Q;
	priority_queue< state > Q;

	state start = (state){0, -5};

	memset(__dist, -1, sizeof(__dist));
	memset(__inQueue, 0, sizeof(__inQueue));

	dist(start.u, start.lastError) = 0;
	Q.push(start);
	inQueue(start.u, start.lastError) = true;

	int answer = (int)1e6;

	while (!Q.empty())
	{
		state top = Q.top();
		inQueue(top.u, top.lastError) = false;

		if (top.u == to)
			answer = min(answer, dist( top.u, top.lastError ));

		Q.pop();

		for (edge e: G[top.u])
		{
			if (e.errorCount > 0 && e.firstError - top.lastError < 5)
				continue ;

			state next = top;
			next.u = e.to;
			if (e.errorCount > 0)
				next.lastError = e.lastError;

			int nd = dist(top.u, top.lastError) + e.errorCount;

			if (dist(next.u, next.lastError) < 0 || nd < dist(next.u, next.lastError))
			{
				dist(next.u, next.lastError) = nd;
				if (!inQueue(next.u, next.lastError))
				{
					inQueue(next.u, next.lastError) = true;
					Q.push(next);
				}
			}
		}
	}

	return answer;
}

int main()
{

	ifstream dict("garbled_email_dictionary.txt");
	{
		string w;
		while (dict >> w)
		{
			W.push_back(w);
			assert(!w.empty());
		}
	}

	int testCount;
	cin >> testCount;

	FOR(test, 1, testCount)
	{

		REP(i, MAXN) G[i].clear();

		string S;
		cin >> S;

		REP(i, SZ(S))
		{
			for (string w : W)
				if (i + SZ(w) <= SZ(S))
				{
					bool noMatch = false;
					int firstError = -1;
					int lastError = -(int)1e6;
					int errorCount = 0;

					REP(k, SZ(w))
					{
						int pos = i + k;

						if (S[pos] != w[k])
						{
							if (firstError < 0) firstError = pos;

							if (pos - lastError < 5)
							{
								noMatch = true;
								break;
							}

							lastError = pos;
							errorCount++;
						}
					}

					if (noMatch) continue ;

					G[i].push_back((edge)
						{
							i, // from
							i + SZ(w), // to
							firstError,
							lastError,
							errorCount
						});
				}
		}

		printf( "Case #%d: %d\n", test, bfs(0, SZ(S)) );
	}

	return 0;
}
