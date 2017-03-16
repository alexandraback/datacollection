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

//#define _INFILE		"A.in"
//#define _OUTFILE	"A.out"

#define _INFILE		"A-small-attempt1.in"
#define _OUTFILE	"A-small.out"

//#define _INFILE		"A-large.in"
//#define _OUTFILE	"A-large.out"

char str[1048576];
int n, len;
int last_begin;
char vowel[5] = {'a', 'i', 'e', 'o', 'u'};

inline bool is_vowel(char c)
{
	for(int i=0; i<5;i++)
		if (vowel[i] == c) return true;
	return false;
}

inline long long cal(int b, int e)
{
	int l = e - b;
	if (l < n) return 0;
	long long c1 = b + 1 - (last_begin + 1);
	long long c2 = len - e + 1;
	last_begin = b + (l - n);
	long long ret = c1 * c2;

	return ret;
}


long long solve()
{
	long long ret = 0;
	scanf("%s%d", str, &n);
	len = strlen(str);

	int begin = -1;
	int end = 0;
	last_begin = -1;

	for(int i=0; i<len; i++)
	{
		char c = str[i];
		if (is_vowel(c))
		{
			if (begin != -1)
			{
				begin = -1;
			}
		}
		else
		{
			if (begin == -1)
			{
				begin = i;
			}
			end = i + 1;
			if (end - begin == n)
			{
				ret += cal(begin, end);				
				begin++;
			}
		}
	}

	return ret;
}

int main(void)
{
	int T;
	freopen(_INFILE, "r", stdin);
	freopen(_OUTFILE, "w", stdout);

	scanf("%d",&T);

	for(int i=0; i<T; i++)
	{
		printf("Case #%d: %lld\n", i+1, solve());
		
	}
	return 0;
}

