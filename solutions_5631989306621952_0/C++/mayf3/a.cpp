#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 2333;

int n;
char s[N];
int v[N];

void solve(int l, int r){
	if (l > r) return;
	int ma = 0, pos = -1;
	for(int i = l; i <= r; i++){
		if (s[i] > ma) ma = s[i], pos = i;
	}
	for(int i = pos; i <= r; i++){
		if (s[i] == ma) v[i] = 0;
		else v[i] = 1;
	}
	solve(l, pos - 1);
}

int main(){
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++){
		scanf("%s", s + 1);
		printf("Case #%d: ", cas);
		n = strlen(s + 1);
		solve(1, n);
		deque<int> que;
		for(int i = 1; i <= n; i++){
			if (v[i] == 0) que.push_front(i);
			else que.push_back(i);
		}
		while(!que.empty()){
			putchar(s[que.front()]);
			que.pop_front();
		}
		puts("");
	}
}
