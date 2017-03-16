//Andrew Yang
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int k, l, s;
string keys, word;
ll cnt, total;
string temp;
int maxBananas;
void dfs(int e)
{
	if (e == s)
	{
		int ocurrences = 0;
		FOR(i, 0, s - l + 1)
		{
			if (temp.substr(i, l) == word)
			{
				ocurrences++;
				cnt++;
			}
		}
		maxBananas = max(maxBananas, ocurrences);
		total++;
		return;
	}
	FOR(i, 0, k)
	{
		temp[e] = keys[i];
		dfs(e + 1);
	}
}
int main()
{
	freopen("monkey.in", "r", stdin);
	freopen("monkey.out", "w", stdout);
	int sets;
	scanf("%d", &sets);
	FOR(set, 1, sets + 1)
	{
		scanf("%d%d%d", &k, &l, &s);
		cin >> keys >> word;
		maxBananas = 0;
		temp = "";
		FOR(i, 0, s)
		{
			temp += " ";
		}
		cnt = 0;
		total = 0;
		dfs(0);
		printf("Case #%d: %.8f\n", set, (double)maxBananas - (double)cnt / total);
	}
}