#include <bits/stdc++.h>
using namespace std;

#define F(c) (c-'A')

int cnt[26];
char buffer[2005];
int ans[26];

char arr[10][10] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

int main()
{
	int t;
	scanf("%d",&t);

	for(int cn=1; cn<=t; cn++)
	{
		for(int i=0; i<26; i++)
		{
			cnt[i] = 0;
			ans[i] = 0;
		}

		scanf("%s",buffer);

		for(int i=0; buffer[i]; i++)
			cnt[buffer[i]-'A']++;

		{
			ans[0] = cnt[F('Z')];
			for(int i=0; arr[0][i]; i++)
				cnt[F(arr[0][i])] -= ans[0];
		}

		{
			ans[2] = cnt[F('W')];
			for(int i=0; arr[2][i]; i++)
				cnt[F(arr[2][i])] -= ans[2];
		}

		{
			ans[4] = cnt[F('U')];
			for(int i=0; arr[4][i]; i++)
				cnt[F(arr[4][i])] -= ans[4];
		}

		{
			ans[5] = cnt[F('F')];
			for(int i=0; arr[5][i]; i++)
				cnt[F(arr[5][i])] -= ans[5];
		}

		{
			ans[6] = cnt[F('X')];
			for(int i=0; arr[6][i]; i++)
				cnt[F(arr[6][i])] -= ans[6];
		}

		{
			ans[1] = cnt[F('O')];
			for(int i=0; arr[1][i]; i++)
				cnt[F(arr[1][i])] -= ans[1];
		}

		{
			ans[3] = cnt[F('R')];
			for(int i=0; arr[3][i]; i++)
				cnt[F(arr[3][i])] -= ans[3];
		}

		{
			ans[8] = cnt[F('G')];
			for(int i=0; arr[8][i]; i++)
				cnt[F(arr[8][i])] -= ans[8];
		}

		{
			ans[7] = cnt[F('V')];
			for(int i=0; arr[7][i]; i++)
				cnt[F(arr[7][i])] -= ans[7];
		}

		ans[9] = cnt[F('E')];

		printf("Case #%d: ",cn);
		for(int i=0; i<10; i++)
			for(int j=0; j<ans[i]; j++)
				printf("%d",i);
		printf("\n");
	}
}