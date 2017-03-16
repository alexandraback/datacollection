#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<functional>
#include<algorithm>

using namespace std;

#define _INFILE		"A-small-attempt1.in"
#define _OUTFILE	"A-small1.out"

typedef long long ll;

char m[27];

void get_mapping()
{
	const char *s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	const char *s2 = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	int len = strlen(s1);
	for (int i=0; i<len; i++)
	{
		char c1 = s1[i];
		char c2 = s2[i];
		if (c1 >= 'a' && c1 <= 'z')
			m[c1 - 'a'] = c2;
	}
}


int main(void)
{
	int T;
	freopen(_INFILE, "r", stdin);
	freopen(_OUTFILE, "w", stdout);

	m['q'-'a'] = 'z';
	m['z'-'a'] = 'q';
	get_mapping();
	scanf("%d",&T);
	char buf[200];
	gets(buf);
	for(int i=0; i<T; i++)
	{
		gets(buf);
		int len = strlen(buf);
		for(int j=0; j<len; j++)
		{
			char c1 = buf[j];
			if (c1 >= 'a' && c1 <= 'z')
				buf[j] = m[c1 - 'a'];
		}

		printf("Case #%d: %s\n", i+1, buf);
	}
	return 0;
}

