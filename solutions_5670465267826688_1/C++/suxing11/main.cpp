#include <stdio.h>


char s[1000010];
int t[1000010];


int tab[3][5] = {
	{0, 2, -1, -4, 3},
	{0, 3, 4, -1, -2},
	{0, 4, -3, 2, -1}};
	
int mul(int v, char ch)
{
	if (v < 0) return -mul(-v, ch);
	if (ch == 'i') return tab[0][v];
	if (ch == 'j') return tab[1][v];
	if (ch == 'k') return tab[2][v];
	return 0;
}


int gao(int n)
{
	int last = 1;
	int i;
	
	for (i = 0; i < n; i++)
		t[i] = last = mul(last, s[i]);
	if (t[n-1] != -1) return 0;
	int flag = 0;
	for (i = 0; i < n; i++){
		if (flag == 0 && t[i] == 2) flag++;
		if (flag == 1 && t[i] == 4) flag++;
	}
	return flag == 2;
}


int main()
{
	long long T, cas;
	long long l, x, i, j;
	freopen ("C-large.in", "r", stdin);
	freopen ("myout.txt", "w", stdout);
	scanf ("%I64d%*c", &T);
	for (cas = 1; cas <= T; cas++)
	{
		scanf ("%I64d %I64d%*c", &l, &x);
		scanf ("%s%*c", s);
		if (x >= 8) x = 4 + x%4;
		
		for (i = 1; i < x; i++)
			for (j = 0; j < l; j++)
				s[j+l*i] = s[j];
		s[x*l] = '\0';
		if (gao(x*l))
		printf ("Case #%d: YES\n", cas);
		else
		printf ("Case #%d: NO\n", cas);
		
	}
	return 0;
}
