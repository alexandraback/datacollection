#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <iterator>

#define MOD 1000000007
#define INF 1000000000000000000
#define PI acos(-1)

using namespace std;

long long int fact[111];
int adj[26][26],cnt[26];
int visited[26];
int middle[26];

long long int dfs (int i) {
	int j;
	long long int res;
	visited[i] = 1;
	res = fact[cnt[i]];
	for (j = 0; j < 27; j++) {
		if (adj[i][j] == 1 && visited[j] == 0) {
			res = (res * dfs(j)) % MOD;
		}
	}
	return res;
}

int main()
{
//	freopen("input.in","r",stdin);
//	freopen("output.in","w",stdout);
	int t,it;
	scanf("%d",&t);
	fact[0] = 1;
	for (it = 1; it <= 110; it++) {
		fact[it] = (fact[it - 1] * it) % MOD;
	}
	for (it = 1; it <= t; it++) {
		long long int ans,temp;
		int n,i,j,flag,st,ch,comp,c,g;
		scanf("%d",&n);
		memset(adj,0,sizeof(adj));
		memset(cnt,0,sizeof(cnt));
		flag = 0;
		memset(middle,0,sizeof(middle));
		for (i = 0; i < n; i++) {
			string s;
			cin >> s;
			st = s[0] - 'a';
			comp = 0;
			for (j = 1; j < s.size(); j++) {
				ch = s[j] - 'a';
				if (ch != st) {
					comp = 1;
					adj[st][ch]++;
					middle[ch]++;
					if (adj[st][ch] > 1) {
						flag = 1;
					}
					st = ch;
				}
			}
			if (comp == 0) {
				cnt[st]++;
			}
		}
/*		for (i = 0; i < 26; i++) {
			c = 0;
			for (j = 0; j < 26; j++) {
				if (adj[i][j] != 0) {
					c++;
				}
			}
			g = 0;
			if (c != 0 && middle[i] > 1) {
				g = 1;
			}
			if (cnt[i] != 0 && g != 0) {
				flag = 1;
			}
		}*/
		if (flag == 0) {
			ans = 1;
			c = 0;
			memset(visited,0,sizeof(visited));
			for (i = 0; i < 26; i++) {
				if (visited[i] != 1 && middle[i] != 1) {
					temp = 0;
					if (cnt[i] != 0) {
						temp = 1;
					}
					for (j = 0; j < 26; j++) {
						if (adj[i][j] != 0) {
							temp = 1;
						}
					}
					if (temp == 1) {
						temp = dfs(i);
						ans = (ans * temp) % MOD;
						c++;
					}
				}
			}
			ans = (ans * fact[c]) % MOD;
		} else {
			ans = 0;
		}
		printf("Case #%d: %lld\n",it,ans);
	}
	return 0;
}
