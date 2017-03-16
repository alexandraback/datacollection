#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int a[9999];
int b[9999];
int bl;
char x[9999];
int n;
int main()
{
//	freopen("A-small-attempt0.in", "rt",stdin);
//	freopen("A-small-attempt0.out", "wt",stdout);
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.out", "wt", stdout);

	int t;
	int tv;
	tv = 1;
	scanf("%d", &t);
	while (t--)
	{
		int i, j, k;
		scanf("%s", x);
		for (n = 0; x[n]; n++);
		for (i = 0; i < 256; i++)a[i] = 0;
		bl = 0;

		for (i = 0; i < n; i++)
		{
			a[x[i]]++;
		}
		//zero
		while (a['Z']>0)
		{
			a['Z']--;
			a['E']--;
			a['R']--;
			a['O']--;
			b[bl++] = 0;
		}
		// 6
		while (a['X'] > 0)
		{
			a['S']--;
			a['I']--;
			a['X']--;
			b[bl++] = 6;
		}
		// 8
		while (a['G'] > 0)
		{
			a['E']--;
			a['I']--;
			a['G']--;
			a['H']--;
			a['T']--;
			b[bl++] = 8;
		}
		//7
		while (a['S'] > 0)
		{
			a['S']--;
			a['E']--;
			a['V']--;
			a['E']--;
			a['N']--;
			b[bl++] = 7;
		}
		//5
		while (a['V'] > 0)
		{
			a['F']--;
			a['I']--;
			a['V']--;
			a['E']--;
			b[bl++] = 5;
		}
		//4
		while (a['F'] > 0)
		{
			a['F']--;
			a['O']--;
			a['U']--;
			a['R']--;
			b[bl++] = 4;
		}
		//3
		while (a['R'] > 0)
		{
			a['T']--;
			a['H']--;
			a['R']--;
			a['E']--;
			a['E']--;
			b[bl++] = 3;
		}
		//2
		while (a['T'] > 0)
		{
			a['T']--;
			a['W']--;
			a['O']--;
			b[bl++] = 2;
		}
		//1
		while (a['O'] > 0)
		{
			a['O']--;
			a['N']--;
			a['E']--;
			b[bl++] = 1;
		}
		//9
		while (a['N'] > 0)
		{
			a['N']--;
			a['I']--;
			a['N']--;
			a['E']--;
			b[bl++] = 9;
		}
		sort(b, b + bl);
		printf("Case #%d: ", tv);
		for (i = 0; i < bl; i++)
			printf("%d", b[i]);
		printf("\n");
		tv++;
	}
}