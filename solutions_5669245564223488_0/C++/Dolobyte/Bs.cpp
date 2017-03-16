#include<cstdio>
#include<cstring>

int ans;
char str[200][200];
int pla[200];
int T, N;
char whole[100000];

void dfs(int now){
	if (now > N){
		/*
		for(int i=1; i<=N; i++)
			printf("%d ", pla[i]);
		printf("\n");
		ans++;*/
int tp=0;
for(int i=1; i<=N; i++){
	int l = strlen(str[pla[i]]);
	for(int j=0; j<l; j++)
		whole[tp++] = str[pla[i]][j];
}
whole[tp] = 0;
//printf("%s\n", whole);
bool mark = true, flag[26];
memset(flag, true, sizeof(flag));
flag[whole[0]-'a'] = false;
for(int i=0; i<tp-1; i++){
	if (whole[i] != whole[i+1]){
		if (flag[whole[i+1]-'a'])
			flag[whole[i+1]-'a'] = false;
		else {
			mark=false;
		//	printf("???%d\n", i);
		}
	}
}
if (mark) ans++;
		return;
	}
	for(int i=1; i<=N; i++)
		if (pla[i] == 0){
			pla[i] = now;
			dfs(now+1);// return;
			pla[i] = 0;
		}
}


int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for(int O=1; O<=T; O++){
		scanf("%d", &N);
		for(int i=1; i<=N; i++)
			scanf("%s", str[i]);
		ans = 0;
		memset(pla, 0, sizeof(pla));
		dfs(1);
		printf("Case #%d: %d\n", O, ans);
	}
	fclose(stdout);
	return 0;
}
