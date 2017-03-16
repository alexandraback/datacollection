#include <cstdio>
#include <cstring>

int v[10000];
int s[100];
char str[10000];

void dec(int z, int k)
{
	v[z] -= k;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; ++cases) {
		scanf("%s", str + 1);
		memset(v, 0, sizeof(v));
		memset(s, 0, sizeof(s));
		int n = strlen(str + 1);
		for (int i = 1; i <= n; ++i)
			v[str[i]]++;
		s[0] = v['Z'];
		dec('Z', s[0]);
		dec('E', s[0]);
		dec('R', s[0]);
		dec('O', s[0]);
		s[6] = v['X'];
		dec('S', s[6]);
		dec('I', s[6]);
		dec('X', s[6]);
		s[8] = v['G'];
		dec('E', s[8]);
		dec('G', s[8]);
		dec('H', s[8]);
		dec('I', s[8]);
		dec('T', s[8]);
		s[3] = v['H'];
		dec('T', s[3]);
		dec('H', s[3]);
		dec('R', s[3]);
		dec('E', s[3]);
		dec('E', s[3]);
		s[4] = v['R'];
		dec('F', s[4]);
		dec('O', s[4]);
		dec('U', s[4]);
		dec('R', s[4]);
		s[5] = v['F'];
		dec('F', s[5]);
		dec('I', s[5]);
		dec('V', s[5]);
		dec('E', s[5]);
		s[7] = v['V'];
		dec('S', s[7]);
		dec('E', s[7]);
		dec('V', s[7]);
		dec('E', s[7]);
		dec('N', s[7]);
		s[9] = v['I'];
		dec('N', s[9]);
		dec('I', s[9]);
		dec('N', s[9]);
		dec('E', s[9]);
		s[1] = v['N'];
		dec('O', s[1]);
		dec('N', s[1]);
		dec('E', s[1]);
		s[2] = v['W'];
		dec('T', s[2]);
		dec('W', s[2]);
		dec('O', s[2]);
		for (int i = 'A'; i <= 'Z'; ++i)
			if (v[i] != 0) 
				printf("%c\n", i);
		printf("Case #%d: ", cases);
		for (int i = 0; i <= 9; ++i)
			for (int j = 1; j <= s[i]; ++j)
				printf("%d", i);
		printf("\n");
	}
	return 0;
}

