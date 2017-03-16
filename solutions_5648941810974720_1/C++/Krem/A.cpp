#include<cstdio>
#include<cstring>

char str[3000];
int count[300];

char chars[][6] = {
	{0,'Z','E','R','O', 0 },
	{8,'G','E','I','H','T'},
	{6,'X','S','I', 0 , 0 },
	{7,'S','E','V','E','N'},
	{5,'V','F','I','E', 0 },
	{4,'U','F','O','R', 0 },
	{9,'I','N','N','E', 0 },
	{3,'R','T','H','E','E'},
	{1,'N','O','E', 0 , 0 },
	{2,'T','W','O', 0 , 0 }
};

int main() {
	int T; scanf("%d", &T);
	for (int _ = 0; _ < T; ++_) {
		memset(count, 0, sizeof(count));
		scanf(" %s", str);
		for (int i = 0; str[i]; ++i) {
			count[str[i]]++;
		}
		int sol[10] = {0,0,0,0,0,0,0,0,0,0};
		for (int i = 0; i < 10; ++i) {
			while(count[chars[i][1]] > 0) {
				sol[chars[i][0]]++;
				for (int j = 1; j < 6; ++j) {
					count[chars[i][j]]--;
				}
			}
		}
		printf("Case #%d: ", _+1);
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < sol[i]; ++j)
				printf("%c", i+'0');
		}
		printf("\n");
	}
	return 0;
}
