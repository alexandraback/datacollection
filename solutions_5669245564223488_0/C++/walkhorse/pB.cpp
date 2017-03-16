#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N_MAX 110
using namespace std;

char str[N_MAX][N_MAX];
bool used[N_MAX];
int len[N_MAX], ans, N;
char all[20 * N_MAX];

bool jud(){
	int L = strlen(all);
	bool apr[30];
	memset(apr, false, sizeof(apr));
	for(int i = 0; i < L; i++){
		if(apr[all[i] - 'a'] && all[i - 1] != all[i]) return false;
		apr[all[i] - 'a'] = true;
	}
	return true;
}

void rec(int lev, int loc){
	if(lev == N){
		if(jud()) ans++;
		return;
	}
	for(int i = 0; i < N; i++){
		if(used[i]) continue;
		used[i] = true;
		strcpy(&all[loc], str[i]);
		loc += len[i];
		all[loc] = '\0';
		rec(lev + 1, loc);
		loc -= len[i];
		all[loc] = '\0';
		used[i] = false;
	}
	return;
}

int main(){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cnt = 1; cnt <= T; cnt++){
		printf("Case #%d: ", cnt);
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%s", &str[i]);
			len[i] = strlen(str[i]);
		}
		ans = 0;
		memset(used, false, sizeof(used));
		rec(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
