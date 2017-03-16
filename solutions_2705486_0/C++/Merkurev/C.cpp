#include <iostream>
#include <map>
using namespace std;


char s[4005];


int treeNxt[5005005][26];
bool isFin[5005005];

const int root = 1;
int lst = 2;

struct State
{
	int pos, woe, node;
	State() : pos(), woe(), node() {}
	State(int pos, int woe, int node) : pos(pos), woe(min(woe, 5) ), node(node) {}
	bool operator < (const State & Oth) const
	{
		if (node != Oth.node)
			return node < Oth.node;
		if (woe != Oth.woe)
			return woe < Oth.woe;
		return false;
	}
};


map <State, int> dp[4005];

void init()
{
	while (true)
	{
		s[0] = 0;
		scanf("%s", s);
		if (s[0] == 0)
			break;
		int cur = root;
		int len = strlen(s);
		for (int i = 0; i < len; i++)
		{
			int ch = s[i] - 'a';
			if (treeNxt[cur][ch] == 0)
			{
				treeNxt[cur][ch] = lst++;
			}
			cur = treeNxt[cur][ch];
		}
		isFin[cur] = true;
	}
}
int len;

int answer;

void add(int i, State s, int d)
{
	if (i == len)
	{
		if (s.node == root)
			answer = min(answer, d);
		return;
	}
	if (dp[i].count(s) == 0)
	{
		dp[i][s] = d;
	}
	else
	{
		dp[i][s] = min(dp[i][s], d);
	}
}

int main()
{
	freopen("dictationary.txt", "r", stdin);
	init();

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		scanf("%s", s);
		len = strlen(s);
		for (int i = 0; i <= len; i++)
			dp[i].clear();
		dp[0][State(0, 5, root) ] = 0;
		
		answer = len;

		for (int i = 0; i < len; i++)
		{
			int ch = s[i] - 'a';

			for (auto it = dp[i].begin(); it != dp[i].end(); it++)
			{
				State cur = it->first;
				int dist = it->second;
				for (int c = 0; c < 26; c++)
				{
					int nnode = treeNxt[cur.node][c];
					int nwoe = cur.woe + 1;
					int ndist = dist;

					if (c != ch)
					{
						if (nwoe < 5)
							continue;
						nwoe = 0;
						ndist = dist + 1;
					}
					else
					{
						int dsgfds = 0;
					}

					if (nnode != 0)
					{
						State nx = State(i + 1, nwoe, nnode);
						add(i + 1, nx, ndist);
					}
					if (isFin[nnode] )
					{
						State nx = State(i + 1, nwoe, root);
						add(i + 1, nx, ndist);
					}
				}
			}
		}
		printf("Case #%d: %d\n", t + 1, answer);
	}


	return 0;
}