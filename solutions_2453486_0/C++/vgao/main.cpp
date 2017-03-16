#include <cstdio>
#include <cstdlib>

char m[4][4];

int equal(char a, char b)
{
	if (a=='T' || b=='T')
		return true;
	return a==b;
}

int search(char c)
{
	for(int i=0; i<4; i++) {
		int flg=true;
		for(int j=0; j<4; j++)
			if (!equal(m[i][j], c)) {
				flg=false;
				break;
			}
		if (flg)
			return true;
		flg=true;
		for(int j=0; j<4; j++)
			if (!equal(m[j][i], c)) {
				flg=false;
				break;
			}
		if (flg)
			return true;
	}
	if (equal(m[0][0], c) && equal(m[1][1], c) && equal(m[2][2], c) && equal(m[3][3], c))
		return true;
	if (equal(m[3][0], c) && equal(m[2][1], c) && equal(m[1][2], c) && equal(m[0][3], c))
		return true;
	return false;
}

int main()
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	int n; scanf("%d", &n);
	//printf("%d\n", n);
	for(int index=0; index<n; index++) {
	for(int y=0; y<4; y++) {
		char s[32];	scanf("%s", s);
		for(int x=0; x<4; x++) {
			m[x][y]=s[x];
		}
	}
	int flag[2];
	flag[0]=search('O');
	flag[1]=search('X');
	//printf("%d, %d\n", flag[0], flag[1]);
	if (flag[0])
		if (flag[1]) {
			printf("Case #%d: Draw\n", index+1);
			goto end;
		}
		else {
			printf("Case #%d: O won\n", index+1);
			goto end;
		}
	else
		if (flag[1]) {
			printf("Case #%d: X won\n", index+1);
			goto end;
		}
		else
			for(int i=0; i<4; i++)
				for(int j=0; j<4; j++)
					if (m[j][i]=='.') {
						printf("Case #%d: Game has not completed\n", index+1);
						goto end;
					}
	printf("Case #%d: Draw\n", index+1);
end:
		;
	}
	return 0;
}