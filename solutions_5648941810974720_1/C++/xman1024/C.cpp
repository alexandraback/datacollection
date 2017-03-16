#include <bits/stdc++.h>
using namespace std;



char S[3000];
int L[300];
int N[25];
int Ord[] = {0, 6, 7, 5, 4, 3, 2, 1, 8, 9};
char Ch[] = "ZOWRFVXSGI";
char Name[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
void solver()
{
	scanf("%s", S);
	for(int i = 0; i < 300; ++i)
		L[i] = 0;
	for(int i = 0; i < 20; ++i)
		N[i] = 0;
	for(int i = 0; S[i] != '\0'; ++i)
	{
		++L[S[i]];
	}
	for(int i = 0; i < 10; ++i)
	{
		int c = Ord[i];
		int nc = L[Ch[c]];
		for(int j = 0; Name[i][j] != '\0'; ++j)
			L[Name[c][j]] -= nc;
		N[c] = nc;
	}
	for(int i = 0; i < 10; ++i)
		while(N[i] > 0)
		{
			printf("%d", i);
			--N[i];
		}
	
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
	{
		printf("Case #%d: ", i);
		solver();
		puts("");
	}
	
	
	return 0;
}
