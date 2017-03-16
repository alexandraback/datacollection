#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

#include <cstdarg>

using namespace std;

#define DBG2 1

#define clr(a) memset(a, 0, sizeof(a))
#define fill(a, b) memset(a, b, sizeof(a))

void dbg(char * fmt, ...)
{
#ifdef DBG1
#if	DBG2
	FILE * file = stderr;

	va_list args;
	va_start(args, fmt);
	vfprintf(file, fmt, args);
	va_end(args);

	fflush(file);
#endif
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;

const char s[1000] = "y qee ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
const char t[1000] = "a zoo our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
char ss[200];

int main()
{
#ifdef DBG1
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	freopen(".err", "w", stderr);
#endif

	vector <char> mapping(26, '\0');
	vector <bool> usedA(26, false);
	vector <bool> usedB(26, false);
	int cnt = 0;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == ' ')
			continue;
		int num = s[i] - 'a';
		if (mapping[num] != '\0' && mapping[num] != t[i])
		{
			printf("%c %c %c\n", s[i], mapping[num], t[i]);
			fflush(stdout);
			throw 42;
		}
		else
		{
			if (mapping[num] == '\0')
				++cnt;
			usedA[num] = usedB[t[i] - 'a'] = true;
			mapping[num] = t[i];
		}
	}
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
			if (!usedA[i] && !usedB[j])
				mapping[i] = j + 'a';

	int tt;
	scanf("%d\n", &tt);
	dbg("tt = %d\n", tt);
	for (int ii = 0; ii < tt; ++ii)
	{
		gets(ss);
		for (int i = 0; ss[i]; ++i)
		{
			dbg("%c", ss[i]);
			if (ss[i] != ' ')
				ss[i] = mapping[ss[i] - 'a'];
		}
		printf("Case #%d: %s\n", ii + 1, ss);
	}

	return 0;
}
