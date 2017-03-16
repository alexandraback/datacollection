#include <stdio.h>


char s[10010];
char t[10010];
int tab[5][5] = {
	{},
	{0, 1, 2, 3, 4}, 
	{0, 2, -1, 4, -3}, 
	{0, 3, -4, -1, 2}, 
	{0, 4, 3, -2, -1}};


int ctoi(char ch){
	switch (ch){
		case '1': return 1;
		case 'i': return 2;
		case 'j': return 3;
		case 'k': return 4;
		case 'e': return -1;
		case 'I': return -2;
		case 'J': return -3;
		case 'K': return -4;
	};;;
}


char itoc(int x){
	switch (x){
		case 1: return '1';
		case 2: return 'i';
		case 3: return 'j';
		case 4: return 'k';
		case -1: return 'e';
		case -2: return 'I';
		case -3: return 'J';
		case -4: return 'K';
	};;;
}


char mul(char a, char b)
{
	int aa = ctoi(a), bb = ctoi(b);
	int sign = 1;
	if (aa < 0) sign *= -1, aa = -aa;
	if (bb < 0) sign *= -1, bb = -bb;
	return itoc(tab[aa][bb]*sign);
}


int gao(int n)
{
	char ch = '1';
	int i;
	for (i = 0; i < n; i++)
		ch = t[i] = mul(ch, s[i]);
	int flag = 0;
	for (i = 0; i < n; i++)
	{
		if (flag == 0 && t[i] == 'i') {flag = 1; continue;}
		if (flag == 1 && t[i] == 'k') {flag = 2; continue;}
	}
	if (flag == 2 && t[n-1] == 'e') return 1;
	return 0;
}


int main()
{
	int T, cas;
	int i, j, x, l;
	freopen ("C-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	scanf ("%d%*c", &T);
	for (cas = 1; cas <= T; cas++)
	{
		scanf ("%d %d%*c", &l, &x);
		scanf ("%s%*c", s);
		for (i = 0; i < l; i++)
			for (j = 0; j < x; j++)
				s[i+j*l] = s[i];
		s[x*l] = '\0';
		printf ("Case #%d: %s\n", cas, gao(x*l) ? "YES" : "NO");
	}
	return 0;
}
