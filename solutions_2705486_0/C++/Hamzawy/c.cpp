/*
 * c.cpp
 *
 *  Created on: May 4, 2013
 *      Author: AhmedHamza
 */

#include<cstdio>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

const int maxN = 1000000; // the sum of the lengths of the string + 1
const int maxE = maxN * 2;
struct edge
{
		int from, to;
		char c;
};

int cN = 1; // count the nodes
edge edges[maxE]; // memseted with -1
bool isLeaf[maxE]; //memseted with 0

edge& getEdge(int ind, unsigned char c)
{
	int i = ((ind << 8) + c) % maxE; // da el hashing
	while (edges[i].from != -1)
	{
		if (edges[i].from == ind && edges[i].c == c)
			break;
		i = ++i % maxE;
	}
	return edges[i];
}

void insert(const char* str, int ind = 0)
{
	if (!*str)
	{
		isLeaf[ind] = true;
		return;
	}

	edge& e = getEdge(ind, *str);
	if (e.from == -1)
	{
		e.from = ind;
		e.to = cN++;
		e.c = *str;

	}
	insert(str + 1, e.to);
}

bool traverse(const char* str, int ind = 0)
{
	if (!*str)
		return isLeaf[ind];

	edge& e = getEdge(ind, *str);
	if (e.from == -1)
		return false;
	return traverse(str + 1, e.to);
}

int DP[1500000][53][6];
const int INF = 1e9;
char str[1000000];
int len;
int dp(int nid, int ind, int diff)
{
	if (ind >= len)
	{
		if (isLeaf[nid])
			return 0;
		return INF;
	}
	int& res = DP[nid][ind][diff];
	if (res != -1)
		return res;
	res = INF;
	int ndiff = diff + 1 > 5 ? 5 : diff + 1;
	if (isLeaf[nid])
		res = min(res, dp(0, ind, ndiff));
	edge e = getEdge(nid, str[ind]);
	if (e.from != -1)
		res = min(res, dp(e.to, ind + 1, ndiff));
	if (diff < 5)
		return min(res, INF);
	for (char c = 'a'; c <= 'z'; ++c)
	{
		e = getEdge(nid, c);
		if (e.from != -1)
			res = min(res, dp(e.to, ind + 1, 1) + 1);
	}
	return res;
}

int main()
{
	FILE* fin = fopen("garbled_email_dictionary.txt", "rt");
	memset(edges, -1, sizeof edges);
	while (fscanf(fin, "%s", str) != -1)
		insert(str);
	cerr << cN << endl;
	fclose(fin);
//	freopen("c.in", "rt", stdin);
		freopen("C-small-attempt0 (1).in", "rt", stdin);
		freopen("c.txt1", "wt", stdout);
	int tc;
	scanf("%d", &tc);
	for (int T = 1; T <= tc; ++T)
	{
		scanf("%s", str);
		len = strlen(str);
		memset(DP, -1, sizeof DP);
		printf("Case #%d: %d\n", T, dp(0, 0, 5));
	}
	return 0;
}
