#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int N = 10;

int n;
char s[100];

int d[N][1 << N];
bool vis[N][1 << N];

void decode(int len, int now, int v[]){
	for(int i = 0;i < len; i++){
		v[i] = ((1 << i) & now) != 0;
	}
}

int encode(int len, int v[]){
	int ret = 0;
	for(int i = 0; i < len; i++){
		ret |= ((1 << i) * v[i]);
	}
	return ret;
}

void work(int len, int dist[], bool vis[]){
	static int v[N], tmp[N];
	deque<int> que;
	vis[(1 << len) - 1] = true;
	dist[(1 << len) - 1] = 0;
	que.push_back((1 << len) - 1);
	while(!que.empty()){
		int now = que.front(); que.pop_front();
		decode(len, now, v);
		for(int i = 1; i <= len; i++){
			for(int j = 0; j < i; j++) tmp[j] = 1 ^ v[i - 1 - j];
			for(int j = i; j < len; j++) tmp[j] = v[j];
			int val = encode(len, tmp);
			if (!vis[val]){
				vis[val] = true;
				dist[val] = dist[now] + 1;
				que.push_back(val);
			}
		}
	}
}

int main(){
	for(int i = 0; i < N; i++) work(i + 1, d[i], vis[i]);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++){
		printf("Case #%d: ", cas);
		scanf("%s", s);
		n = strlen(s);
		int sta = 0;
		for(int i = 0; i < n; i++){
			sta |= ((1 << i) * (s[i] == '+'));
		}
		printf("%d\n", d[n - 1][sta]);
	}
}
