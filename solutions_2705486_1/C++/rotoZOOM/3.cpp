#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Trie
{
	Trie *next[26];
	bool last;

	Trie ()
	{
		memset (next,0,sizeof (next));
		last = false;
	}
};

Trie head;
string s;
char buf[5000];

map<int,int> cache[4001][5];

int doit (int idx, int last, Trie *node)
{
	if (!buf[idx]) return node==&head ? 0 : -1;
	if (cache[idx][last].count((int)node)) return cache[idx][last][(int)node];

	int c = buf[idx]-'a';

	int best = -1;
	for (int i=0;i<26;i++)
	{
		if (node->next[i])
		{
			if (last == 4 || i==c)
			{
				int ret = doit(idx+1,i==c ? min(4,last+1) : 0, node->next[i]);
				if (ret != -1 && (best == -1 || ret < best - (i!=c))) best = ret + (i!=c);
				if (node->next[i]->last)
				{
					ret = doit(idx+1,i==c ? min(4,last+1) : 0, &head);
					if (ret != -1 && (best == -1 || ret + (i!=c) < best)) best = ret + (i!=c);
				}
			}
		}
	}
	return cache[idx][last][(int)node] = best;
}

int main ()
{
	freopen ("input.txt","rt",stdin);
	freopen ("output.txt","wt",stdout);
	int test;

	FILE *f = fopen ("dictionary.txt","rt");
	while (fscanf (f,"%s",buf)==1)
	{
		Trie *node=&head;
		int i=0;
		while (buf[i])
		{
			int j = buf[i]-'a';
			if (!node->next[j])
			{
				node->next[j] = new Trie();
			}
			node = node->next[j];
			i++;
		}
		node->last = true;
	}
	fclose (f);
	scanf ("%d",&test);
	for (int step=1;step<=test;step++)
	{
		int r,n,m,k,i,j,u,b;
		scanf ("%s",buf);
		for (i=0;buf[i];i++)
		{
			for (j=0;j<5;j++) cache[i][j].clear();
		}
		r = doit(0,4,&head);
		printf ("Case #%d: %d\n",step,r);
	}
	return 0;
}