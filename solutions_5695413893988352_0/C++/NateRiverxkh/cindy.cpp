#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define maxn 1010
int lena;
int lenb;
char a[maxn];
char b[maxn];
char t[maxn];

void get(string &s, int &a, int &b)
{
	a = 0;
	for (int i = 0; i<lena; i++)
	{
		a = a * 10 + (s[i] - '0');
	}

	b = 0;
	for (int i = lena; i<lena + lenb; i++)
	{
		b = b * 10 + (s[i] - '0');
	}
}

int ansa, ansb, ansc;
int abs(int a){ return a>0 ? a : -a; }
string ab, bb;
void check(int a, int b, string &s)
{
	if (abs(a - b)<ansc)
	{
		ansb = b;
		ansa = a;
		ansc = abs(a - b);

		ab = s.substr(0, lena);
		bb = s.substr(lena, lenb);
	}
	else if (abs(a - b) == ansc)
	{
		if (b<ansb)
		{
			ansb = b;
			ansa = a;
			ab = s.substr(0, lena);
			bb = s.substr(lena, lenb);
		}
	}
}

void dfs(int d, string s)
{
	if (d == lena + lenb)
	{
		int aa, bb;
		get(s, aa, bb);
		check(aa, bb, s);
		return;
	}

	if (t[d] == '?')
	{
		string ss;
		for (int i = 0; i<10; i++)
		{
			char str[4];
			sprintf(str, "%d", i);
			ss = s + string(str);
			dfs(d + 1, ss);
		}
	}
	else
	{
		char str[4];
		sprintf(str, "%d", t[d] - '0');
		string ss = s + string(str);
		dfs(d + 1, ss);
	}
}

int main()
{
	int i, j, n, m, ncase, tt = 0;
	//freopen("C-large.in", "r", stdin);
	//freopen("C-large.out", "w", stdout);
	scanf("%d", &ncase);
	while (ncase--)
	{
		string sa, sb;
		scanf("%s", a);
		scanf("%s", b);
		lena = strlen(a);
		lenb = strlen(b);
		for (i = 0; i<lena; i++)
			t[i] = a[i];
		for (i = 0; i<lenb; i++)
			t[i + lena] = b[i];
		t[lena + lenb] = '\0';
		ansb = ansc = ansb = 1000;
		dfs(0, "");

		printf("Case #%d: %s %s\n", ++tt, ab.c_str(), bb.c_str());
	}
}




