#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int MAXL = 128;

map <char, char> M;
char s[MAXL];

void add(const char *s, const char *c)
{
	for (int i = 0; s[i]; i++)
	{
		if (M.find(s[i]) != M.end())
		{
			if (M[s[i]] != c[i])
				puts("ERROR");
		}
		else
		{
			M[s[i]] = c[i];
		}
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    add("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
    add("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
    add("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
    add("y n f i c w l b k u o m x s e v z p d r j g a t h a q set k oset xa ynfd", "a b c d e f g h i j k l m n o p q r s t u v y w x y z now i know my abcs");

    int t;
    scanf("%d\n", &t);
    for (int test = 1; test <= t; test++)
    {
    	printf("Case #%d: ", test);
    	gets(s);
    	for (int i = 0; s[i]; i++)
    		printf("%c", M.find(s[i]) == M.end()? '#' : M[s[i]]);
    	printf("\n");
    }

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
