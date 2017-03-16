#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()

string s;
int tests;
LL MOD = 1000000007;
vector<string> str;
int n , cycle;

int whole[30], vis[30];
vector<pair<int, int> > where[30];
vector<int> graph[30];

void go(int v) {
	vis[v] = 1;
	for (int j = 0; j < graph[v].size(); j++) {
		if(!vis[graph[v][j]]) go(graph[v][j]);
		else cycle = 1;
	}
	return;
}

int main() {
	scanf("%d",&tests);
	for (int test = 1; test <= tests; test++) {	
		printf("Case #%d: ", test);
		str.clear();
		cin >> n;
		for (int i = 0; i < 30; i++) {
			whole[i] = vis[i] = cycle = 0;
			where[i].clear();
			cycle = false;
			graph[i].clear();
		}
		for (int i = 0; i < n; i++) {
			cin >> s;
			str.push_back(s);
		}
		
		bool zero = false;
		for (int i = 0; i < n; i++) {
			bool diff = false;
			for (int j = 1; j < str[i].size(); j++) {
				if (str[i][j] != str[i][j-1]) {
					if (diff == false) where[str[i][j - 1] - 'a'].push_back(make_pair(0, i));
					
					bool moreDiff = false;
					for (int k = j + 1; k < str[i].size(); k++) {
						if (str[i][k] != str[i][k - 1]) {
							moreDiff = true;
						}
					}
					if (!moreDiff) where[str[i][j] - 'a'].push_back(make_pair(2, i));
					else where[str[i][j] - 'a'].push_back(make_pair(1, i));
					
					diff = true;
				}
			}
			if (!diff) whole[str[i][0] - 'a']++;
		}
		
		int plusComponents = 0;
		for (int i = 0; i < 30; i++) {
			int type[3]; type[0] = type[1] = type[2] = 0;
			for (int j = 0; j < where[i].size();j++) {
				type[where[i][j].first]++;
				//printf("%c %d\n",i + 'a', where[i][j].first);
			}			
			if (type[0] > 1 || type[2] > 1 || type[1] > 1 || (type[1] == 1 && (type[0] + type[2] + whole[i] > 0))) zero = true;
			if (whole[i] && (type[0] + type[2] == 0)) plusComponents++;
		}
		
		if (zero) {
			printf("0\n");
			continue;
		}
		
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < where[i].size(); j++) {
				if (where[i][j].first == 0) {
					int lastIndex = str[where[i][j].second].size() - 1;
					graph[i].push_back(str[where[i][j].second][lastIndex] - 'a');
				}
			}
		}

		int components = plusComponents;
		for (int i = 0; i < 30; i++) if (!vis[i] && graph[i].size()) {
			go(i);
			components++;
		}
		
		LL ret = 1;
		if (cycle) {
			printf("0\n");
			continue;
		}
		
		for (int i = 1; i <= components; i++) {
			ret *= (LL)i;
			ret %= MOD;
		}
		for (int i = 0; i < 30; i++) {
			for (int j = 1; j <= whole[i]; j++) {
				ret *= (LL)j;
				ret %= MOD;
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}
			

			
		
		


