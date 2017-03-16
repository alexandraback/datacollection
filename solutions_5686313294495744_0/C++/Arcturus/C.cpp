#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#define M1 1000000007
#define M2 1000000009

using namespace std;

map<long long, int> m1, m2;
set<long long> s1, s2;
char str1[25], str2[25];

long long hashi(char * str){
	int len = strlen(str);
	
	long long v1 = 0;
	for(int i=0; i<len; i++){
		v1 *= 31;
		v1 += str[i]-'A';
		v1 %= M1;
	}
	
	long long v2 = 0;
	for(int i=0; i<len; i++){
		v2 *= 41;
		v2 += str[i]-'A';
		v2 %= M2;
	}
	
	return v1 * M2 + v2;
}

#include <algorithm>
#include <string.h>

using namespace std;

const int MAXN1 = 1010;
const int MAXN2 = 1010;
const int MAXM = 1000100;

int n1, n2, edges, last[MAXN1], prev[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int _n1, int _n2) {
  n1 = _n1;
  n2 = _n2;
  edges = 0;
  memset(last, -1, sizeof(last));
}

void addEdge(int u, int v) {
  head[edges] = v;
  prev[edges] = last[u];
  last[u] = edges++;
}

void bfs() {
  memset(dist, -1, sizeof(dist));
  int sizeQ = 0;
  for (int u = 0; u < n1; ++u) {
    if (!used[u]) {
      Q[sizeQ++] = u;
      dist[u] = 0;
    }
  }
  for (int i = 0; i < sizeQ; i++) {
    int u1 = Q[i];
    for (int e = last[u1]; e >= 0; e = prev[e]) {
      int u2 = matching[head[e]];
      if (u2 >= 0 && dist[u2] < 0) {
        dist[u2] = dist[u1] + 1;
        Q[sizeQ++] = u2;
      }
    }
  }
}

bool dfs(int u1) {
  vis[u1] = true;
  for (int e = last[u1]; e >= 0; e = prev[e]) {
    int v = head[e];
    int u2 = matching[v];
    if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
      matching[v] = u1;
      used[u1] = true;
      return true;
    }
  }
  return false;
}

int maxMatching() {
  memset(used, false, sizeof(used));
  memset(matching, -1, sizeof(matching));
  for (int res = 0;;) {
    bfs();
    memset(vis, false, sizeof(vis));
    int f = 0;
    for (int u = 0; u < n1; ++u)
      if (!used[u] && dfs(u))
        ++f;
    if (!f)
      return res;
    res += f;
  }
}



int main(){
	int jcase;
	int N;
	
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	
	scanf("%d", &jcase);
	for(int icase=0; icase<jcase; icase++){
		m1.clear();
		m2.clear();
		
		scanf("%d", &N);
		init(N, N);
		
		for(int i=0; i<N; i++){
			scanf("%s %s", str1, str2);
			
			long long h1 = hashi(str1);
			int res = m1[h1];
			if(res == 0){ 
				res = m1.size();
				m1[h1] = res;
			}
			
			h1 = hashi(str2);
			int res2 = m2[h1];
			if(res2 == 0){ 
				res2 = m2.size();
				m2[h1] = res2;
			}
			
			addEdge(res-1, res2-1);
			//printf("add %d %d\n", res-1, res2-1);
		}
		
		int mat = maxMatching();
		//printf("mat = %d\n", mat);
		//for(int i=0; i<n1; i++) printf("%d: %d %d %d\n", i, dist[i], Q[i], last[i]);
		//for(int i=0; i<n2; i++) printf("%d: %d\n", i, matching[i]);
		
		int nleft = m1.size();
		int nright = m2.size();
		int orig = nleft + nright - mat;
		int ans = N - orig;
		printf("Case #%d: %d\n", icase+1, ans);
	}
	
	return 0;
}

