//Одобрено Сумским обласным раввинатом.
//Кошерно, да. А поцчему вы сп'гашиваете?

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <time.h>
using namespace std;

#define all(c) c.begin(),c.end()
const int INF = (1 << 31);
//const int MAXN = 20000, MAXM = 200000;

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}

//int to_s(string s){
//	int res = 0, p = 1;
//	for(int i = s.size() - 1; i >= 0; i--){
//		res += (s[i] - '0') * p;
//		p *= 10;
//	}
//	return res;
//}
//aaaweewfgr
vector<int> pr(string s){
	vector<int> res(s.size(), 0);
	int i, j;
	for(j = 0, i = 1; i < s.size(); i++){
		while(j != 0 && s[i] != s[j]) j = res[j - 1];
		if(s[i] == s[j]) j++;
		res[i] = j;
	}
	return res;
}

vector<vector<int> > g;
set<pair<int, int> > pt;
vector<char> used;
int cnt;

void dfs(int v){
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(used[to] == 0) dfs(to);
		if(used[to] == 1) {
			cnt++;
			used[to] = 2;
		}
	}
	used[v] = 2;	
}

bool isnumb(char c){
	if(c - '0' >= 0 && c - '0' < 10) return true;
	else return false;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("gg.out", "w", stdout);
	/*freopen("theuler.in", "r", stdin);
	freopen("theuler.out", "w", stdout);*/
	int n, m, i, j, a, b, c, d, q;
	scanf("%d%d", &n, &m);
	int sum[1001][1001];
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			scanf("%d", &a);
			sum[i][j] = sum[i][j - 1] + a;
		}
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int z = 0;
		for(i = a; i <= c; i++){
			z += (sum[i][d] - sum[i][b - 1]);
		}
		printf("%d\n", z);
	}
	return 0;
}