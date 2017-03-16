#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;

typedef struct {
	char s[8];
	int city;
} S;
S s[10];
bool comp(S a, S b) {
	return (strcmp(a.s, b.s) < 0);
}

int t, n, m;
vi adj[10];
int dest;
void dfs(int u);

int main() {
	int a, b;
	
	scanf("%d", &t);
	for(int test=1; test<=t; test++) {
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++) {
			scanf("%s", s[i].s);
			s[i].city = i;
			
			adj[i].clear();
		}
		sort(s, s+n, comp);
		
		for(int i=0; i<m; i++) {
			scanf("%d %d", &a, &b);
			a--; b--;
			
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		if(n == 1) {
			printf("Case #%d: %s\n", test, s[0].s);
			continue;
		}
		
		do {
			dest = 1;
			dfs(s[0].city);
			if(dest == n) break;
		} while(next_permutation(s, s+n, comp));
		
		printf("Case #%d: ", test);
		for(int i=0; i<n; i++) printf("%s", s[i].s);
		printf("\n");
	}
}

void dfs(int u) {
	if(dest == n) return;
	
	int size = (int)adj[u].size();
	for(int i=0; i<size; i++) if(adj[u][i] == s[dest].city) {
		dest++;
		dfs(adj[u][i]);
		if(dest == n) return;
		dfs(u);
		if(dest == n) return;
	}
}
