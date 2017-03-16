/*
CODE TO CHECK THE MAX LENGTH AND IF THE DICTIONARY IS SORTED

int N = 521196;
int max = 0;
string s1, s2;
s1 = "";
int i;
for (i = 0; i < N; i++)
{
	cin >> s2;
	if (s2 < s1) cout << "ACHTUNG!" << endl;
	if (s2.length() > max) max = s2.length();
	s1 = s2;
}
printf("max length = %d\n",max);

*/

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define MAXW 521200
#define MAXWLEN 12 //It's actually 10
#define MAXLEN 4005
#define MYINF 1000000000

using namespace std;

static int a[MAXLEN][5];
static char s[MAXLEN];
int len;
int wc = 521196;
static char w[MAXW][MAXWLEN];

void Update (int pos, int restr, int l, int r, int pos_in_word, int what)
{
	int L, R, C;
	//Words that have ended
	L = l; R = r+1;
	while (R > L)
	{
		C = (L+R)/2;
		if (w[C][pos_in_word] == 0) L = C+1;
		else R = C;
	}
	if (L > l)
	{
		if (what < a[pos][restr]) a[pos][restr] = what;
		l = L;
	}
	if (L > R) return;
	if (pos == len) return;
	if (restr)
	{
		int A1, A2;
		L = l; R = r+1;
		while (R > L)
		{
			C = (L+R)/2;
			if (w[C][pos_in_word] >= s[pos]) R = C;
			else L = C+1;
		}
		A1 = R;
		L = l; R = r+1;
		while (R > L)
		{
			C = (L+R)/2;
			if (w[C][pos_in_word] > s[pos]) R = C;
			else L = C+1;
		}
		A2 = R;
		A2--;
		if (A2 >= A1) Update(pos+1, restr-1, A1, A2, pos_in_word+1, what);
	}
	else
	{
		int A1, A2;
		L = l; R = r+1;
		while (R > L)
		{
			C = (L+R)/2;
			if (w[C][pos_in_word] >= s[pos]) R = C;
			else L = C+1;
		}
		A1 = R;
		L = l; R = r+1;
		while (R > L)
		{
			C = (L+R)/2;
			if (w[C][pos_in_word] > s[pos]) R = C;
			else L = C+1;
		}
		A2 = R;
		A2--;
		if (A2 >= A1) Update(pos+1, 0, A1, A2, pos_in_word+1, what);		

		int prev = l;
		int next;
		char c;
		for (c = 'a'; c <= 'z'; c++)
		{
			L = prev+1; R = r+1;
			while (R > L)
			{
				C = (L+R)/2;
				if (w[C][pos_in_word] > c) R = C;
				else L = C+1;
			}
			next = R;
			//if ((c == 'z') && (next != r+1)) printf("ACHTUNG\n");
			if (next > prev) Update(pos+1, 4, prev, next-1, pos_in_word+1, what+1);
			prev = next;
		}
	}
}

int main ()
{
	FILE *fi;
	fi = fopen("garbled_email_dictionary.txt","r");
	int i, j;
	memset(w,0,sizeof(w));
	for (i = 0; i < wc; i++) fscanf(fi,"%s\n",w[i]);
	fclose(fi);
	int T, iT;
	scanf("%d",&T);
	for (iT = 0; iT < T; iT++)
	{
		scanf("%s\n",s);
		len = strlen(s);
		for (i = 0; i <= len; i++)
		{
			for (j = 0; j < 5; j++)
			{
				a[i][j] = MYINF;
			}
		}
		a[0][0] = 0;
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if (a[i][j] != MYINF)
				{
					//printf("a[%d][%d] = %d\n",i,j,a[i][j]);
					Update(i, j, 0, wc-1, 0, a[i][j]);
				}
			}
		}
		int res = MYINF;
		for (j = 0; j < 5; j++)
		{
			if (a[len][j] < res) res = a[len][j];
		}
		printf("Case #%d: %d\n",iT+1,res);
	}
	return 0;
}
