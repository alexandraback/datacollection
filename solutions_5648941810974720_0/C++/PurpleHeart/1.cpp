#include <cstdio>
#include <cstring>

int cnt[505], T[10];
char S[2005];
int cases;

int main(){
	scanf("%d", &cases);
	for(int xx = 1; xx <= cases; ++xx){
		scanf("%s", S);
		int len = strlen(S);
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < len; ++i)
			cnt[S[i]]++;
		// unique
		T[0] = cnt['Z'];
		T[2] = cnt['W'];
		T[4] = cnt['U'];
		T[6] = cnt['X'];
		T[8] = cnt['G'];
		T[1] = cnt['O'] - T[0] - T[2] - T[4];
		T[3] = cnt['R'] - T[0] - T[4];
		T[5] = cnt['F'] - T[4];
		T[7] = cnt['V'] - T[5];
		T[9] = cnt['I'] - T[5] - T[6] - T[8];
		printf("Case #%d: ", xx);
		for(int i = 0; i <= 9; ++i)
			for(int j = 0; j < T[i]; ++j)
				printf("%d", i);
		puts("");
	}
}
