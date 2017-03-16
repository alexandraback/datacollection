#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main ()
{
	static char a[256];
	static char b[256];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	char data[128] = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	char ans[128]  = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	int N = strlen(data);
	int i;
	for (i = 0; i < N; i++)
	{
		if (data[i] != ' ')
		{
			a[(int)(data[i])] = ans[i];
			b[(int)(ans[i])] = 1;
		}
	}
	a['q'] = 'z';
	a['z'] = 'q';
	int T, iT;
	scanf("%d\n",&T);
	static char s[205];
	for (iT = 0; iT < T; iT++)
	{
		fgets(s,205,stdin);
		N = strlen(s);
		while (s[N-1] < 32)
		{
			N--;
			s[N] = 0;
		}
		for (i = 0; i < N; i++)
		{
			if ((s[i] >= 'a') && (s[i] <= 'z')) s[i] = a[(int)(s[i])];
		}
		printf("Case #%d: %s\n",iT+1,s);
	}
	return 0;
}
