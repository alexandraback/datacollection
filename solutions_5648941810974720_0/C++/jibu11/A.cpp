#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, ct[30], aaa[2000];
char lin[2010];

int main()
{
	int t, k;
	scanf("%d", &t);
	for(k = 0; k < t; k++)
	{
		scanf(" %s", lin);
		memset(ct, 0, sizeof ct);
		int i, l = strlen(lin);
		int ans = 0;
		for(i = 0; i < l; i++)
			ct[lin[i] - 'A']++;
		while(ct['W' - 'A'])
		{
			ct['W' - 'A']--;
			ct['T' - 'A']--;
			ct['O' - 'A']--;
			aaa[ans++] = 2;
		}
		while(ct['Z' - 'A'])
		{
			ct['Z' - 'A']--;
			ct['E' - 'A']--;
			ct['R' - 'A']--;
			ct['O' - 'A']--;
			aaa[ans++] = 0;
		}
		while(ct['X' - 'A'])
		{
			ct['S' - 'A']--;
			ct['I' - 'A']--;
			ct['X' - 'A']--;
			aaa[ans++] = 6;
		}
		while(ct['G' - 'A'])
		{
			ct['E' - 'A']--;
			ct['I' - 'A']--;
			ct['G' - 'A']--;
			ct['H' - 'A']--;
			ct['T' - 'A']--;
			aaa[ans++] = 8;
		}
		while(ct['U' - 'A'])
		{
			ct['F' - 'A']--;
			ct['O' - 'A']--;
			ct['U' - 'A']--;
			ct['R' - 'A']--;
			aaa[ans++] = 4;
		}
		while(ct['F' - 'A'])
		{
			ct['F' - 'A']--;
			ct['I' - 'A']--;
			ct['V' - 'A']--;
			ct['E' - 'A']--;
			aaa[ans++] = 5;
		}
		while(ct['I' - 'A'])
		{
			ct['N' - 'A']--;
			ct['I' - 'A']--;
			ct['N' - 'A']--;
			ct['E' - 'A']--;
			aaa[ans++] = 9;
		}
		while(ct['H' - 'A'])
		{
			ct['T' - 'A']--;
			ct['H' - 'A']--;
			ct['R' - 'A']--;
			ct['E' - 'A']-=2;
			aaa[ans++] = 3;
		}
		while(ct['V' - 'A'])
		{
			ct['S' - 'A']--;
			ct['E' - 'A']-=2;
			ct['V' - 'A']--;
			ct['N' - 'A']--;
			aaa[ans++] = 7;
		}
		while(ct['O' - 'A'])
		{
			ct['O' - 'A']--;
			ct['E' - 'A']--;
			ct['N' - 'A']--;
			aaa[ans++] = 1;
		}
		sort(aaa, aaa + ans);
		printf("Case #%d: ", k + 1);
		for(i = 0; i < ans; i++)
			printf("%d", aaa[i]);
		printf("\n");
	}
	return 0;
}
